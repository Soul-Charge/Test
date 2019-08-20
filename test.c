#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    pid_t pid;
    int i;

    puts("father:starts");
    pid = fork();
    if (!pid)
    {
    for (i = 0; i < 500; i++)
        printf("%d ", i);
    }
    puts("father:end");

    return 0;
}
