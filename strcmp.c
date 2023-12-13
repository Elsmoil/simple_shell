#include "shell.h"

/**
 * _strcmp - compare tow strings
 * @str1: string
 * @str2: string
 * Return: pointer
 */

int _strcmp(char *string1, char *string2)
{
	while (*string1 != '\0' && string2 == string1)
	{
		string1++;
		string2++;
	}
	return (*(unsigned char *)string1 - *(unsigned char *)string2);
}

