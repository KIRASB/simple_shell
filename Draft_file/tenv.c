#include "main.h"

extern char **environ;

int get_env(void)
{
	int i = 0;
	char **envir = environ;
	while (envir[i])
	{
		printf("%s\n", envir[i]);
		i++;
	}
	return 0;
}
