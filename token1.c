#include "main.h"
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
	char *copy = strdup(ptr); //save the original content;

	tokens = (char **)malloc(sizeof(char *));
	if (tokens == NULL)
		return (NULL);

	token = strtok(ptr, del);
	tokens[0] = strdup(token);
	//if there is more token the loop keeps working
	while(token != NULL)
	{
		//new momory for the array and allocat for the pointer
		tokens = (char **)realloc(tokens, (i + 1) * sizeof(char *));  // !!!
		if(tokens == NULL)
		{
			free(ptr);
			return (NULL);
		}
		tokens[i] = (char *)malloc(strlen(token) + 1);
		if(tokens[i] == NULL)
		{
			free(copy);
			return (NULL);
		}
		
		strcpy(tokens[i], token);
		token = strtok(NULL, del);
	}
	free(copy);
	return(tokens);
}

int main(void)
{
	printf("test");
	char **tok = token_it("ls -la", " ");
	printf("%s", tok[0]);
	execute(tok);
	return 0;
}
