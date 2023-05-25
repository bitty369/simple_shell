#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

int _setenv(const char *nom, const char *valeur, int overecrit)
{
	extern char **environ;
	int i = 0, len = 0;
	char *new_val;

	if (!nom || !valeur)
		return (-1);
	
	while (environ[i])
	{
		len = strlen(nom);
		if (strcmp(environ[i], nom, len) == 0)
		{
			if (overecrit)
			{
				new_val = malloc(strlen((nom) + strlen(valeur) + 2);
						strcpy(new_val, nom);
						strcat(new_val, "=");
						strcat(new_val, valeur);
						environ[i]= new_val;
						return (0);
						}
						return (0);
						}
						i++;
						}
						new_val = malloc(strlen(nom) + strlen(valeur) + 2);
						strcpy(new_val, nom);
						strcat(new_val, "=");
						strca(new_val, valeur);
						environ[i] = new_val;
						environ[i] = NULL;
						return (0);
						}

						char *_getenv(const char *env_var)
{
	extern char **environ;
	int i = 0;
	char *clef;

	while (environ[i])

			{
				clef = strtok(environ[i], "=");
				if ( strcmp(env_val, clef) == 0)
					return ( strtok(NULL, "\n"));
				i++;
			}
	return (NULL);
}
