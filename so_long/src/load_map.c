/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 20:34:47 by hyunhole          #+#    #+#             */
/*   Updated: 2022/06/27 21:00:53 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_strndup(char *src, int size);
static char	*add_line_info(char *info, char *line);

static char	*add_line_info(char *info, char *line)
{
	char			*ret;
	unsigned int	len;

	if (!info && !line)
		return (NULL);
	else if (!info)
		return (ft_strndup(line, ft_strlen(line)));
	else if (!line)
		return (info);
	len = ft_strlen(info) + ft_strlen(line);
	ret = (char *)malloc(len);
	if (!ret)
		return (NULL);
	ft_memcpy(ret, info, ft_strlen(info));
	ft_memcpy(ret + ft_strlen(info), line, ft_strlen(line) - 1);
	ret[len - 1] = '\0';
	free(info);
	free(line);
	return (ret);
}

/* duplicate the src string with at most 'size - 1' chars */
static char	*ft_strndup(char *src, int size)
{
	char	*ret;

	ret = (char *)malloc(size);
	if (!ret)
		return (NULL);
	ft_memcpy(ret, src, size - 1);
	ret[size - 1] = '\0';
	return (ret);
}

void	load_map(char *filename, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	map->height = 0;
	map->width = ft_strlen(line) - 1;
	map->info = ft_strndup(line, ft_strlen(line));
	free(line);
	while (line)
	{
		map->height += 1;
		line = get_next_line(fd);
		if (line)
			map->info = add_line_info(map->info, line);
	}
	close(fd);
	return ;
}
