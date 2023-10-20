#include "shell.h"
/**
 * get_files - take the command and stick it to all paths
 * @copy: the command
 * @del: the delimiter
 * Return: array of the paths with the command
 */
char **get_files(char **copy, char *del)
{
	int size = 0;
	int i;
	char **path_and_file;
	char **paths = NULL;
	char *allpaths = NULL;

	allpaths = getenv("PATH");
	paths = token_it(allpaths, del);
	 while(paths[size])
	 {
		 size++;
	 }
	 path_and_file = (char **)malloc(sizeof(char *) * (size + 2));
	 if (path_and_file == NULL)
		 return (NULL);
	 i = 0;
	 
	 while (paths[i] != NULL && i < size && copy[0][0] != '/')
	 {
		 path_and_file[i] = (char *)malloc(_strlen(paths[i]) + _strlen(copy[0]) + 2);
		 if(path_and_file[i] == NULL)
			 return (NULL);
		 _strcat(path_and_file[i], paths[i]);
		 _strcat(path_and_file[i], "/");
		 _strcat(path_and_file[i], copy[0]);
		 printf("%s\n", path_and_file[i]);
	 	i++;
	 }
	 printf("I am working 3");
	 if(copy[0][0] == '/')
		 path_and_file[0] = _strdup(copy[0]);
	 return (path_and_file);
}
