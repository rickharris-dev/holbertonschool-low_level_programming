#include "hdr.h"

int main(__attribute__((unused)) int ac, __attribute__((unused)) char **av, char **env)
/* Launches shell */
{
        int status;

        status = 0;
        while (1)
                status = shell_prompt(status, env);
        return 0;
}

int return_status(int status, char **argv)
/* Frees memory and then returns status */
{
        free_array(argv);
        return status;
}

int shell_prompt(int status, char **env)
/* Reads input and initializes processing */
{
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
                return return_status(1, argv);
        } else if (argv[0] == NULL) {
                return return_status(0, argv);
        }
        handle_comments(argv);
        if (dollar_vars(status, argv, env)) {
                write_string("simple_shell: Error converting variables\n");
                return return_status(1, argv);
        } else if (check_builtins(argv[0], argv, env)) {
                return return_status(0, argv);
        }

        status = check_path(argv[0], argv, env);
        return return_status(status, argv);
}
