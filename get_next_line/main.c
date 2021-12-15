/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:33:38 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/15 21:26:18 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Thx to yohlee
 */

#include "get_next_line.h"
#include <fcntl.h>
#include <limits.h>

char	*get_next_line(int fd);

int	main()
{
	int		ret;
	int		fd;
	char	*line;

	fd = open("Your text", O_RDONLY);
	while (line = get_next_line(fd))
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
}
