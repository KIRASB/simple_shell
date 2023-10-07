<<<<<<< HEAD
=======
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
>>>>>>> 03ea7e750ac975a558fc1a24bed01513a2178e68
#include "main.h"

int main()
{
<<<<<<< HEAD
	char *token, **str = malloc(1024);
	size_t len = 1024;
	int i, n = 0;
	
	while (1)
	{	
		printf("$ ");
		i = getline(str, &len, stdin);
=======
	char *token, *str = malloc(1024);
	size_t len = 1024;
	char **env = get_env();
	int i;

	while (1)
	{	
		printf("$ ");
		i = getline(&str, &len, stdin);
>>>>>>> 03ea7e750ac975a558fc1a24bed01513a2178e68
		if (i == -1)
		{
			printf("Disconected\n");
			exit(EXIT_FAILURE);
		}
<<<<<<< HEAD
		/*if (str[n] == )
		{
			printf("this is arg");
			n++;
		}*/

		token = strtok(*str, " ");

	while (token != NULL)
	{
	//	printf("%s\n", token);
		token = strtok(NULL, " ");

	}
=======
		token = strtok(str, " ");

		char *argv[] = {token, NULL};

		i = execve(token, argv, env);
		if (i == -1)
			printf("command noot found");
		else
			return 0;
>>>>>>> 03ea7e750ac975a558fc1a24bed01513a2178e68
	}
	free(str);
}
