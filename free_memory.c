#include "simple_shell.h"

/**
 * free_single_ptr - free pointer
 * @ptr : pointer to be freed
 * Return: no return
 */
void free_single_ptr(char *ptr)
{
	if (ptr != NULL)
		free(ptr);
}
/**
 * free_double_ptr - free pointer
 * @ptr : ponter to be freed
 * Return: no return
 */
void free_double_ptr(char **ptr)
{
	if (ptr != NULL)
	{
		int idx = 0;

		while (ptr[idx] != NULL)
		{
			free(ptr[idx]);
			idx++;
		}
		free(ptr);
	}
}
/**
 * free_memory - frees dynamically allocated memory
 * @count: specifies pointer to be freed
 * Return: void
 */
void free_memory(int count, ...)
{
	va_list args;

	va_start(args, count);
	char *sptr;
	char **dptr;
	int i = 0;

	while (i < count)
	{
		if (i == 0)
		{
			sptr = va_arg(args, char *);
			free_single_ptr(sptr);
		}
		else if (i == 1)
		{
			dptr = va_arg(args, char **);
			free_double_ptr(dptr);
		}
		i++;
	}
	va_end(args);
}

