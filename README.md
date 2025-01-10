
----

**Basic Command Excution**   

- [ ] ls: Lists files and directories in the current directory.  

   - Lists files with detailed information (permissions, owner, size, etc.).  

- [ ] cd: Changes the current directory.

    - cd ..: Moves to the parent directory.  
    - cd ~: Moves to the home directory.  

- [ ] pwd: Displays the current working directory.  
- [ ] mkdir: Creates a new directory.  
- [ ] touch: Creates an empty file or updates the timestamp of an existing file.  
- [ ] cp: Copies files or directories.  
- [ ] mv: Moves or renames files or directories.  
- [ ] rm: Removes files or directories.  

    - rm -r: Recursively removes directories and their contents.  

- [ ] cat: Displays the contents of a file.  
- [ ] grep: Searches for patterns in files.  
- [ ] echo: Displays text on the console.  

----  

**Built-in Commands**  

- [ ] cd: Change directory.  
- [ ] pwd: Print working directory (show the current directory).  
- [ ] echo: Display text on the screen.  
- [ ] exit: Exit the current shell session.  
- [ ] export: Set or modify environment variables.  
- [ ] source: Read and execute commands from a file in the current shell environment.  
- [ ] history: Display a list of previously executed commands.  
- [ ] alias: Create shortcuts for frequently used commands.  
- [ ] jobs: List background jobs.  
- [ ] fg: Bring a background job to the foreground.  
- [ ] bg: Move a job to the background.  
- [ ] kill: Send signals to processes, including termination signals.  
- [ ] if, else, elif, for, while, until: Control flow constructs for conditional execution and looping.  

**Input Handling**


**Error Handling**


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

