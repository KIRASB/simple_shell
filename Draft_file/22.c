#include "shell.h"

extern char **environ;

int get_env()
{
	ssize_t w_err;
	int i = 0;
	char **envir = environ;
	while (envir[i])
	{
		w_err = write(1, "\n", 1);
		if(w_err == -1)
		{
			perror("write");
			return 1;
		}
		w_err = write(1, envir[i], strlen(envir[i]));
		if(w_err == -1)
		{
			perror("write");
			return 1;
		}
		i++;
	}
	return 0;
}
