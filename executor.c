#include <sys/stat.h>

int myInterpreter(char **arguments)
{
	struct stat fileStats;

	return ((mySearchBuiltins(arguments) == 0))
			? 0
			: (mySearch(arguments) == -1)
				? -1
				: (stat(arguments[0], &fileStats) == -1 || S_ISREG(fileStats.st_mode) == 0)
					? -1
					: (myExecution(arguments) == -1)
						? -1
						: 0;
}

