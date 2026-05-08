# Minishell

**Project Objectives** : Redirections (> < >> <<); understanding stdin, stdout, dup2; pipes; execve func; fork create; waitpid func; signals and signals manipulations , meaning of $?, input tokenizate, shell env variables operations (Export, Unset)

<img src="./img.png" />

**Implementation Notes**
 
 - It Display a prompt when waiting for a new command.
 - It Have a working history.
 - It Search and launch the right executable (based on the PATH variable or using a relative or an absolute path).
 - It Handle ’ (single quote) which should prevent the shell from interpreting the meta-characters in the quoted sequence.
 - It Handle " (double quote) which should prevent the shell from interpreting the meta-characters in the quoted sequence except for $ (dollar sign).
 - Redirections : >, <, >>, <<
 - It Implement pipes (| character). The output of each command in the pipeline is connected to the input of the next command via a pipe.
 - It handle environment variables ($ followed by a sequence of characters) which should expand to their values.
 - It handle $? which should expand to the exit status of the most recently executed foreground pipeline
 - It handle ctrl-C, ctrl-D and ctrl-\ which should behave like in bash.
  - In interactive mode:
     - ctrl-C displays a new prompt on a new line.
     - ctrl-D exits the shell.
     - ctrl-\ does nothing.
 - It implemented the following builtins:
    - echo with option -n
    - cd with only a relative or absolute path
    - pwd with no options
    - export with no options
    - unset with no options
    - env with no options or arguments
    - exit with no options
