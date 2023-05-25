#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include "shell.h"


char *_getenv(const char *env_var)
{
	extern char **environ;
	int i = 0;
	char *key;

	while (environ[i])
	{
		key = strtok(environ[i], "=");
		if (strcmp(env_var, key) == 0)
			return (strtok(NULL, "\n"));
		i++;
	}
	return (NULL);
}

char *get_command(char *command)
{
char *path = _getenv("PATH");
char *tock;
char *cmd_full;
struct stat st;

tock = strtok(path, ":");
while (tock)
{
cmd_full = malloc(strlen(tock) + strlen(command) + 2);
strcpy(cmd_full, tock);
strcat(cmd_full, "/");
strcat(cmd_full, command);
if (stat(cmd_full, &st) == 0)
	return (cmd_full);
free(cmd_full);
tock = strtok(NULL, ":");
}
return (NULL);
}

char **split_string(char * buff, char *dell)
{
	char **tocks;
	char *tock;
	int i = 0;

	tocks = malloc(sizeof(char *) * 1024);
	tock = strtok(buff, dell);
	while (tock)
	{
		tocks[i] = tock;
		tock = strtok(NULL, dell);
		i++;
	}
	tock[i] = NULL;
	return (tocks);
}

int main(int ac, char **av, char **env)
{
	char *buff = NULL;
	size_t buff_size = 0;
	char *cmd;
	char **args;
	pid_t pid;
	int status, n_charse;

	while (1)
	{
		write(1, "$ ", 2);
		n_charse = getline(&buff, &buff_size, stdin);
			if (n_charse == -1)
			{
				write(1, "\n", 1);
				exit(1);
			}
		args = split_string(buff, "\t\n");
		if (strcmp(args[0], "exit") == 0)
			exit(0);
		pid = fork();
		if (pid == 0)
		{
			cmd = get_command(args[0]);
			if (cmd)
				execve(cmd, args, env);
			else
				printf("command nit found\n");
			exit(0);
		}
		else
			wait(&status);
	}
	return(0);
}
