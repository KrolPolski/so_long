/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:06:56 by rboudwin          #+#    #+#             */
/*   Updated: 2023/12/20 15:35:12 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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