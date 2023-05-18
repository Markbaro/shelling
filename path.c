#include "simple_shell.h"

/**
 * get_path - sets the path
 * @target : name of variable
 * Return: pointer to string of path
 */

char *get_path(char *target)
{
	int index = 0;

	while (shell_envt[index] != NULL)
	{
		if (_strcmp(shell_envt[index], target) == 0)
			break;
		else if (shell_envt[index + 1] == NULL)
			perror("Error: Find Path");
		index++;
	}
	return (shell_envt[index] ? shell_envt[index] : NULL);
}
