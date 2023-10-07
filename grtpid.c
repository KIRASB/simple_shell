#include "main.h"
#include <unistd.h>
#include <sys/types.h>

int main(int arc, char **ac)
{
printf("%d\n %d\n", getppid(), getpid());
}
