#include "hdr.h"

int check_file_exists(char *path)
/* Checks if file exists in path */
{
        if (access(path, F_OK) != -1) {
                return 1;
        }
        return 0;
}

int check_path(char *cmd, char **argv, char **env)
/* Checks the paths provided by env for the given command */
{
        char *path;
        char **paths;
        char *prog;

        path = find_path(env);
        if (!path) {
                perror("find_path");
                return 1;
        }

        paths = string_split(path, ':');
        if (!paths) {
                perror("string_split");
                return 1;
        }

        prog = find_program(paths, cmd);
        free_array(paths);
        if (!prog) {
                write_string(cmd);
                write_string(": Command not found\n");
                return 127;
        }

        return exec_cmd(prog, argv, env);
}

char *find_path(char **env)
/* Locates the path line in env */
{
        int i;

        for (i = 0; env[i] != NULL; i++) {
                if (strn_compare(env[i], "PATH=", 5)) {
                        return trim_left(env[i], 5);
                }
        }
        return NULL;
}

char *find_program(char **paths, char *cmd)
/* Locates the program in env paths */
{
        int i;
        char *full_path;

        for (i = 0; paths[i] != NULL; i++){
                full_path = concat_strings(paths[i], cmd, '/');
                if (check_file_exists(full_path))
                        return full_path;
                free(full_path);
        }
        return NULL;
}
