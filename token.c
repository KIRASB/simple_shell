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

	tokens = (char **)malloc(sizeof(char *) * 1);
	if (tokens == NULL)
		return (NULL);
	
	token = strtok(copy, del);
	//if there is more token the loop keeps working
	while(token != NULL)
	{
		tokens[i] = strdup(token);
		//new momory for the array
		tokens = (char **)realloc(tokens, (i + 2) * sizeof(char *));  // !!!
		if(tokens == NULL)
		{
			return (NULL);
		}
		token = strtok(NULL, del);
		i++;
	}
	tokens[i] = NULL;
	free(copy);
	// maybe need to free the ptr
	return(tokens);
}

int main(void)
{
	printf("test\n");
	char **tok = token_it("ls -la", " \n");
	//printf("%s  %s %s %s %s %s %s\n", tok[0], tok[1], tok[2],tok[3], tok[4], tok[5], tok[6]);
	execute(tok);
	return 0;
}
