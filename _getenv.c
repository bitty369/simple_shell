#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

/**
 * _getenv - finds and returns a copy of the requested environmental variable
 * @name: string to store it in
 *
 * Return: copy of requested environmental variable
 */

char *_getenv(const char *name)
{
	extern char **environ;
	int i = 0;
	char *key;

	while (environ[i])
	{
		key = strtok(environ[i], "=");
		if (strcmp(key, name) == 0)
			return (strtok(NULL, "="));
		i++;
	}
	return (NULL);
}

/**
 * main - create the path of the file.
 *
 * Return: always 0.
 */

int main(void)
{
	printf("%s\n", _getenv("PATH"));
	return (0);
}
