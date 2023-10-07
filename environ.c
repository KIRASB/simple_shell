#include "main.h"

int main(int ac, char **av, char **env)
{
	int i = 0;
	char *token, *tok, *var = env[i];
	while (var)
	{
	var = env[i];
	token = strtok(var, " ");
	tok = strtok(NULL, " ");
	printf("%s\n", tok);
	i++;
	}
}
