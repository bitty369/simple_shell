#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "shell.h"

/**
 * check_command - creates a simple shell
 * @command: command variable
 * Return: 0 on success
 */

void check_command(char *command)
{
	if (access(command, F_OK) == 0)
		printf("%s: FOUND\n", command);
	else
		printf("%s: NOT FOUND\n", command);
}

/**
 * main - creates a simple shell
 *
 * Return: 0 on success
 */

int main(void)
{
	char *buff = NULL;
	size_t buff_size;
	ssize_t charse;
	char *tock;

	while (1)
	{
		write(1, "$ ", 2);
		charse = getline(&buff, &buff_size, stdin);
		tock = strtok(buff, "\t\n");
		if (strcmp(tock, "which") == 0)
		{
			tock = strtok(NULL, "\t\n");
			while (tock)
			{
				check_command(tock);
				tock = strtok(NULL, "\t\n");
			}
		}
		else
			printf("command doesn't exists\n");
	}
}
