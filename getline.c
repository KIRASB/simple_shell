#include "main.h"

int main()
{
	char **token, *str = malloc(1024);
	size_t i, len = 1024;
	
	
	while (i != -1)
	{	
		printf("$ ");
		getline(&str, &len, stdin);
		token = strtok(str, " ");

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, " ");

	}
	}
}
