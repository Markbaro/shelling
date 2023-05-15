#include "simple_shell.h"

/**
 * shell_execute - forks child process and executes  an new process in it
 * @argums: pointer to an array of strings with arg values
 * Return: Success or failure
*/

int shell_execute(char **argums)
{
	pid_t child_procId;
	int return_value;

	child_procId = fork();
	{
		if (child_procId == 0)
		{
			if (execve(argums[0], argums, NULL) == -1)
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(&return_value);
		}
	}
	return (0);
}
