#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    pid_t pid;

    pid = fork();

    if (pid == -1)
    {
        printf("fork() error");
        exit(1);
    }
    if (pid == 0)
    {
        printf("\n****자식프로세스****\n");
        printf("변수pid값: %d\n", pid);
        printf("자식피드: %d\n", getpid());
    }
    else
    {
        printf("\n****부모프로세스****\n");
        printf("변수pid값: %d\n", pid);
        printf("부모피드: %d\n", getpid());
    }
    return (0);
}
