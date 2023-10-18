#include "shell.h"

/**
  *_strdup - duplicate the string
  *@str: the string will duplicate
  *Return: the duplicate string
  */

char *_strdup(char *str)
{
	char *dup;
	int i, len;
	i = 0;
	len = 0;

	if (str == NULL)
		return (NULL);

	while (str[len] != '\0')
		len++;

	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);

	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';

	return (dup);
}

int main() {
    char *input = "Hello, World!";
    char *output = _strdup(input);

    if (output == NULL) {
        fprintf(stderr, "Failed to duplicate string\n");
        return EXIT_FAILURE;
    }

    printf("Duplicated string: %s\n", output);
    free(output);
    return EXIT_SUCCESS;
}

