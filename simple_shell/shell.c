#include "hdr.h"

int get_arg_count(char **argv)
/* Returns number of arguments in array */
{
        int i;
        for (i = 0; argv[i] != NULL; i++);
        return i;
}

int main(int ac, char **av, char **env)
/* Launches shell */
{
        int status;

        (void)(ac);
        (void)(av);
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

int process_cmd(int status, char **argv, char **env)
/* Checks built-ins for cmd or checks paths for cmd */
{
        int tmp;
        
        tmp = check_builtins(argv[0], argv, env);
        if (tmp == -1)
                return 1;
        else if (tmp)
                return 0;
        status = check_path(argv[0], argv, env);
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
        }
        status = process_cmd(status, argv, env);
        return return_status(status, argv);
}
