#include "simple_shell.h"

/**
 * loop - main loop of the shell
 * Return: no return
 */

void loop(void)
{
	int loop_count, line_count;
	char *line_ptr;
	char **args_ptr;
	size_t line_size;

	signal(SIGINT, signals);
	loop_count = 1;
	while (1)
	{
		line_ptr = NULL;
		line_size = 0;
		args_ptr = NULL;

		isatty(STDIN_FILENO) ? write(STDOUT_FILENO, "simple_shell $", 2) : 0;
		getline(&line_ptr, &line_size, stdin) == EOF ? (isatty(STDIN_FILENO) ?
				write(STDOUT_FILENO, "\n", 1) : 0, exit(EXIT_FAILURE)) : 0;
		line_count = shell_getline(line_ptr);
		args_ptr = tokenize(line_ptr, line_count);
		_strcmp(args_ptr[0], "exit") == 0 &&
			(_strlen(args_ptr[0]) == _strlen("exit"))
			? (exit_shell(args_ptr, line_ptr) == -1 ?
					error_message(NULL, args_ptr, loop_count) : 0) :
			(args_ptr != NULL && args_ptr[0] != NULL ? (compiler(args_ptr) == -1 ?
								    error_message(NULL, args_ptr, loop_count) : 0) : 0);
		free_memory(1, line_ptr);
		free_memory(2, args_ptr);
		loop_count++;
	}
}
/**
 * main - entry point
 * @argc: argument counter
 * @argv: argument vector
 * Return: 0
 */
int main(__attribute__((unused)) int argc, __attribute__((unused)) char **argv)
{
	loop();
	return (0);
}
