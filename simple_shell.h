#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>

int shell_execute(char **argums);
void signals(int sig);

#endif /* SIMPLE SHELL_H */
