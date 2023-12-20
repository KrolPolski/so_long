/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:06:56 by rboudwin          #+#    #+#             */
/*   Updated: 2023/12/20 12:15:54 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_grid(t_map *map)
{
	map->y = 0;
	while (map->grid[map->y] != NULL)
	{
		free(map->grid[map->y]);
		map->y++;
	}
	free(map->grid);
}