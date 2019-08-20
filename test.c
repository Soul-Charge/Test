#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    pid_t pid;
    FILE * fp;

    if (NULL == (fp = fopen("test.txt", "r")))
    {
        fprintf(stderr, "Can't open test.txt\n");
        exit(1);
    }

    pid = fork();
    if (!pid)
    {
        dup2(fileno(fp), 1); // redirect stdout to test.txt
        execl("~/Test/test/out", "~/Test/test/out", NULL);
    }

    return 0;
}
