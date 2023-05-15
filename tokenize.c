#include "simple shell.h"

/**
 * tokenize - splits string into characters
 * @str: input string
 * @args: stores input
 * Return:count of input strings
 */
char **tokenize(char *str, int args)
{
	char **tokenList = malloc(sizeof(char *) * size);
	char *token;
	int index;
	char *delim = " :'\n''\t'";

	if (line == NULL || tokenList == NULL)
		return (NULL);
	for (index = 0, token = strtok(line, delim); token != NULL; index++,
			token = strtok(NULL, delim))
	{
		tokenList[index] = strdup(token);
		if (tokenList[index] == NULL)
		{
			free_function(2, tokenList);
			return (NULL);
		}
	}
	tokenList[index] = token;
	return (tokenList);
}
