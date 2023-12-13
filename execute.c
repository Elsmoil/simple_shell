#include "shell.h"

/**
 * execute - execute the commands
 * comm: a pointer
 */

void execute(char *comm)
{
	struct stat st;
	char *argv[1024], *path, *copy_path, *token, *path_token;
	char fullPath[1024];
	int i, status, n;
	pid_t child_pid;

	token = strtok(comm, " ");
	for (i = 0; token != NULL; i++)
	{
		argv[i] = token;
		token = strtok(NULL, " ");
	}
	argv[i] = NULL;

	if (_strchr(argv[0], '/') != NULL)
	{
		path = getenv("PATH");
		copy_path = strdup(path);
		path_token = strtok(copy_path, ":");

		while (path_token != NULL)
		{
			n = strlen(path_token);
			_strncpy(fullPath, path_token, n);
			_strncat(fullPath, "/", 1);
			n = _strlen(argv[0]);
			_strncat(fullPath, argv[0], n);

			if (stat(fullPath, &st) == 0)
			{
				child_pid = fork();
				if (child_pid == 0)
				{
					if (execve(fullPath, argv, NULL) != -1)
					{
						free(copy_path);
						free(path);
						exit(EXIT_SUCCESS);
					}
				}
				else
					wait(&status);
			}
			path_token = strtok(NULL, " ");
		}
		perror("./shell");
	}
	else
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("./shell");
				exit(EXIT_FAILURE);
			}
		}
		else
			wait(&status);
	}
}





