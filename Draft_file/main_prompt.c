#include "main.h"
/**
 * main - show the prompt and do the process and show the prompt again
 *
 * Return: 0
 */
int main()
{
	char *cmd = NULL;
	size_t len = 0;
	size_t ret;
	char **tokens;
	int check, i = 0;
	int fd = 0;
	char *env = "env";
	char ext[4] = "exit";

	while(1)
	{
		if (isatty(fd))
			printf("$ ");

		ret = getline(&cmd, &len, stdin);
		if(ret != -1)
		{
			tokens = token_it(cmd, " \t\n");
			if(tokens[0] == NULL)
			{
				free(tokens[0]);
				free(tokens);
				continue;
			}

			check = strcmp(tokens[0], ext);

			if(check == 0)
			{
				printf("exit...\n");
				free(cmd);
				exit(EXIT_SUCCESS);
			}

			check = strcmp(tokens[0], env);
			if (check == 0)
				get_env();

			else
			{
				execute(tokens);
			}
		}
		else
		{
			if(isatty(fd))
				printf("Disconected...\n");
			exit(EXIT_SUCCESS);
		}
		while (tokens[i] != NULL)
		{
			free(tokens[i]);
			i++;
		}
		free(tokens);
	}
	return (0);
}
