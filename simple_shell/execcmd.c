#include "hdr.h"

int exec_cmd(char *cmd, char **argv, struct Stringlist *env)
/* Executes the program with the given arguments */
{
        int pid;
        int status;
        char **array;

        array = list_to_strarr(env);

        if((pid = fork()) == -1) {
                perror("fork");
                return (0);
        }
        if (pid == 0) {
                status = execve(cmd, argv, array);
        } else {
                wait(&status);
                if(WIFEXITED(status)){
                        free(cmd);
                        free(array);
                        return WEXITSTATUS(status);
                }
        }
        free(cmd);
        free(array);
        return 0;
}
