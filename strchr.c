#include "shell.h"

/**
 * _strchr - a string function
 * @str: pointer
 * @ch: character
 * Return: pointer
 */

char *_strchr(char *str, char ch)
{
	while (*str != '\0' && *str != ch)
		str++;
       
	return ((*str == ch) ? (char *)str : NULL);
}

