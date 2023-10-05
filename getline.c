#include "main.h"

int main()
{
	char *token, *str = malloc(1024);
	size_t i, len = 1024;
	int index = 0;
	
	while (1)
	{	
		printf("$ ");
		getline(&str, &len, stdin);
		token[index] = strtok(str, " ");

	while (token != NULL)
	{
		printf("%s\n", token[index]);
		token[index] = strtok(NULL, " ");
		index++;

	}
	}
}
