/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:33:38 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/16 14:36:09 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Thx to yohlee
 */

#include "get_next_line.h"
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>

char	*get_next_line(int fd);

int	main()
{
	int		ret;
	int		fd;
	char	*line;

//	fd = open("Your text", O_RDONLY);
	fd = 0;
	while ((line = get_next_line(fd)))
	{
		printf("output is %s...\n", line);
		free(line);
	}
	printf("final is %s...\n", line);
	free(line);
}
