#include <stdio.h>
#include "main.h"

extern char **environ;

char **get_env()
{
	char **envir = environ;
	
	return(envir);
}
