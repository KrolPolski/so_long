/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adv_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:46:53 by rboudwin          #+#    #+#             */
/*   Updated: 2023/12/20 11:39:30 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_borders(t_map *map)
{
	//ft_printf("Hello advanced validator baby\n");
	map->x = 0;
	map->y = 0;
	while (map->grid[0][map->x] != '\0')
	{
		//ft_printf("We are trying to check the first line\n");
		if (map->grid[0][map->x] != '1')
			return (0);
		(map->x)++;
	}
	map->y++;
	map->x = 0;
	while (map->y < map->line_count - 1)
	{
		if (map->grid[map->y][0] != '1' || map->grid[map->y][map->line_length - 1] != '1')
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
