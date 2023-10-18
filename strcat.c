#include "shell.h"

/**
  *_strcat - copy the string from s2 and appen it to s1
  *@S1:the first string
  *@s2: the second string
  *Return: the appended string
  */

char *_strcat(char *s1, char *s2)
{
	int i, j;

	i = 0;
	j = 0;


	while (s1[i] != '\0')
		i++;	
	
	while(s2[j] != '\0')
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	
	s1[i] = '\0';

	return (s1);
}

