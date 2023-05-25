#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

/**
 * main - creates a simple shell
 * @ac: argument count
 * @av: argument vectors
 * @env: environmental variables
 * Return: 0 on success
 */

int main(int ac, char **av, char **env)
{
	extern char **environ;

	printf("%p\n", env);
	printf("%p\n", environ);
}
