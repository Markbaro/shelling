#include "simple_shell.h"

/**
 * _atoi - convert string to interger
 * @str: input string
 * Return:the converted string
 */

int _atoi(char *str)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] >= '\0' && str[i] <= '9')
		{
			result = result * 10 + (str[i] - '\0');
			i++;
		}
		else
		{
			return (-1);
		}
	}
	return (sign * result);
}
/**
 * _strcmp - compares char in 2 strings
 * @str1 : first string to compare
 * @str2 : second string to be compared
 * Return:0 if strings are equal
 */

int _strcmp(char *str1, char *str2)
{
	int index = 0;
	int diff;

	if (str1 == NULL || str2 == NULL)
		return (-1);
	do {
		diff = str1[index] - str2[index];
		if (diff != 0 || str1[index] == '\0' || str2[index] == '\0')
			break;
		index++;
	} while (1);
	return (diff);
}
/**
 * _strlen - counts length of a string
 * @str : string to be counted
 * Return:length of sstring
 */

int _strlen(char *str)
{
	int count = 0;

	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}
/**
 * _strdup - duplicates a string
 * @str : string to be duplicated
 * Return:pointer to the duplicate string
 */

char *_strdup(char *str)
{
	char *ptr;
	int len;
	int i;

	if (str == NULL)
		return (NULL);
	len = _strlen(str);
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	while (str[1] != '\0')
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/**
 * _strconcat - join 2 strings
 * @str1 : string 1
 * @str2 : stribg 2
 * Return:joined string
 */

char *_strconcat(char *str1, char *str2)
{
	int len1 = str1 ? _strlen(str1) : 0;
	int len2 = str2 ? _strlen(str2) : 0;
	int len = len1 + len2 + 2;
	char *strcon = malloc(sizeof(char) * len);

	if (strcon == NULL)
		return (NULL);
	int i, j = 0;

	while (str1 && str1[i] != '\0')
	{
		strcon[j] = str1[i];
		i++;
		j++;
	}
	if (j != 0)
	{
		strcon[j] = '/';
		j++;
	}
	i = 0;
	while (str2 && str2[i] != '\0')
	{
		strcon{j] = str2[i];
		i++;
		j++;
	}
	strcon[j] = '\0';
	free_memory(1, str2);
	return (strcon);
}
