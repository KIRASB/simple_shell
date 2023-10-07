#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

int main()
{
	char *token, *str = malloc(1024);
	size_t len = 1024;
	char **env = get_env();
	int i;

	while (1)
	{	
		printf("$ ");
		i = getline(&str, &len, stdin);
		if (i == -1)
		{
			printf("Disconected\n");
			exit(EXIT_FAILURE);
		}
		token = strtok(str, " ");

		char *argv[] = {token, NULL};

		i = execve(token, argv, env);
		if (i == -1)
			printf("command noot found");
		else
			return 0;
	}
	free(str);
}
