#include <stdio.h>
#include <unistd.h>
#include "shell.h"

/**
 * main - creates a simple shell
 * @ac: argument count
 * @av: argument vectors
 *
 * Return: 0 on success
 */

int main(int ac, char **av)
{
	(void)ac;
	char *buff = NULL;
	size_t size_buff = 0;
	int n_char = 0;

	write(1, "$ ", 2);
	n_char = getline(&buff, &size_buff, stdin);
	if (n_char == EOF)
	perror("getline");
	printf("%s\n", buff);

	return (0);
}
