#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int catch_signal(int sig, void (*handler)(int));

int main(void)
{
    int i;
    
    catch_signal(SIGINT, SIG_IGN);
    for (i = 0; i < 1000; i++)
        printf("%d ", i);
    return 0;
}

/* 将函数设置为给定信号的处理器 */
/* 调用方式: catch_signal(要处理的信号, 用来处理的函数名); */
int catch_signal(int sig, void (*handler)(int))
{
    struct sigaction action;
    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    return sigaction(sig, &action, NULL);
}