#include "simple shell.h"

/**
  * exit_shell - exits the shell
  * @codes: exit codes
  * @line: space to be free as we exit
  * Return: 0
  */

int exit_shell(char **codes, char *line)
{
	int exitCode = 0;

	exitCode = (arguments[1] != NULL) ? myAtoi(arguments[1]) : 0;

	if (exitCode == -1)
		return (-1);

	free_function(1, inputLine);
	free_function(2, arguments);
	exit(exitCode);
}

