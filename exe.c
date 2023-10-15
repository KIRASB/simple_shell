#include "main.h"

int execute(char *args)
{
	char *const ar[] = {"-l", NULL};
	char *allpaths = NULL;
	char **paths = NULL;
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
		size++;
	}
	
	//alocate memory for the array
	path_and_file = (char **)malloc(sizeof(char *) * (size + 4));
	if (path_and_file == NULL)
		return (-1);

		//alocate memory for each pointer in the array
		path_and_file[0] = (char *)malloc(strlen(paths[i]) + strlen(args) + 2);
		
		if(path_and_file[0] == NULL)
			return (-1);
		
		//stick each path to the input comand
		path_and_file[0] = paths[size - 1];
		strcat(path_and_file[0], "/");
		strcat(path_and_file[0], args);
		//path_and_file[3] = '\0';
	//	printf("the path file is: %s\n", path_and_file[0]);

	
	free(paths);
	
	i = 0;
	
	real_cmd = path_and_file[0];
	
	while(path_and_file[i])
	{	
	//*check for the access and existence
		check = access(path_and_file[0], X_OK);
		if(check == -1)		//if it's not the file I want free its mimmory
		{
			free(path_and_file[i]);
			i++;
			continue;
		}
		if(check == 0)
		{
			real_cmd = path_and_file[0];
			break;
		}
		i++;
	}
	//printf("the real command: %s\n", real_cmd);
	//free the memory of the array

	free(path_and_file);
	free(path_and_file[0]);
	//executing process
	pid = fork();
	if(pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if(pid == 0)
	{
		check = execve(real_cmd, ar, NULL);
		if(check == -1)
		{
			printf("%s: command not found\n", args);
			exit(EXIT_FAILURE);
			free(real_cmd);
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

