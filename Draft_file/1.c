#include "shell.h"

int execute(char **args)
{
	char *allpaths = NULL;
	char **paths = NULL;
	char **path_and_file = NULL;
	char *real_cmd = NULL;
	int i = 0;
	int size = 0;
	int check;
	int status;
	pid_t pid;
	char **copy;

	copy = (char **)malloc(sizeof(char *));

	while(args[i] != NULL)
	{
		copy = (char **)realloc(copy, sizeof(char *) * (i + 2));
		copy[i] = strdup(args[i]);
		i++;
	}
	copy[i] = NULL;

	allpaths = getenv("PATH");
	paths = token_it(allpaths, ":\t\n");
	
	size = 0;
	while(paths[size])
	{
		size++;
	}
	path_and_file = (char **)malloc(sizeof(char *) * (size + 1));
	if (path_and_file == NULL)
		return (-1);

	i = 0;
	while (paths[i] != NULL && i < size && copy[0][0] != '/')
	{
		path_and_file[i] = (char *)malloc(strlen(paths[i]) + strlen(copy[0]) + 2);
		if(path_and_file[i] == NULL)
			return (-1);

		strcat(path_and_file[i], paths[i]);
		strcat(path_and_file[i], "/");
		strcat(path_and_file[i], copy[0]);
		i++;
	}
	if(copy[0][0] == '/')
	{
		path_and_file[0] = strdup(copy[0]);
	}
	i = 0;
	while(path_and_file[i] != NULL && i < size)
	{
		check = access(path_and_file[i], F_OK);
		if(check == -1)
		{
			free(path_and_file[i]);
			i++;
			continue;
		}
		if(check == 0)
		{
			real_cmd =  strdup(path_and_file[i]);
			free(path_and_file[i]);
			break;
		}
		i++;
	}

	free(path_and_file);
	check = access(real_cmd, X_OK);
	if(check != 0)
	{
		printf("%s: command not found\n", args[0]);
	}
	else
	{
		pid = fork();
		if(pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		if(pid == 0)
		{
			execve(real_cmd, args, NULL);
			exit(EXIT_SUCCESS);
		}
		else
		{
			wait(&status);
		}
		free(copy);
		free(real_cmd);
	}
	return (0);
}
