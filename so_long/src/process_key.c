
#include "so_long.h"

void	process_w(t_map *map, t_game *game)
{
	int	i;

	i = -1;
	while (++i < ft_strlen(map->info))
	{
		if (map->info[i] == 'P')
			break ;
	}
	if (map->info[i - map->width] == 'C')
		game->playerpos.y++;
	
	
}