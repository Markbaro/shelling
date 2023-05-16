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
#include <stdarg.h>
#include <sys/stat.h>
#include <stddef.h>

typedef struct simple_shell
{
    char *id;
    int (*cmd_function)(void);
} system_built;

extern char **shell_envt;

int shell_execute(char **argums);
void print_number(loops);
int compiler(char **argums);
int exit_shell(char **arguments, char *input_line);
int getline(char *line);
int main(__attribute__((unused)) int argc, char **argv);
void loop(void);
void error_message(char **argv, char **args, int loops);
void free_mem(int count, ...);
void free_double_ptr(char **ptr);
void free_single_ptr(char *ptr);
void signals(int sig);
int arg_search(char **argums);
int own_env(void);
char **tokenize(char *str, int args);
int argums_counter(char *input_str);
void mod_equals(char **str);
int shell_system_search(char **argums);
int directory_search(char **input_cmd, char **argums);
#endif /* SIMPLE SHELL_H */
