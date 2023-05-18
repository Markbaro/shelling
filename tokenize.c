#include "simple_shell.h"

/**
 * tokenize - splits string into characters
 * @str: input string
 * @argum_size: stores input
 * Return:count of input strings
 */
char **tokenize(char *str, int argum_size)
{
	char **parsed_array, *delim = " :'\n''\t'", *parsed_str;
	int index;

	parsed_array= malloc(sizeof(char *) * argum_size);
	if (str == NULL || parsed_array == NULL)
		return (NULL);
	for (index = 0, parsed_str = strtok(str, delim); parsed_str != NULL; index++,
			parsed_str = strtok(NULL, delim))
	{
		parsed_array[index] = strdup(parsed_str);
		if (parsed_array[index] == NULL)
		{
			free_memory(2, parsed_array);
			return (NULL);
		}
	}
	parsed_array[index] = parsed_str;
	return (parsed_array);
}
/**
 * mod_equals - elimitates chars up including = in the envt str
 * @str: string to edit
 * Return: void
*/
void mod_equals(char **str)
{
	int iter = 0;

	for (; str[0][iter] != '='; iter++)
	{
		str[0][iter] = ':';
	};

}
