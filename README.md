
----

**Basic Command Excution**   

- [x] ls: Lists files and directories in the current directory.  

   - Lists files with detailed information (permissions, owner, size, etc.).  

- [x] cd: Changes the current directory.

    - cd ..: Moves to the parent directory.  
    - cd ~: Moves to the home directory.  

- [x] pwd: Displays the current working directory.  
- [x] type: tell the type of command.
    - type: builtin
    - type: excuatbles
- [x] echo: Displays text on the console.  
- [x] mkdir: Creates a new directory.  
- [ ] Run a Program.
- [ ] touch: Creates an empty file or updates the timestamp of an existing file.  
- [ ] cp: Copies files or directories.  
- [ ] mv: Moves or renames files or directories.  
- [ ] rm: Removes files or directories.  

    - rm -r: Recursively removes directories and their contents.  

- [ ] cat: Displays the contents of a file.  

----  

**Built-in Commands**  

- [x] cd (Change Directory):  
  
    - Changes the current working directory of the shell.  
    - Example: cd /home/user  
  
- [x] exit:  
  
    - Exits the shell.  
  
- [x] pwd (Print Working Directory):  
  
    - Displays the current working directory.   
  
----

**Input Handling**

- Handling inputs through fgets(), strtok().  

**Error Handling**
 
 - Handling error like fgets(),fork(), execvp(), wait().  


**looping**  
- [ ] Continuously Prompt the User:  

    - Display the shell prompt (e.g., myshell>) to the user.  
    - Use fgets() to read a line of input from the user.  

- [ ] Check for the exit Command:  

    - If the user enters the exit command, set a flag (e.g., should_run = 0) to indicate that the shell should terminate.  

- [ ] Execute Commands:  

    - If the input is not exit, proceed with the command execution steps:  
        - Parse the input to extract the command and arguments.  
        - Fork a child process using fork().  
        - In the child process, use execvp() to execute the command.  
        - In the parent process, use wait() to wait for the child process to finish.  

- [ ] Handle Errors:  

    - Check for errors during fork(), execvp(), and wait().  
    - Display appropriate error messages to the user.  


----


optional

*Background Processes*

*I/O Redirection*

*Job Control*

*History*

*Tab Completion*

