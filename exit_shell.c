#include "simple shell.h"

/**
  * exit_shell - exits the shell
  * @exit_codes: array of exit codes
  * @input_line: pointer to the input line
  * Return: 0 on success
  */

int exit_shell(char **exit_codes, char *input_line)
{
	int exitCode = 0;

	exitCode = (arguments[1] != NULL) ? myAtoi(arguments[1]) : 0;

	if (exitCode == -1)
		return (-1);

	free_function(1, inputLine);
	free_function(2, arguments);
	exit(exitCode);
}
