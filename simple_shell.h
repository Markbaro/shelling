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
int compiler(char **arglist);
int scan_system(char **argums);
int check_system(char **argums);
int exit_shell(char **arguments, char *input_line);
int getline(char *input_str);
int main(__attribute__((unused)) int argc, char **argv);
void loop(void);
void error_message(char **argv, char **args, int loops);
void free_memory(int count, ...);
void free_double_ptr(char **ptr);
void free_single_ptr(char *ptr);
void signals(int sig);
int own_env(void);
char **tokenize(char *str, int args);
void mod_equals(char **str);
char *get_path(char *target);
int scan_dir(char **input_cmd, char **argums);
int _atoi(char *str);
int _strcmp{char *str1, char *str2);
int _strlen(char *str);
char _strdup(char *str);
char *_strconcat(char *str1, char *str2);
#endif /* SIMPLE SHELL_H */
