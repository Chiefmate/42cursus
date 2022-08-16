
/* https://bigpel66.oopy.io/library/42/inner-circle/8#6e97c45fe04c4adea6b65375bc71b72d */

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int	main()
{
	pid_t	pid1;
	pid_t	pid2;
	pid_t	ret;
	int		status;

	pid1 = fork();
	if (pid1 == -1)
		return (1);
	else if (!pid1)
	{
		/* 1st child */
		usleep(50000);
		printf("Child1: I am the 1st Child\n");
		return (2);
	}
	else
	{
		pid2 = fork();
		if (pid2 == -1)
			return (1);
		else if (!pid2)
		{
			usleep(49000);
			printf("Child2: I am the 2nd Child\n");
			return (3);
		}
		else
		{
			/* Parent process */
			printf("Parent: I have 2 Children\n");
			ret = waitpid(pid1, &status, 0);
			printf("Parent: Successfully got status from %d Child\n", ret);
			printf("Parent: Exit Code is %d, Signal is %d\n", WEXITSTATUS(status), WTERMSIG(status));
			ret = waitpid(pid2, &status, 0);
			printf("Parent: Successfully got status from %d Child\n", ret);
			printf("Parent: Exit Code is %d, Signal is %d\n", WEXITSTATUS(status), WTERMSIG(status));
		}
	}

	return (0);
}