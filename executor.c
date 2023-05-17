#include "simple_shell.h"

/**
 * compiler - inteprets arguments (argums[0]) and
 * checks the function to send to
 * @arglist: argumesnt to be passed to the function
 * Return: 0 on success
 */
int compiler(char **arglist)
{
	struct stat filestat;
	int system_result = check_system(arglist);

	switch (system_result)
	{
		case 0:
			return (0);
		case -1:
			scan_system(arglist);
			break;
		default:
			return (-1);
	}
	if (stat(arglist[0], &filestat) == -1)
	{
		return (-1);
	}
	switch (filestat.st_mode & S_IFMT)
	{
		case S_IFREG:
			break;
		default:
			return (-1);
	}
	if (shell_execute(arglist) == -1)
	{
		return (-1);
	}
	return (0);
}
