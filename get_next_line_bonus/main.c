#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int	fd;
	char	*str;

	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	close(fd);
	return (0);
}
