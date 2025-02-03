#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <limits.h>
#include <errno.h>
#include <dirent.h>


void create_file(char *f_name){
	FILE *file = fopen(f_name, "w+");
	if(file == NULL){
		perror("error opening file");
	}
}


bool check_dir(char *cmd){
	struct dirent *entry;
	DIR *dir = opendir("/usr/bin/");
	if(dir == NULL){
		printf("Path error");
	}
	bool check_val = 0;
	while ((entry = readdir(dir)) != NULL){
		if(strcmp(entry->d_name, cmd) == 0){
		check_val = 1;
		break;
		}
	}
	closedir(dir);
	return check_val;
}


void open_application(char *input){
	char *argv[128];
	int argc = 0;
	char *token = strtok(input, " ");
	while( token != NULL){
		argv[argc++] = token;
		token = strtok(NULL, " ");
	}
	argv[argc] = NULL;

	char PATH[PATH_MAX];
	snprintf(PATH, sizeof(PATH), "/usr/bin/%s", argv[0]);
	pid_t pid = fork();

	if(pid < 0){
		perror("fork failed\n");
	}
	else if(pid == 0){

		execv(PATH, argv);

		perror("Execv failed");
	}
	else {
		int status;
		waitpid(pid, &status, 0);
	}
}

int main(int argc, char *argv[]){
	char home_dir[PATH_MAX];
	getcwd(home_dir, sizeof(home_dir));
	printf("\n");
	char current_dir[PATH_MAX], previous_dir[PATH_MAX];


	while(1){
		getcwd(current_dir, sizeof(current_dir));
		char *path = strrchr(current_dir, '/');
		if (path != NULL){
			path++;
			printf("[ %s]$ ", path);
		}
		else {
			printf("[ ~]$ ");
		}
		char input[MAX_INPUT];
		fgets(input, sizeof(input), stdin);
		input[strcspn(input, "\n")] = '\0';

		// type command
		if (strncmp(input, "type", 4) == 0){
			char *cmd = input+5;
			bool check_val = check_dir(cmd);
			
			if(strcmp(cmd, "type") == 0 
				|| strcmp(cmd, "touch") == 0 
				|| strcmp(cmd, "pwd") == 0 
				|| strcmp(cmd, "ls") == 0 
				|| strcmp(cmd, "cd") == 0 
				|| strcmp(cmd, "echo") == 0){
				printf("It is a buildin command\n");
			}
			else if(check_val == 1){
				printf("Command found in /usr/bin\n");
			}
			else{
				printf("command not found\n");
			}
		}

		// Touch create a new file
		else if (strncmp(input, "touch", 5) == 0){
			char *f_name = input + 6;
			create_file(f_name);
		}

		// mkdir
		else if (strncmp(input, "mkdir", 5) == 0){
			const char *dir = input + 6;
			struct stat st = {0};

			if(stat(dir, &st) == -1){
				mkdir(dir, 0777);
			}
			else {
				perror("Directory already exist\n");
			}
		}

		// echo command
		else if (strncmp(input, "echo", 4) == 0){
			char *text = input + 5;

			printf("%s\n", text);
		}


		//ls list files and directories
		else if (strcmp(input, "pwd") == 0){
			if(getcwd(current_dir, sizeof(current_dir)) != NULL)
				printf("%s\n", current_dir);
		}

		else if (strcmp(input, "ls") == 0){
			DIR *dir = opendir(".");
			if(dir == NULL){
				perror("Directory error");
			}

			struct dirent *entry;

			while ((entry = readdir(dir)) != NULL){
				if(entry->d_name[0] != '.'){
					printf("%s\t",entry->d_name);
				}
			}
			printf("\n");

			closedir(dir);
		}


		// cd changing directory
		else if (strncmp(input, "cd", 2) == 0){
			char *path = input+3;


			if (strcmp(path, "..") == 0){
				char *plast_path = strrchr(previous_dir, '/');
				if (plast_path != NULL){
					*plast_path = '\0';
				}
				char *temp = previous_dir;
			
				chdir(temp);
			}
			else if (strcmp(path, "~") == 0){
				char *home = home_dir;
				chdir(home);
			}
			else if (chdir(path) == 0){
				printf("%s\n", path);
			}
			else{
				perror("Path not exist");
			}
		}


		// Exits the shell when typed exit
		else if(strcmp(input, "exit") == 0){
			exit (0);
		}


		else {
			char cp_input[128];
			strcpy(cp_input, input);
			char *app = strtok(cp_input, " ");
			if(check_dir(app)){
				open_application(input);
				printf("%s",input);
				continue;
			}
			printf("%s: command not found\n", input);
		}
		getcwd(previous_dir, sizeof(previous_dir));
	}

	return 0;
}
