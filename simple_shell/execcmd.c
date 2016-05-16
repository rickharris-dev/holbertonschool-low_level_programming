#include "hdr.h"

int exec_cmd(char *cmd, char **argv, char **env)
/* Executes the program with the given arguments */
{
        int pid;
        int status;

        if((pid = fork()) == -1) {
                perror("fork");
                return (0);
        }
        if (pid == 0) {
                status = execve(cmd, argv, env);
        } else {
                wait(&status);
                if(WIFEXITED(status)){
                        free(cmd);
                        return WEXITSTATUS(status);
                }
        }
        free(cmd);
        return 0;
}
