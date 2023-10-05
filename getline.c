#include "main.h"

int main()
{
	char **token, *str = malloc(1024);
	size_t i, len = 1024;
	int index = 0;
	
	while (1)
	{	
		printf("$ ");
		i = getline(&str, &len, stdin);
		if (i == -1)
			exit(EXIT_FAILURE);

		token[index] = strtok(str, " ");

	while (token[index] != NULL)
	{
		printf("%s\n", token[index]);
		token[index] = strtok(NULL, " ");
		index++;

	}
	}
}
