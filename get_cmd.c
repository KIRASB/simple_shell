#include "main.h"
#include <sys/wait.h>

char  *get_cmd()
{
	char *cmd, *fcmd, *cmdline = malloc(1024);
	size_t len = 1024;
	char **env = get_env();
	int i, le, j = 0;


	while (1)
	{	
		printf("$ ");
		i = getline(&cmdline, &len, stdin);
		if (i == -1)
		{
			printf("\n\n[Disconected...]\n");
			exit(EXIT_FAILURE);
		}
		cmd = strtok(cmdline, " ");
		le = strlen(cmd);

		fcmd = cmd;
			while (fcmd[j] != '\0')
			{
				if (fcmd[j] == '\n')
				{
					fcmd[j] = '\0';
					break;
				}
				fcmd[j] = cmd[j];
				j++;
			}

		char *argv[] = {cmd, NULL};

		pid = fork();
		waitpid(pid, NULL, WNOHANG);
		if (pid == 0)
		{
		i = execve(cmd, argv, env);
		if (i == -1)
			printf("command not found\n");
		}
		if(pid == -1)
		printf("fork is fail\n");
	
	}
	return (cmdline);
	free(cmdline);
}
