#include "main.h"

extern char **environ;

char **get_env()
{
	int i = 0;
	char **envir = environ;
	while (envir[i])
	{
		printf("%s\n", envir[i]);
		i++;
	}
	return(envir);
}
