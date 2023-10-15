#include "main.h"

char** token_it(const char* ptr, const char* del)
{
    char** tokens = NULL;
    char* copy = strdup(ptr);

    if (copy == NULL)
        return NULL;

    tokens = (char**)malloc(2 * sizeof(char*)); // Allocate space for at least two pointers

    if (tokens == NULL) {
        free(copy);
        return NULL;
    }

    char* token = strtok(copy, del);
    int i = 0;

    while (token) 
    {
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

    tokens[i] = '\0'; // Add a null terminator to mark the end of the tokens array

    free(copy);
    return tokens;
}

int main(void)
{
	char command[] = "ls";
        char **tok = token_it(command, " ");
        printf("%s %s\n", tok[0], tok[1]);
	execute(tok);
        return 0;
}
