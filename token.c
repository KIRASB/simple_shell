#include "main.h"
/**
 * token_it - takes a long string and separate cut int into small strings
 * @ptr: pointer point to a string
 * Return: double pointer contain the list of small strings
 */
char **token_it(char *ptr, char *del)
{
	char **tokens = (char **)malloc(sizeof(char*));
	int i = 0;

	if (tokens == NULL)
		return (NULL);

	tokens[i] = strtok(ptr, del);
	while(tokens[i] != NULL)
	{
		tokens = (char **)realloc(tokens, (i + 1) * sizeof(char *));
		if(tokens == NULL)
			return (NULL);

		tokens[i] = strtok(NULL, del);
		i++;
	}
	return(tokens);
}
