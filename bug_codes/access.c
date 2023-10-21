#include "shell.h"
/**
 * check_access - this function check if a file exits or not
 * @path_and_file: list of arrays of propably paths
 * Return: the path if the file exist and NULL of it doesn't
 */
char *check_access(char **path_and_file)
{
	int i = 0;
	int check;
	char *good_path;

	while(path_and_file[i] != NULL)
	{
		check = access(path_and_file[i], F_OK);
		if(check == 0)
		{
			good_path = path_and_file[i];
			break;
		}
		else
		{
			free(path_and_file[i]);
		}
		i++;
	}
	return (good_path);
	while(path_and_file[i] != NULL)
	{
		free(path_and_file[i]);
		i++;
	}
	free(path_and_file);
	printf("good path is:%s\n", good_path);
	
}
