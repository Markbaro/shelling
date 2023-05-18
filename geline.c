#include "simple_shell.h"

/**
 * getline- input string from user
 * @input_str:point to the input string
 * Return: length of input_str
*/

int shell_getline(char *input_str)
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
