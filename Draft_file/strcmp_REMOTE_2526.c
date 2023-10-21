#include "shell.h"

/**
  *_strcmp - compare tow string
  *@s1:the first string
  *@s2: the second string
  *Return: 0if there equal less than zero if s1 less than s2
  grater than 0 if s1 grater
  */

int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return (0);

		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
