#include "shell.h"

/**
  *_strlen - calculate the string length
  *@str: the string want to calculate
  *Return: the number of byte
  */

int _strlen(char *str)
{
	int len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

