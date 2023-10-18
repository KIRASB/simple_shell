#include "shell.h"
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
	ssize_t w_err;
	int check, i = 0;
	int fd = 0;
	char *env = "env";
	char ext[4] = "exit";

	while(1)
	{
		if (isatty(fd))
			w_err = write(1, "$ ", 2);

		ret = getline(&cmd, &len, stdin);
		if(ret != (size_t)-1)
		{
			tokens = token_it(cmd, " \t\n");
			if(tokens[0] == NULL)
			{
				free(tokens[0]);
				free(tokens);
				continue;
			}

			check = _strcmp(tokens[0], ext);

			if(check == 0)
			{
				free(cmd);
				exit(EXIT_SUCCESS);
			}

			check = _strcmp(tokens[0], env);
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
			{
				w_err = write(1, "\n", 1);
				if(w_err == -1)
				{
					perror("write");
					return 1;
				}
			}
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
