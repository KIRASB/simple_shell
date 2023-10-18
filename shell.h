#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/wait.h>

/** protoypes */

char *_strcat(char *s1, char *s2);
int get_env();
char **token_it(char *ptr, char *del);
int execute(char **args);

#endif
