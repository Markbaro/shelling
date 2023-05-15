#include "simple_shell.h"

/**
  * signals - evaluates SIGINT
  * @sig: signal
  * Return: void
  */
void signals(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n$ ", 3);
}
