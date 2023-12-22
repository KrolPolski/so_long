/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:17:00 by rboudwin          #+#    #+#             */
/*   Updated: 2023/12/22 09:57:06 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collect_chest(t_map *map, t_img *img, mlx_t *mlx)
{
	ft_printf("Before collection we have %d \n", map->curr_col);
	map->curr_col++;
	ft_printf("You now have %d/%d chests\n", map->curr_col, map->collectibles);
	mlx_image_to_window(mlx, img->img_cc,
		map->charx * map->tile_sq, map->chary * map->tile_sq);
	map->grid[map->chary][map->charx] = '0';
	if (map->curr_col == map->collectibles)
	{
		map->grid[map->exity][map->exitx] = 'e';
		mlx_delete_image(mlx, img->img_e);
		mlx_image_to_window(mlx, img->img_eo,
			map->exitx * map->tile_sq, map->exity * map->tile_sq);
	}
	mlx_delete_image(mlx, img->img_m);
	img->img_m = mlx_texture_to_image(mlx, img->txt_m);
	mlx_resize_image(img->img_m, map->tile_sq, map->tile_sq);
	mlx_image_to_window(mlx, img->img_m,
		map->charx * map->tile_sq, map->chary * map->tile_sq);
}

void	move_player(t_map *map, t_img *img, char c)
{
	if (c == 'L')
	{
		if (map->grid[map->chary][map->charx - 1] != '1')
		{
			img->img_m->instances[0].x -= map->tile_sq;
			map->charx--;
			if (map->grid[map->chary][map->charx] == 'C')
				collect_chest(map, img, map->mlx);
			if (map->grid[map->chary][map->charx] == 'e')
			{
			//	mlx_image_to_window(map->mlx, img->img_win, 
			// map->tile_sq * 0.5 * map->line_length, 
			// map->tile_sq *0.3 * map->line_count);
				ft_printf("You win!\n");
			}
		}
		map->moves++;
		ft_printf("Moves: %d\n", map->moves);
	}
	if (c == 'R')
	{
		if (map->grid[map->chary][map->charx + 1] != '1')
		{
			img->img_m->instances[0].x += map->tile_sq;
			map->charx++;
			if (map->grid[map->chary][map->charx] == 'C')
				collect_chest(map, img, map->mlx);
			if (map->grid[map->chary][map->charx] == 'e')
				ft_printf("You win!\n");
		}
		map->moves++;
		ft_printf("Moves: %d\n", map->moves);
	}
	if (c == 'U')
	{
		if (map->grid[map->chary - 1][map->charx] != '1')
		{
			img->img_m->instances[0].y -= map->tile_sq;
			map->chary--;
			if (map->grid[map->chary][map->charx] == 'C')
				collect_chest(map, img, map->mlx);
			if (map->grid[map->chary][map->charx] == 'e')
				ft_printf("You win!\n");
		}
		map->moves++;
		ft_printf("Moves: %d\n", map->moves);
	}
	if (c == 'D')
	{
		if (map->grid[map->chary + 1][map->charx] != '1')
		{
			img->img_m->instances[0].y += map->tile_sq;
			map->chary++;
			if (map->grid[map->chary][map->charx] == 'C')
				collect_chest(map, img, map->mlx);
			if (map->grid[map->chary][map->charx] == 'e')
				ft_printf("You win!\n");
		}
		map->moves++;
		ft_printf("Moves: %d\n", map->moves);
	}
}
