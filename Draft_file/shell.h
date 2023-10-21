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

int _strlen(char *str);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *_strcat(char *s1, char *s2);
int get_env();
char **get_files(char **copy, char *del);
char *check_access(char **path_and_file);
char **token_it(char *ptr, char *del);
int execute(char **args);

#endif
