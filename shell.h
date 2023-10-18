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

<<<<<<< HEAD:main.h
/** protoypes */

int get_env();
char get_line();
char *get_cmd();
=======
int get_env();
>>>>>>> 30d6e11055a9a866b2334fe35035b769176a748d:shell.h
char **token_it(char *ptr, char *del);
int execute(char **args);

#endif
