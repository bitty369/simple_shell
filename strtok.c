#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

char **splitter(char *str)
{
	char *tock, ***tockens;
	int i = 0;

	tock = strtok(str, "\t\n");
	while (tock != NULL)
	{
		i++;
		tockens = realloc(tockens, i * sizeof(char *));
		if (tockens == NULL)
		{
			perror("realloc");
			exit(EXIT_FAILURE);
		}
		tockens[i - 1] = tock;
		tock = strtok(NULL, "\t\n");
	}

	for (i = 0; tockens[i]; i++)
		printf("%s\n", tockens[i]);

	return (0);
}

	int main(int argc, char **argv)
	{
		(void)argc;
		(void)argv;

		char *buff = NULL;
		size_t size_buff = 0;
		int n_char = 0;
		int tock_size = 0;
		char **tockens = NULL;
		char *tock = NULL;

		printf("$ ");
		n_char = getline(&buff, &size_buff, stdin);
		if (n_char == -1)
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
		buff[n_char - 1] = '\0';

		return (0);
	}

