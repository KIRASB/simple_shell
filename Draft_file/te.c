#include "main.h"

int execute(char **args) {
    char *allpaths = NULL;
    char **paths = NULL;
    char **path_and_file = NULL;
    char *real_cmd = NULL;
    int i = 0;
    int size = 0;
    int check;
    int status;
    pid_t pid;
    char **copy;

    // Allocate and copy the 'args' array
    copy = (char **)malloc(sizeof(char *) * (i + 1));
    while (args[i] != NULL) {
        copy[i] = strdup(args[i]);
        i++;
        copy = (char **)realloc(copy, sizeof(char *) * (i + 1));
    }
    copy[i] = NULL;

    allpaths = getenv("PATH");
    printf("1 %s %s\n", copy[0], copy[1]);
    paths = token_it(allpaths, ":\t\n");

    size = 0;
    while (paths[size]) {
        size++;
    }

    // Allocate memory for the 'path_and_file' array
    path_and_file = (char **)malloc(sizeof(char *) * (size + 1));
    if (path_and_file == NULL) {
        // Handle malloc failure
        return (-1);
    }

    // Initialize 'real_cmd' to NULL
    real_cmd = NULL;

    i = 0;
    while (paths[i] != NULL && i < size && copy[0][0] != '/') {
        path_and_file[i] = (char *)malloc(strlen(paths[i]) + strlen(copy[0]) + 2);
        if (path_and_file[i] == NULL) {
            // Handle malloc failure
            return (-1);
        }
        strcat(path_and_file[i], paths[i]);
        strcat(path_and_file[i], "/");
        strcat(path_and_file[i], copy[0]);
        i++;
    }

    if (copy[0][0] == '/') {
        path_and_file[0] = strdup(copy[0]);
    }

    i = 0;
    while (path_and_file[i] != NULL && i < size) {
        check = access(path_and_file[i], X_OK);
        if (check == -1) {
            free(path_and_file[i]);  // Free memory for unused paths
            i++;
            continue;
        }
        if (check == 0) {
            real_cmd = path_and_file[i];
            printf("path ------>>> %s\n", real_cmd);
            break;
        }
        i++;
    }

    if (real_cmd != NULL) {
        // Execute the command
        pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        if (pid == 0) {
            check = execve(real_cmd, copy, NULL);
            if (check == -1) {
                printf("%s: command not found\n", copy[0]);
                exit(EXIT_FAILURE);
            }
            if (check == 0) {
                exit(EXIT_SUCCESS);
            }
        } else {
            wait(&status);
        }
    } else {
        printf("%s: command not found\n", copy[0]);
    }

    // Free memory for 'path_and_file'
    for (int j = 0; j < size; j++) {
        free(path_and_file[j]);
    }
    free(path_and_file);

    // Free memory for 'copy' and 'paths'
    for (int j = 0; copy[j] != NULL; j++) {
        free(copy[j]);
    }
    free(copy);

    // You should not free 'real_cmd' here, as it still points to a valid path

    return 0;
}

