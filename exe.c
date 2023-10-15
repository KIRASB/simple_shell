#include "main.h"

int execute(char **args)
{
	char *const ar[] = {"-l", NULL};
	char *allpaths = NULL;
	char **paths = NULL;
	char *arg = NULL;
	char **path_and_file = NULL;
	char *real_cmd = NULL;
	int i = 0;
	int size = 1;
	int check;
	int status;
	pid_t pid, ppid;

	allpaths = getenv("PATH");
	paths = token_it(allpaths, ":\n\t");

	while (paths[size])
	{
		//printf("%s\n", paths[size]);
		size++;
	}
	
	//alocate memory for the array
	path_and_file = (char **)malloc(sizeof(char *) * (size + 4));
	if (path_and_file == NULL)
		return (-1);

	i = 0;
	//char **path_and_file = paths;
	//while (path_and_file[i])
	//{
		//alocate memory for each pointer in the array
	//	path_and_file[i] = (char *)malloc(strlen(paths[i]) + strlen(args[0]) + 2);
		//if(path_and_file[i] == NULL)
		//	return (-1);
		//stick each path to the input comand
		path_and_file[0] = paths[size - 1];
		strcat(path_and_file[0], "/");
		strcat(path_and_file[0], args[0]);
		//path_and_file[3] = '\0';
		//printf("the path file is: %s\n", path_and_file[0]);

		i++;
	//}
//	free(path_and_file);
//	free(paths);
	i = 0;
	
	real_cmd = path_and_file[0];
	
	while(path_and_file[i])
	{
	//printf("the path_and_file: %s\n", path_and_file[0]);

		
	//*check for the access and existence
		check = access(path_and_file[0], X_OK);
		if(check == -1)		//if it's not the file I want free its mimmory
		{
			free(path_and_file[i]);
		}
		else if(check == 0)
		{
			real_cmd = path_and_file[0];
			arg = args[0];
			args[0] = real_cmd;
			break;
		}
		i++;
	}
	//printf("the real command: %s\n", real_cmd);
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
			printf("%s: command not found\n", arg);
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
	free(paths);
	return (0);
}
