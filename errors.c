#include "simple_shell.h"

/**
 * error_message - prints error message if command is invalid
 * @argv : strings containing programmes names and argument
 * @args : strings containing commands
 * @loops : number of times the loop has to be executed
 * Return: void
 */

void error_message(char **argv, char **args, int loops)
{
	char *separator = ": ";
	char *error1 = "invalid command\n";

	if (argv[0] != NULL)
	{
		write(STDERR_FILENO, argv[0], _strlen(argv[0]));
		write(STDERR_FILENO, separator, _strlen(separator));
	}
	if (loops > 0)
	{
		print_number(loops);
		write(STDERR_FILENO, separator, _strlen(separator));
	}
	if (argv[0] != NULL)
	{
		write(STDERR_FILENO, argv[0], strlen(args[0]));
		write(STDERR_FILENO, separator, strlen(separator));
	}
	write(STDERR_FILENO, error1, strlen(error1));
}
/**
 * print_number - prints error number
 * @loops : error number
 * Return: void
 */
void print_number(int loops)
{
	int divisor = 1;
	unsigned int num = loops;
	char digit;

	for (; num / divisor > 9; divisor *= 10)
		;
	for (; divisor >= 1; divisor /= 10)
	{
		digit = ((num / divisor) % 10) + '0';
		write(STDERR_FILENO, &digit, 1);
	}
}
