#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    pid_t	pid;
	pid_t	wait_res;
	int		status;

    pid = fork();

    if (pid == -1)
    {
        printf("fork() error");
        exit(1);
    }
	if (pid == 0)
	{
		printf("\n****자식프로세스****\n");
		sleep(2);
		printf("자식프로세스 종료\n");
	}
	else
	{
		wait_res = wait(&status);
		printf("\n****부모프로세스****\n");
		sleep(1);
		printf("부모프로세스 종료\n");
		printf("wait인자값: %d\nwait반환값: %d\n", status, wait_res);
		printf("자식pid: %d\n", pid);	
	}
    return (0);
}
