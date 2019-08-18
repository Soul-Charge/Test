#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    char str[] = "for test.";
    int a = 10;

    puts("test1");
    puts(str);
    printf("a = %d", a);

    fork();
    puts(str);
    printf("a = %d", a);

    puts("test2");
    puts("test3");
    system("pause");
    return 0;
}
