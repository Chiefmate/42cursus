#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	char	*envp[] = {0};

	execve("/bin/ls", argv, envp);
	return (0);
}
