#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int i;
    pid_t pid;

    puts("I am father");
    
    for (i = 0; i < 10; i++)
    {
        pid = fork();
        if (!pid)
            printf("I am child %d\n", i);
    }
    return 0;
}
