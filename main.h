#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/** protoypes */

int get_env();
char get_line();
char *get_cmd();
char **token_it(char *ptr, char *del);
int execute(char **args);

#endif
