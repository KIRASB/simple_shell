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
	int check1, check2, i = 0;
	int fd = 0;
	char *env = "env";
	char ext[4] = "exit";

	while(1)
	{
		if (isatty(fd))
			w_err = write(1, "$ ", 2);

		ret = getline(&cmd, &len, stdin);
		if(ret != -1) 
		{
			tokens = token_it(cmd, " \t\n");
			if(tokens[0] == NULL)
			{
				//free(tokens[0]);
				free(tokens);
				continue;
			}

			check1 = _strcmp(tokens[0], ext);

			if(check1 == 0)
			{
				
				exit(EXIT_SUCCESS);
			}

			check2 = _strcmp(tokens[0], env);
			if (check2 == 0)
				get_env();
			else
			{
				execute(tokens);
				free(cmd);
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

		//free(tokens);
	}
//	free(cmd);
	return (0);
}
