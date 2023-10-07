#include "main.h"

int main()
{
	char *token, **str = malloc(1024);
	size_t len = 1024;
	int i, n = 0;
	
	while (1)
	{	
		printf("$ ");
		i = getline(str, &len, stdin);
		if (i == -1)
		{
			printf("Disconected\n");
			exit(EXIT_FAILURE);
		}
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
	}
	free(str);
}
