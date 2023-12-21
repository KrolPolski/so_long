/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:17:00 by rboudwin          #+#    #+#             */
/*   Updated: 2023/12/21 14:31:30 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	move_player(t_map *map, t_img *img, char c)
{
	if (img)
		if (map)
		ft_printf("We managed to ignore CCC unused paramater warnings\n");
	ft_printf("We are running move_player with '%c' as a parameter\n", c);
	if (c == 'L')
	{
		ft_printf("We detected intention to move left\n");//from x:%d and width of %d\n", map->charx, img->img->width);
		ft_printf("Before moving our current position is y:%d x:%d\n", map->chary, map->charx);
		if (map->grid[map->chary][map->charx - 1] != '1')
		{
			img->img_m->instances[0].x -= map->tile_sq;
			map->charx--;
		}
		map->moves++;
		ft_printf("Moves: %d\n", map->moves);
	}
	if (c == 'R')
	{
		ft_printf("We detected intention to move right\n");
		if (map->grid[map->chary][map->charx + 1] != '1')
		{
		img->img_m->instances[0].x += map->tile_sq;
		map->charx++;
		}
		map->moves++;
		ft_printf("Moves: %d\n", map->moves);
	}
	if (c == 'U')
	{
		ft_printf("We detected intention to move up\n");
		if (map->grid[map->chary - 1][map->charx] != '1')
		{img->img_m->instances[0].y -= map->tile_sq;
		map->chary--;
		}
		map->moves++;
		ft_printf("Moves: %d\n", map->moves);
	}
	if (c == 'D')
	{
		ft_printf("We detected intention to move down\n");
		if (map->grid[map->chary + 1][map->charx] != '1')
		{img->img_m->instances[0].y += map->tile_sq;
		map->chary++;}
		map->moves++;
		ft_printf("Moves: %d\n", map->moves);
	}
}
