#include "simple_shell.h"

/**
 * compiler - inteprets arguments (argums[0]) and
 * checks the function to send to
 * @argums: argumesnt to be passed to the function
 * Return: 0 on success
 */
int compiler(char **argums)
{
	struct stat fileStats;

	return (((shell_system_search(argums) == 0))
			? 0
			: (arg_search(argums) == -1)
				? -1
				: (stat(argums[0], &fileStats) == -1 || S_ISREG(fileStats.st_mode) == 0)
					? -1
					: (shell_execute(argums) == -1)
						? -1
						: 0);
}
