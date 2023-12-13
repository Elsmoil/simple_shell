#include "shell.h"

/**
 * strlen - calculate string length
 * @str: pointer
 * Return: integer
 */

int _strlen(char *str)
{
	int i = 0;

	while (str[i])
	{
		i++;
	}
	return (i);
}
