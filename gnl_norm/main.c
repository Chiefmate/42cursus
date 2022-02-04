/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:40:30 by hyunhole          #+#    #+#             */
/*   Updated: 2022/01/17 16:40:30 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int main(void)
{
	int	fd;

	fd = open("in1", O_RDONLY);
	if (fd < 0)
		return (0);
	printf("%s\n", get_next_line(0));
	printf("%s\n", get_next_line(0));
	printf("%s\n", get_next_line(0));
	printf("%s\n", get_next_line(0));
	printf("%s\n", get_next_line(0));

	close(fd);
	return (0);
}