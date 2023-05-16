#include "simple_shell.h"

/**
 * own_env - handles printing of environ variables
 * Return: void
 */

int own_env(void)
{
	int index = 0;

	while (environ[index] != NULL)
	{
		write(STDOUT_FILENO, environ[index], strlen(environ[index]);
		write(STDOUT_FILENO, "\n", 1);
		index++;
	}
	return (0);
}
