#include "main.h"

int main(void)
{
	char *input;
	int len;
	size_t value;

	while(1)
	{
		//show the prompt
		write(1, "$ ", 2);
		value = getline(&input, &len, stdin);

