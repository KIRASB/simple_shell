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
	
	if(i == 0)
		get_env();

	toke_cmd = token_it(cmd, " ");
	execute(toke_cmd);
	}
return (0);
}
