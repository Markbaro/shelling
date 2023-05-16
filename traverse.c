#include "simple_shell.h"

/**
 * shell_system_search - searches functions builtins
 * @argums:  command
 * Return: Always 0 on success and -1 0n failure
*/

int shell_system_search(char **argums)
{
	system_built builtin_func[] = {
		{"env", environ_print},
		{NULL, NULL}
	};

	int i, enquire = 0;

	for (i = 0; builtin_func[i].id != NULL; i++)
	{
		if (_strcmp(builtin_func[i].id, argums[0]) == 0 &&
			_strlen(builtin_func[i].id) == _strlen(argums[0]))
			enquire = builtin_func[i].cmd_function();
	}
	if (builtin_func[i].id == NULL)
		return (-1);
	return (enquire);
}
/**
 * arg_search-passes arguments to traverse and search functions
 * @argums: commands to search for
 * Return: int values- 0 for success and 1 on failure
 */
int arg_search(char **argums)
{
	char **input_cmd = NULL, *temp;
	int iterate;

	temp =  _strdup(find_shell_path"PATH");
	if (temp == NULL)
		return (0);
	iterate = argums_counter(temp);
	if (iterate == -1)
	{
		free_memory(1, temp);
		return (-1);
	}
	mod_equals(&temp);
	input_cmd = tokenize(temp, iterate);
	if (input_cmd == NULL)
	{
		free_memory(1, temp);
		return (-1);
	}
	if (directory_search(input_cmd, argums) == -1)
	{
		free_memory(1, temp);
		return (-1);
	}
	free_memory(1, temp);
	return (0);
}
/**
 * directory_search - traverse through dirs till cmd is found
 *  @input_cmd: pointer to all PATH directories
 *  @argums: command argument to search for in the dir
 *  Return: Always 0 on Success and -1 on failure
 */
int directory_search(char **input_cmd, char **argums)
{
	char *current_directory;
	int i;
	struct stat fileStats;

	current_directory = getcwd(NULL, 0);
	while (input_cmd[i] != NULL)
	{
		if (argums[0][0] == '/')
			break;
		if (_strcmp(argums[0], "./") == 0)
			break;
		chdir(input_cmd[i]);
		if (stat(argums[0], &fileStats) == 0)
		{
			argums[0] = _strconcat(input_cmd[i], argums[0]);
			if (argums[0] == NULL)
			{
				free_memory(1, current_directory);
				free_memory(2, input_cmd);
				return (-1);
			}
			break;
		}
	}
	chdir(current_directory);
	free_memory(1, current_directory);
	if (input_cmd[i] == NULL)
	{
		free_memory(2, input_cmd);
		return (-1);
	}
	free_memory(2, input_cmd);
	return (0);
}
