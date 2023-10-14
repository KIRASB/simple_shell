#include "main.h"

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
	pid_t pid, ppid;

	allpaths = getenv("PATH");
	paths = token_it(allpaths, ":\n\t");

	while(paths[size])
	{
		size++;
	}
	//alocate mimory for the array
	path_and_file = (char **)malloc(sizeof(char *) * (size + 1));
	if (path_and_file == NULL)
		return (-1);

	i = 0;
	while (paths[i] != NULL && i < size)
	{
		//alocate memory for each pointer in the array
		path_and_file[i] = (char *)malloc(strlen(paths[i]) + strlen(args[0]) + 2);
		if(path_and_file[i] == NULL)
			return (-1);
		//stick each path to the input comand
		strcpy(path_and_file[i], paths[i]);
		strcat(path_and_file[i], "/");
		strcat(path_and_file[i], args[0]);
		i++;
	}
	i = 0;
	while(path_and_file[i] != NULL && i < size)
	{
		//check for the access and existence
		check = access(path_and_file[i], X_OK);
		if(check == -1)		//if it's not the file I want free its mimmory
		{
			free(path_and_file[i]);
			i++;
			continue;
		}
		if(check == 0)
		{
			real_cmd = path_and_file[i];
			break;
		}
		i++;
	}
	//free the momiry of the array

	free(path_and_file);
	//executing process
	pid = fork();
	if(pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if(pid == 0)
	{
		check = execve(real_cmd, args, NULL);
		if(check == -1)
		{
			printf("%s: command not found\n", args[0]);
			exit(EXIT_FAILURE);
		}
		if(check == 0)
		{
			exit(EXIT_SUCCESS);
		}
	}
	else
	{
		wait(&status);
	}
	free(real_cmd);
	return (0);
}