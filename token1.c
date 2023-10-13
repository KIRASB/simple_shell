#include "main.h"

char** token_it(char* ptr, char* del)
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
