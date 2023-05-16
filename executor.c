#include "simple_shell.h"

/**
 * compiler -
 * @ags
 * Return: 0 on success
 */
int compiler(char **ags)
{
	struct stat store;

	return ((mySearchBuiltins(ags) == 0))
			? 0
			: (mySearch(ags) == -1)
				? -1
				: (stat(ags[0], &store) == -1 || S_ISREG(store.st_mode) == 0)
					? -1
					: (shell_execute(ags) == -1)
						? -1
						: 0;
}

