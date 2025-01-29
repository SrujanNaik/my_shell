#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>
#include <dirent.h>

int main(){
	printf("\n");

	while(1){
		printf("$ ");
		char input[128];
		fgets(input, sizeof(input), stdin);
		input[strcspn(input, "\n")] = '\0';

		//ls list files and directories
		if (strcmp(input, "pwd") == 0){
			char cwd[PATH_MAX];

			if(getcwd(cwd, sizeof(cwd)) != NULL)
				printf("%s\n", cwd);
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
			
			if (chdir(path) == 0){
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
		
		else{
			printf("%s: command not found\n", input);
		}
	}

	return 0;
}
