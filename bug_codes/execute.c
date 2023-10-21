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


	path_and_file = get_files(args, ":\n\t");
	printf("the real cmd: %s\n", real_cmd);
	real_cmd = check_access(path_and_file);
	 printf("the real cmd: %s\n", real_cmd);
	check = access(real_cmd, X_OK);
	if(real_cmd == NULL)
	{
		//printf("not here\n");
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
		//printf("here\n");
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
