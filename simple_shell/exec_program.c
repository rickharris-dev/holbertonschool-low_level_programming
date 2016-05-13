#include "my_header.h"

int exec_program(char *cmd, char **argv, char **env)
/* Executes the program with the given arguments */
{
        int pid;
        int status;

        if((pid = fork()) == -1) {
                perror("fork");
                return (1);
        }
        if (pid == 0) {
                status = execve(cmd, argv, env);
                if (status != 0) {
                        perror("execve");
                        exit(-1);
                }
        } else {
                wait(&status);
        }
        return 0;
}
