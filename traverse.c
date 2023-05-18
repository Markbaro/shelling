#include "simple_shell.h"

/**
 * check_system - searches functions builtins
 * @argums:  command
 * Return: Always 0 on success and -1 0n failure
*/
int check_system(char **argums)
{
	system_built builtin_func[] = {
		{"env", own_env},
		{NULL, NULL}
	};
	int index, enquire = 0;

	while (builtin_func[index].id != 0)
	{
		enquire = (_strcmp(builtin_func[index].id, argums[0]) == 0 &&
		_strlen(builtin_func[index].id) == _strlen(argums[0])) ?
		builtin_func[index].cmd_function() : enquire;
		index++;
	}
	return ((builtin_func[index].id == 0) ? -1 : enquire);
}
/**
 * scan_system - passes arguments to traverse and search functions
 * @argums: commands to search for
 * Return: int values- 0 for success and 1 on failure
 */
int scan_system(char **argums)
{
	char **input_cmd = NULL, *temp;
	int iterate;

	temp =  _strdup(get_path("PATH"));
	if (!temp)
		return (-1);
	iterate = shell_getline(temp);
	return ((iterate == -1) ? (free_memory(1, temp), -1) : -1);
	mod_equals(&temp);
	input_cmd = tokenize(temp, iterate);
	return ((input_cmd == NULL) ? (free_memory(1, temp), -1) : -1);
	return ((scan_dir(input_cmd, argums) == -1) ?
	(free_memory(1, temp), -1) : -1);
	free_memory(1, temp);
	return (0);
}
/**
 * scan_dir - traverse through dirs till cmd is found
 * @input_cmd: pointer to all PATH directories
 * @argums: command argument to search for in the dir
 * Return: Always 0 on Success and -1 on failure
 */
int scan_dir(char **input_cmd, char **argums)
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
