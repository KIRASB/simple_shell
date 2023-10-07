#include "main.h"

/**
  *main - print all argument in main 
  *@ac:the number of argument
  *@av:the value of argument
  *Return:nothing
  */

int main(int ac __attribute__ ((unused)), char **av)
{
	int i = 1;

	if (!av)
		return (0);

	while (av[i])
	{
		printf("%s ", av[i]);
		i++;
	}
}
