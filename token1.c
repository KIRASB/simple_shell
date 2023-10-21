#include "shell.h"
/**
 * token_it - takes a long string and separate cut int into small strings
 * @ptr: pointer point to a string
 * @del: the delemiter to use for seprating
 * Return: double pointer contain the list of small strings
 */
char **token_it(char *ptr, char *del)
{
	char **tokens;
	int i = 0;
	char *token;
	char *copy = strdup(ptr);

	tokens = (char **)malloc(sizeof(char *) * 1);
	if (tokens == NULL)
		return (NULL);
	token = strtok(copy, del);
	while (token != NULL)
	{
		tokens[i] = _strdup(token);
		tokens = (char **)realloc(tokens, (i + 2) * sizeof(char *));
		if (tokens == NULL)
		{
			return (NULL);
		}
		token = strtok(NULL, del);
		i++;
	}
	tokens[i] = NULL;
	free(copy);
	return (tokens);
}
