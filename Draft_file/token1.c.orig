#include "shell.h"
/**
 * token_it - takes a long string and separate cut int into small strings
 * @ptr: pointer point to a string
<<<<<<< HEAD
 * @del: the delemiter to use for seprating
=======
 * @del: the delimeter
>>>>>>> bb8c18f0fbe4ee20d8284d0b9780af366a9d4089
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
<<<<<<< HEAD
	token = strtok(copy, del);
=======

	token = strtok(copy, del);

>>>>>>> bb8c18f0fbe4ee20d8284d0b9780af366a9d4089
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
