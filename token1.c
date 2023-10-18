#include "shell.h"
/**
 * token_it - takes a long string and separate cut int into small strings
 * @ptr: pointer point to a string
 * Return: double pointer contain the list of small strings
 */
char **token_it(char *ptr, char *del)
{
	char **tokens;
	int i = 0;
	char *token;
<<<<<<< HEAD
	char *copy = strdup(ptr); //save the original content;
	
	if (ptr == NULL || ptr == "\n")
		return (0);
	tokens = (char **)malloc(sizeof(char *));
=======
	char *copy = strdup(ptr);

	tokens = (char **)malloc(sizeof(char *) * 1);
>>>>>>> 30d6e11055a9a866b2334fe35035b769176a748d
	if (tokens == NULL)
		return (NULL);
	
	token = strtok(copy, del);
	
	while(token != NULL)
	{
		tokens[i] = strdup(token);
		tokens = (char **)realloc(tokens, (i + 2) * sizeof(char *));
		if(tokens == NULL)
		{
			return (NULL);
		}
		token = strtok(NULL, del);
		i++;
	}
	tokens[i] = NULL;
	free(copy);
	return(tokens);
}
<<<<<<< HEAD
/*
int main(void)
{
	printf("test");
	char **tok = token_it("ls -la", " ");
	printf("%s", tok[0]);
	execute(tok);
	return 0;
}*/
=======
>>>>>>> 30d6e11055a9a866b2334fe35035b769176a748d
