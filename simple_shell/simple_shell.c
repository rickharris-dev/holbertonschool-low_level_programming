#include "my_header.h"

int get_arg_count(char **argv)
{
        int i;
        for (i = 0; argv[i] != NULL; i++);
        return i;
}

int string_len(char *str){
        int i;
        for (i = 0; str[i] != '\0'; i++);
        return i;
}

void write_string(char *str)
{
        int i;
        for (i = 0; str[i] != '\0'; i++)
                print_char(str[i]);
}

char *trim_left(char *str, int n) {
        return &str[n];
}

char *concat_strings(char *first, char * second, char sep) {
        int i;
        int len_one;
        int len_two;
        int sep_exists;
        char *str;

        len_one = string_len(first);
        len_two = string_len(second);
        sep_exists = 0;
        if (sep)
                sep_exists = 1;

        str = malloc(sizeof(char) * (len_one + len_two + 2));
        for (i = 0; i < len_one; i++) {
                str[i] = first[i];
        }
        if (sep_exists)
                str[i] = sep;
        for (i = 0; i < len_two; i++) {
                str[len_one + sep_exists + i] = second[i];
        }
        str[len_one + sep_exists + i] = '\0';

        return str;
}

int check_path(char *cmd, char **argv, char **env)
{
        int i;
        int j;
        char *path;
        char **paths;
        char *full_path;

        for (i = 0; env[i] != NULL; i++) {
                if (strn_compare(env[i], "PATH=", 5)) {
                        path = trim_left(env[i], 5);
                        paths = string_split(path, ':');
                        for (j = 0; paths[j] != NULL; j++){
                                full_path = concat_strings(paths[j], cmd, '/');
                                if (access(full_path, F_OK) != -1) {
                                        exec_program(full_path, argv, env);
                                        return 0;
                                }
                                free(full_path);
                        }
                }
        }
        return -1;
}

int check_builtins(char *cmd, char **env)
{
        if (compare_strings(cmd, "exit")) {
                exit(0);
        } else if (compare_strings(cmd, "env")) {
                int i;
                for (i = 0; env[i] != NULL; i++) {
                        write_string(env[i]);
                        print_char('\n');
                }
                return 1;
        }
        return 0;
}

int process_input(char *input, char **env)
{
        char **argv;

        argv = string_split(input, ' ');
        if (argv == NULL)
                return -1;
        else if (argv[0] == NULL)
                return 0;
        else if (check_builtins(argv[0], env))
                return 0;
        return check_path(argv[0], argv, env);
}

void shell_prompt(char **env)
{
        /* Reads input and initializes processing */
        char *input;

        write_string("simple_shell> ");
        input = read_line(0);
        process_input(input, env);
}

int main(__attribute__((unused)) int ac, __attribute__((unused)) char **av, char **env)
{
        /* Launches shell */
        while (1)
                shell_prompt(env);
        return 0;
}
