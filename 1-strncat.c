#include "shell.h"

/**
 * *_strncat - concatenates two strings
 * @dest: pointer to destination
 * @src: pointer to source
 * @n: int parameter
 * Return: concatenated string
 */

char *_strncat(char *dest, char *src, int n)
{
	int i, j;

	i = 0;

	while (dest[i])
		i++;

	for (j = 0; j < n && src[j] != '\0'; j++)
		dest[i++] = src[j];

	dest[i + j] = '\0';

	return (dest);
}

