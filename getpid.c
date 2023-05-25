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
	int i = 0;

	while (av[i])
	{
		printf("%s\n", av[i]);
		i++;
	}
	return (0);
}
