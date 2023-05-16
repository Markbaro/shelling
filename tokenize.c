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
/**
 * argums_counter - counts rgums in the input string from getline
 * @input_str:point to the input string
 * Return: length of input_str
*/

int argums_counter(char *input_str)
{
	int iterate, j, flag, i = 0;
	char *delimiter = " :";

	flag  = i;
	iterate = 1;

	if (input_str == NULL)
	return (iterate);

	for (; input_str[i] != '\0'; i++)
	{
		while (delimiter[j] != '\0')
		{
			if (input_str[i] == delimiter[j] && flag == 0)
			{
				iterate++;
				flag = 1;
				break;
			}
		}
		if (delimiter[j] == '\0')
		{
			flag = 0;
		}
		i++;
	}
	return (iterate + 1);
}

/**
 * mod_equals - elimitates chars up including = in the envt str
 * @str: string to edit
 * Return: void
*/
void mod_equals(char **str)
{
	int iter = 0;

	for (; str[0][iter] != '=', iter++)
	{
		str[0][iter] = ':';
	}
	str[0][iter];

}
