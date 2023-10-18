#include "main.h"
#include <sys/wait.h>

char *get_cmd()
{
	char *fcmd, *cmdline = malloc(1024);
	size_t len = 1024;
	int i, j = 0;
	char *e = "exit";
	fcmd = cmdline;
	
	while (1)
	{	
		printf("$ ");
		i = getline(&cmdline, &len, stdin);
		if (i == -1)
		{
			printf("\n\n[Disconected...]\n");
			exit(EXIT_FAILURE);
		}

		//cmd = token_it(cmdline, " ");
		//printf("%s", cmd[0]);

			while (cmdline[j] != '\0')
			{
				if (cmdline[j] == '\n')
				{
					cmdline[j] = '\0';
					break;
				}
				fcmd[j] = cmdline[j];
				j++;
			}
/*
		if (fcmd[0] == "exit")
		{
			printf("\n\n[Disconected...]\n");
			exit(EXIT_FAILURE);
		}
	
		char *argv[] = {cmd, NULL};

		int pid = fork();
		waitpid(pid, NULL, WNOHANG);
		if (pid == 0)
		{
		i = execve(fcmd, argv, env);
		if (i == -1)
			printf("command not found\n");
		}
		if(pid == -1)
		printf("fork is fail\n");
	*/	
	return (cmdline);
	free(cmdline);
	free(fcmd);
}}
