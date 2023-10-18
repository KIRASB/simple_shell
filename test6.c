#include "main.h"

char *execute(char **args)
{
        char *allpaths = NULL;
        char *path = NULL;
        char **paths = NULL;
        char **path_and_file = NULL;
        char *real_cmd = NULL;
        pid_t cpid, pid;
        int statu;
        int check,i = 0;
	int size = 0;

        allpaths = getenv("PATH");
        paths = token_it(allpaths, ":\n\t");
	while(paths[size])
	{
		size++;
	}

	path_and_file = (char **)malloc(sizeof(char *) * (size + 1));
	if (path_and_file == NULL)
		return (NULL);

	while (paths[i])
        {
		path_and_file[i] = (char *)malloc(strlen(paths[i]) + strlen(args[0]) + 2);
		if(path_and_file[i] == NULL)
			return(NULL);
		strcpy(path_and_file[i], paths[i]);
		strcat(path_and_file[i], "/");
		strcat(path_and_file[i], args[0]);
                i++;
		printf("%s\n", path_and_file[i]);
        }
        i = 0;
        while(path_and_file[i] != NULL)
        {
                check = access(path_and_file[i], X_OK);
                i++;
                if (check == -1)
                        continue;

                if(check == 0)
		{
			real_cmd = path_and_file[i];
                        break;
		}
        }
	return real_cmd;

}
int main(void)
{
	int i = 0;
	char *path;
	char **av = (char **)malloc(sizeof(char *));
	av[0] = (char *)malloc(sizeof("ls"));
	av[0] = "ls";

	path = execute(av);
	printf("%s\n", path);
	free(av[0]);
	free(av);
	free(path);
	return 0;
}
