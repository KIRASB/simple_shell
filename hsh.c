#include "main.h"

int main()
{
	char *cmd;
	char **toke_cmd;
	int i;

	while(1)
	{
	cmd = get_cmd();
	toke_cmd = token_it(cmd, " ");
	printf("%s\n %s\n %s\n", toke_cmd[0], toke_cmd[1], toke_cmd[2]);
	}
return 0;
}
