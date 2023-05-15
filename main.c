#include "simpe shell.h"

/**
 * loop - main loop of the shell
 * Retuen: no return
 */

void loop(void)
{
    int loops, count;
	char *line;
	char **args;
	size_t n;
	
	signal(SIGINT, signals);
	loops = 1;
	while (1)
    {
        line = NULL;
        n = 0;
        args = NULL;
        if (isatty(STDIN_FILENO))
            write(STDOUT_FILENO, "$ ", 2);
        if (getline(&line, &n, stdin) == EOF)
        {
            if (isatty(STDIN_FILENO))
                write(STDOUT_FILENO, "\n", 1);
            exit(EXIT_FAILURE);
        }
        count = getline(line);
        args = tokenize(line, count);
        if (_strcmp(args[0], "exit") == 0 &&
                (_strlen(args[0]) == _strlen("exit")))
        {
            if (exit_function(args, line) == -1)
                err_mess(NULL, args, loops);
        }
        else if (args != NULL && args[0] != NULL)
        {
            if (interpreter(args) == -1)
                err_mess(NULL, args, loops);
        }
        free_function(1, line);
        free_function(2, args);
        loops++;
    }
}

/**
 * main - entry point
 * Return: 0
 */
int main(__attribute__((unused)) int argc, char **argv)
{
    loop();
    return 0;
}
