#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

/**
 * main - creates a simple shell
 *
 * Return: 0 on success
 */

int main(void)
{
	char *buff = NULL;
	size_t buff_size = 0;
	int n_char;
	char *tock;
	char **array;
	int status, i = 0;
	pid_t pid;

	while (1)
	{
		write(1, "$ ", 2);
		n_char = getline(&buff, &buff_size, stdin);
		array = malloc(sizeof(char *) * 1024);
		tock  = strtok(buff, "\t\n");
		while (tock)
		{
			array[i] = tock;
			tock = strtok(NULL, " \t\n");
			i++;
	}
	array[i] = NULL;
	pid = fork();
	if (pid == 0)
	{
		if (execve(array[0], array, NULL) == -1)
		perror("execve");
	}
	else
		wait(&status);
	i = 0;
	free(array);
}
}
