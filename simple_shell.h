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

typedef struct simple_shell
{
    char *id;
    int (*cmd_function)(void);
} system_built;

extern char **shell_envt;

int shell_execute(char **argums);
void signals(int sig);
int arg_search(char **argums);
char **tokenize(char *str, int args);
int argums_counter(char *input_str);
void mod_equals(char **str);
int shell_system_search(char **argums);
int directory_search(char **input_cmd, char **argums);
#endif /* SIMPLE SHELL_H */
