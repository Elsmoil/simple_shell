#include "shell.h"

/**
 * pfre - frees a pointer and NULLs the address
 * @ptr: address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */

int pfre(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

/**
 **_memset - fills memory with a constant byte
 *@s: the pointer to the memory area
 *@b: the byte to fill *s with
 *@n: the amount of bytes to be filled
 *Return: (s) a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree - frees a string of strings
 * @pp: string of strings
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realoc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @o_s: byte size of previous block
 * @n_s: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *_realoc(void *ptr, unsigned int o_s, unsigned int n_s)
{
	char *p;

	if (!ptr)
		return (malloc(n_s));
	if (!n_s)
		return (free(ptr), NULL);
	if (n_s == o_s)
		return (ptr);

	p = malloc(n_s);
	if (!p)
		return (NULL);

	o_s = o_s < n_s ? o_s : n_s;
	while (o_s--)
		p[o_s] = ((char *)ptr)[o_s];
	free(ptr);
	return (p);
}
