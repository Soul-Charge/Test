#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char * argv[])
{
    FILE * my_file;
    int descriptor;
    int i;

    if ((my_file = fopen("test.txt", "w")))
    {
        fprintf(stderr, "Can't open test.txt\n");
        exit(1);
    }
    descriptor = fileno(my_file);

    if (argc > 1)
        dup2(descriptor, 1); //将标准输出重定向至my_file指向的文件

    printf("--- print some number ---\n");
    printf("*** run with any arguments will output to file:\"test.txt\" ***\n");
    for (i = 0; i < 10; i++)
    printf("  %d", i);

    return 0;
}
