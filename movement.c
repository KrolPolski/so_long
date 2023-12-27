/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:17:00 by rboudwin          #+#    #+#             */
/*   Updated: 2023/12/27 16:46:36 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_map *map, t_img *img)
{
	if (map->grid[map->chary][map->charx - 1] != '1')
	{
		img->img_m->instances[0].x -= map->tile_sq;
		map->charx--;
		if (map->grid[map->chary][map->charx] == 'C')
			collect_chest(map, img, map->mlx);
		if (map->grid[map->chary][map->charx] == 'e')
		{
			map->moves++;
			ft_printf("Moves: %d\n", map->moves);
			ft_printf("You win!\n");
			free_grid(map, 1);
			exit(EXIT_SUCCESS);
		}
	}
	map->moves++;
	ft_printf("Moves: %d\n", map->moves);
}

void	move_right(t_map *map, t_img *img)
{
	if (map->grid[map->chary][map->charx + 1] != '1')
	{
		img->img_m->instances[0].x += map->tile_sq;
		map->charx++;
		if (map->grid[map->chary][map->charx] == 'C')
			collect_chest(map, img, map->mlx);
		if (map->grid[map->chary][map->charx] == 'e')
		{
			map->moves++;
			ft_printf("Moves: %d\n", map->moves);
			ft_printf("You win!\n");
			free_grid(map, 1);
			exit(EXIT_SUCCESS);
		}
	}
	map->moves++;
	ft_printf("Moves: %d\n", map->moves);
}

void	move_up(t_map *map, t_img *img)
{
	if (map->grid[map->chary - 1][map->charx] != '1')
	{
		img->img_m->instances[0].y -= map->tile_sq;
		map->chary--;
		if (map->grid[map->chary][map->charx] == 'C')
			collect_chest(map, img, map->mlx);
		if (map->grid[map->chary][map->charx] == 'e')
		{
			map->moves++;
			ft_printf("Moves: %d\n", map->moves);
			ft_printf("You win!\n");
			free_grid(map, 1);
			exit(EXIT_SUCCESS);
		}
	}
	map->moves++;
	ft_printf("Moves: %d\n", map->moves);
}

void	move_down(t_map *map, t_img *img)
{
	if (map->grid[map->chary + 1][map->charx] != '1')
	{
		img->img_m->instances[0].y += map->tile_sq;
		map->chary++;
		if (map->grid[map->chary][map->charx] == 'C')
			collect_chest(map, img, map->mlx);
		if (map->grid[map->chary][map->charx] == 'e')
		{
			map->moves++;
			ft_printf("Moves: %d\n", map->moves);
			ft_printf("You win!\n");
			free_grid(map, 1);
			exit(EXIT_SUCCESS);
		}
	}
	map->moves++;
	ft_printf("Moves: %d\n", map->moves);
}

void	move_player(t_map *map, t_img *img, char c)
{
	if (c == 'L')
		move_left(map, img);
	if (c == 'R')
		move_right(map, img);
	if (c == 'U')
		move_up(map, img);
	if (c == 'D')
		move_down(map, img);
}
