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
	int input_len;
	char c;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(1, promt, 2);

			if ((getline(&p, &size, stdin) == -1))
				break;
			input_len = strlen(p);

			if (input_len > 0)
			{
				c = p[input_len - 1];
				if (c == '\n')
					p[input_len - 1] = '\0';
			}

			if (strcmp(p, "exit") == 0)
				break;

			execute(p);
		}
	}
	free(p);
	return (0);
}




