#include "my_header.h"

int get_arg_count(char **argv)
{
        int i;
        for (i = 0; argv[i] != NULL; i++);
        return i;
}

int ret_stat(int status, char **argv) {
        free_array(argv);
        return status;
}

int shell_prompt(int status, char **env)
{
        /* Reads input and initializes processing */
        char *input;
        char **argv;

        write_string("simple_shell> ");
        input = read_line(0);
        if (!input) {
                write_string("simple_shell: Error reading arguments\n");
                return 1;
        }
        argv = string_split(input, ' ');
        free(input);
        if (argv == NULL) {
                write_string("simple_shell: Error processing arguments\n");
                return ret_stat(1, argv);
        } else if (argv[0] == NULL) {
                return ret_stat(0, argv);
        }
        argv = dollar_vars(status, argv, env);
        if (!dollar_vars(status, argv, env)) {
                write_string("simple_shell: Error converting variables\n");
                return ret_stat(1, argv);
        } else if (check_builtins(argv[0], argv, env)) {
                return ret_stat(0, argv);
        }

        status = check_path(argv[0], argv, env);
        return ret_stat(status, argv);
}

int main(__attribute__((unused)) int ac, __attribute__((unused)) char **av, char **env)
{
        /* Launches shell */
        int status;

        status = 0;
        while (1)
                status = shell_prompt(status, env);
        return 0;
}
