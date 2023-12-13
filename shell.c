#include "shell.h"

/**
 * main - Entery point
 * Return: 0
 */

int main(void)
{
	char *p;
	size_t size;
	char *promt = "$ ";

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(1, promt, 2);

			if ((getline(&p, &size, stdin) == -1))
				break;

			if (strcmp(p, "exit") == 0)
				break;

			execute(p);
		}
	}
	free(p);
	return (0);
}




