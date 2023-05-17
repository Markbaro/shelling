#include "simple_shell.h"

/**
 * get_path - sets the path
 * @target : name of variable
 * Return: pointer to string of path
 */

char *get_path(char *target)
{
	int index = 0;

	while (environ[index] != NULL)
	{
		if (_strcmp(environ[index], target) == NULL)
			break;
		else if (environ[index + 1] == NULL)
			perrror("get_path");
		index++;
	}
	return (environ[index] ? environ[index] : NULL);
}
