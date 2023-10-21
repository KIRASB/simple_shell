#include "shell.h"
/**
 * execute - take the commadn and execute it
 * @args: input commands
 * Return: 0
 */
int execute(char **args)
{
	char *allpaths = NULL;
	char **paths = NULL;
	char **path_and_file = NULL;
	char *real_cmd = NULL;
	ssize_t w_err1, w_err2;
	int  i = 0;
	int size = 0;
	int check;
	int status;
	pid_t pid;

	printf("still working 1\n");

<<<<<<< HEAD
	path_and_file = get_files(args, ":\n\t");
	real_cmd = check_access(path_and_file);
	printf("still working for acess\n");
	check = access(real_cmd, X_OK);
	if(real_cmd == NULL)
=======
	i = 0;
	while (paths[i] != NULL && i < size && copy[0][0] != '/')
	{
		path_and_file[i] = (char *)malloc(strlen(paths[i]) + _strlen(copy[0]) + 2);
		if(path_and_file[i] == NULL)
			return (-1);

		_strcat(path_and_file[i], paths[i]);
		_strcat(path_and_file[i], "/");
		_strcat(path_and_file[i], copy[0]);
		i++;
	}
	if(copy[0][0] == '/')
	{
		path_and_file[0] = _strdup(copy[0]);
	}
	i = 0;
	while(path_and_file[i] != NULL && i < size)
>>>>>>> bb8c18f0fbe4ee20d8284d0b9780af366a9d4089
	{
		printf("not here\n");
		w_err1 = write(1, args[0], _strlen(args[0]));
		w_err2 = write(1, ": is not found\n", 15);
		if(w_err1 == -1 || w_err2 == -1)
		{
			perror("write");
			return (1);
		}
	}
	else if(real_cmd != NULL && check != 0)
	{
		printf("here\n");
		w_err1 = write(1, args[0], _strlen(args[0]));
		w_err2 = write(1, ": is not found\n", 15);
		if(w_err1 == -1 || w_err2 == -1)
		{
			perror("write");
			return (1);
		}
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
		free(real_cmd);
	}
	return (0);
}
