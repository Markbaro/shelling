#include "simple shell.h"

/**
 * getline - counts the number of arguments in the string
 * @line: pointer to a string
 * Return: number of characters read
 */
int getline(char *line)
{
	int count = 1;
	int flag = 0;

	if (line == NULL)
		return (count);

	for (int i = 0; line[i] != '\0'; i++)
	{
		for (int j = 0; line[j] != '\0'; j++)
		{
			if (line[i] == ' ' || line[i] == ':')
			{
				count++;
				flag = 1;
				break;
			}
		}
		if (!flag)
			flag = 0;
	}
	return ((count + 1));
}
