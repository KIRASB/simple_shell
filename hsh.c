#include "main.h"

int main()
{
	char *cmd;
	char **toke_cmd;
	char *ex = "exit";
	char *en = "env";
	int i, j = 0;

	while(1)
	{
	cmd = get_cmd();
	
	i = strcmp(cmd, ex);
	if (i == 0)
	{
		printf("exit\n\n[Disconnect...\n]");
		exit(EXIT_FAILURE);
	}
	i = 0;
	i = strcmp(cmd, en);
	
	else if(i == 0)
		get_env();

	else
	{
		toke_cmd = token_it(cmd, " \n\t");
		execute(toke_cmd);
	}
	free(cmd);
return (0);
}
