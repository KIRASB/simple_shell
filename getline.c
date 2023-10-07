#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

int main()
{
	char *token, *str = malloc(1024);
	size_t len = 1024;
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

	while (token != NULL)
	{
		char *argv[] = {token, NULL};

		execve(token, argv, NULL);
		token = strtok(NULL, " ");
	}
	}
	free(str);
}
