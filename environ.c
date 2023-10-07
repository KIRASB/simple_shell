#include <stdio.h>
#include "main.h"

<<<<<<< HEAD
int main(int ac, char **av,  char **env)
{
	size_t i = 0;
	char *token, *tok, *var = env[i];
	
	while (var)
	{
	var = env[i];
	//token = strtok(var, " ");
	//tok = strtok(NULL, " ");
	printf("%s\n", var);
	i++;
	}
	free(var);
	return (0);
=======
extern char **environ;

char **get_env()
{
	char **envir = environ;
	
	return(envir);
>>>>>>> 03ea7e750ac975a558fc1a24bed01513a2178e68
}
