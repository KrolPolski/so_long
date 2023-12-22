/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:06:56 by rboudwin          #+#    #+#             */
/*   Updated: 2023/12/22 11:10:31 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	report_map_count_error(t_map *map)
{
	ft_printf("ERROR: Invalid map- starts: %d exits: %d collectibles: %d\n",
	map->starts, map->exits, map->collectibles);
	ft_printf("You must have exactly one start, one exit");
	ft_printf(" and at least one collectible\n");
	return (0);
}

void	free_grid(t_map *map, int flag)
{
	if (flag == 1)
	{
		map->y = 0;
		while (map->grid[map->y] != NULL)
		{
			free(map->grid[map->y]);
			map->y++;
		}
		free(map->grid);
	}
	if (flag == 2)
	{
		map->y = 0;
		while (map->grid2[map->y] != NULL)
		{
			free(map->grid2[map->y]);
			map->y++;
		}
		free(map->grid2);
	}
}
