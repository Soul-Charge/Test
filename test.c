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
        puts("I am child");
        fprintf(fp, "child: can I write the file?\n"); //check the child whether have the stream of test.txt
        if (-1 == dup2(fileno(fp), 1)) // redirect stdout to test.txt
        {
            fprintf(stderr, "can't redirect stdout.\n");
        }
        else
            puts("redirect stdout success.");

        if (-1 == execl("~/Test/test/out", "~/Test/test/out", NULL))
            fprintf(stderr, "can't execute out");
        else
            puts("I had executed the out!");
    }
    fclose(fp);

    return 0;
}
