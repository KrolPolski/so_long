/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adv_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:46:53 by rboudwin          #+#    #+#             */
/*   Updated: 2023/12/22 10:35:20 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_exits_etc(t_map *map)
{
	map->x = 0;
	map->y = 0;
	map->starts = 0;
	map->exits = 0;
	map->collectibles = 0;
	while (map->grid[map->y] != NULL)
	{
		while (map->grid[map->y][map->x] != '\0')
		{
			if (map->grid[map->y][map->x] == 'P')
			{
				(map->starts)++;
				map->starty = map->y;
				map->startx = map->x;
			}
			else if (map->grid[map->y][map->x] == 'C')
				(map->collectibles)++;
			else if (map->grid[map->y][map->x] == 'E')
			{
				(map->exits)++;
				map->exitx = map->x;
				map->exity = map->y;
			}
			else if (!ft_strchr("10CEP", map->grid[map->y][map->x]))
			{
				ft_printf("ERROR: Invalid character detected in map\n");
				return (0);
			}
			map->x++;
		}
		map->x = 0;
		map->y++;
	}
	ft_printf("starts %d exits %d collectibles %d\n",
		map->starts, map->exits, map->collectibles);
	if (map->starts != 1 || map->exits != 1 || map->collectibles <= 0)
	{
		ft_printf("ERROR: Invalid map- starts: %d exits: %d collectibles: %d\n",
			map->starts, map->exits, map->collectibles);
		ft_printf("You must have exactly one start, one exit");
		ft_printf(" and at least one collectible\n");
		return (0);
	}
	return (1);
}

int	check_borders(t_map *map)
{
	map->x = 0;
	map->y = 0;
	while (map->grid[0][map->x] != '\0')
	{
		if (map->grid[0][map->x] != '1')
			return (0);
		(map->x)++;
	}
	map->y++;
	map->x = 0;
	while (map->y < map->line_count - 1)
	{
		if (map->grid[map->y][0] != '1'
			|| map->grid[map->y][map->line_length - 1] != '1')
			return (0);
		map->y++;
	}
	while (map->grid[map->line_count - 1][map->x] != '\0')
	{
		if (map->grid[map->line_count - 1][map->x] != '1')
			return (0);
		map->x++;
	}
	return (1);
}
