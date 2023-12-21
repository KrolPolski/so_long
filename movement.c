/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:17:00 by rboudwin          #+#    #+#             */
/*   Updated: 2023/12/21 16:01:59 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collect_chest(t_map *map, t_img *img, mlx_t *mlx)
{
	ft_printf("Before collection we have %d \n",map->curr_col);
	map->curr_col++;
	ft_printf("You now have %d/%d chests\n", map->curr_col, map->collectibles);
	mlx_image_to_window(mlx, img->img_cc, map->charx * map->tile_sq, map->chary * map->tile_sq);
	map->grid[map->chary][map->charx] = '0';
	printf("Depth before was %d\n and depth of first chest is %d\n", img->img_m->instances[0].z, img->img_cc->instances[0].z);
	mlx_delete_image(mlx, img->img_m);
	img->img_m = mlx_texture_to_image(mlx, img->txt_m);
	mlx_resize_image(img->img_m, map->tile_sq, map->tile_sq);
	mlx_image_to_window(mlx, img->img_m, map->charx * map->tile_sq, map->chary * map->tile_sq);
}
void	move_player(t_map *map, t_img *img, char c)
{
	
	//ft_printf("We are running move_player with '%c' as a parameter\n", c);
	if (c == 'L')
	{
		ft_printf("We detected intention to move left\n");//from x:%d and width of %d\n", map->charx, img->img->width);
		ft_printf("Before moving our current position is y:%d x:%d\n", map->chary, map->charx);
		if (map->grid[map->chary][map->charx - 1] != '1')
		{
			img->img_m->instances[0].x -= map->tile_sq;
			map->charx--;
			if(map->grid[map->chary][map->charx] == 'C')
				collect_chest(map, img, map->mlx);
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
		if(map->grid[map->chary][map->charx] == 'C')
				collect_chest(map, img, map->mlx);
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
		if(map->grid[map->chary][map->charx] == 'C')
				collect_chest(map, img, map->mlx);
		}
		map->moves++;
		ft_printf("Moves: %d\n", map->moves);
	}
	if (c == 'D')
	{
		ft_printf("We detected intention to move down\n");
		if (map->grid[map->chary + 1][map->charx] != '1')
		{
			img->img_m->instances[0].y += map->tile_sq;
			map->chary++;
			if(map->grid[map->chary][map->charx] == 'C')
				collect_chest(map, img, map->mlx);
		}
		map->moves++;
		ft_printf("Moves: %d\n", map->moves);
	}
}
