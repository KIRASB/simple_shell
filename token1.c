#include "main.h"

/**
  *token_it - function that ttokinaze the string depending on delimeter
  *@ptr: the string will tokinze
  *@del: the delimeter of tokinaze
  *Return: the tokinzed array of pointer
  */

char** token_it(char* ptr, char* del)
{
	char** tokens = NULL;
	char* copy = strdup(ptr);
	char* token;
	int i;

	if (copy == NULL)
		return NULL;

	tokens = (char**)malloc(2 * sizeof(char*)); // Allocate space for at least two pointers

	if (tokens == NULL) 
	{
		free(copy);
		return (NULL);
	}

	token = strtok(copy, del);
	i = 0;

	while (token)
	{
		tokens[i] = malloc(sizeof(char*));
		tokens[i] = strdup(token);

		if (tokens[i] == NULL)
		{
			free(copy);
			for (int j = 0; j < i; j++)
				free(tokens[j]);
			free(tokens);
			return NULL;
		}

		token = strtok(NULL, del);
		i++;
	}

	tokens[i] = NULL; // Set the last element of the tokens array to NULL

	free(copy);
	return (tokens);
}
/*int main()
{
	int i = 0;
	char **tok;
	char *ptr = "omar:algassim:hello:world:is:fun";

	tok = token_it(ptr, ":\n\t");
	
	while (tok[i])
	{
		printf("%s\n", tok[i]);
		i++;
	}
}*/
