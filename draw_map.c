/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:26:11 by rboudwin          #+#    #+#             */
/*   Updated: 2023/12/21 15:01:42 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	determine_tile_size(t_map *map)
{
	map->tile_length = 1366 / map->line_length;
	map->tile_width = 768 / map->line_count;
	if (map->tile_length <= map->tile_width)
		map->tile_sq = map->tile_length;
	else
		map->tile_sq = map->tile_width;
	ft_printf("Tile size should be %dx%d, but square is %d\n", map->tile_length, map->tile_width, map->tile_sq);
	map->charx = map->startx;
	map->chary = map->starty;
	map->moves = 0;
	map->curr_col = 0;
}
void	draw_map(mlx_t *mlx, t_map *map, t_img *p)
{
	map->x = 0;
	map->y = 0;
	determine_tile_size(map);
	
	//p->img = mlx_new_image(mlx, 1366, 768);
	//ft_memset(p->img->pixels, 255, p->img->width * p->img->height * BPP);
	//mlx_image_to_window(mlx, p->img, 0, 0);
	p->txt_0 = mlx_load_png("./assets/tiles/floor/floor_1.png");
	p->txt_1 = mlx_load_png("./assets/tiles/wall/wall_1.png");
	p->txt_c = mlx_load_png("./assets/props_itens/chest_closed_anim_f0.png");
	p->txt_e = mlx_load_png("./assets/tiles/wall/door_closed.png");
	p->txt_p = mlx_load_png("./assets/tiles/floor/floor_2.png");
	p->txt_k = mlx_load_png("./assets/heroes/knight/knight_idle_anim_f0.png");
	p->txt_m = mlx_load_png("./assets/minotaur.png");
	p->txt_cc = mlx_load_png("./assets/props_itens/chest_open.png");
	p->img_k = mlx_texture_to_image(mlx, p->txt_k);
	p->img_0 = mlx_texture_to_image(mlx, p->txt_0);
	p->img_1 = mlx_texture_to_image(mlx, p->txt_1);
	p->img_c = mlx_texture_to_image(mlx, p->txt_c);
	p->img_e = mlx_texture_to_image(mlx, p->txt_e);
	p->img_p = mlx_texture_to_image(mlx, p->txt_p);
	p->img_m = mlx_texture_to_image(mlx, p->txt_m);
	p->img_cc = mlx_texture_to_image(mlx, p->txt_cc);
	mlx_resize_image(p->img_k, map->tile_sq, map->tile_sq);
	mlx_resize_image(p->img_0, map->tile_sq, map->tile_sq);
	mlx_resize_image(p->img_1, map->tile_sq, map->tile_sq);
	mlx_resize_image(p->img_c, map->tile_sq, map->tile_sq);
	mlx_resize_image(p->img_cc, map->tile_sq, map->tile_sq);
	mlx_resize_image(p->img_e, map->tile_sq, map->tile_sq);
	mlx_resize_image(p->img_p, map->tile_sq, map->tile_sq);
	mlx_resize_image(p->img_m, map->tile_sq, map->tile_sq);
	ft_printf("We are about to draw the map\n");
	while (map->grid[map->y] != NULL)
	{
		while (map->grid[map->y][map->x] != '\0')
		{
			if (map->grid[map->y][map->x] == '0')
				mlx_image_to_window(mlx, p->img_0, map->x * map->tile_sq, map->y * map->tile_sq);
			else if (map->grid[map->y][map->x] == '1')
				mlx_image_to_window(mlx, p->img_1, map->x * map->tile_sq, map->y * map->tile_sq);
			else if (map->grid[map->y][map->x] == 'C')
				mlx_image_to_window(mlx, p->img_c, map->x * map->tile_sq, map->y * map->tile_sq);
			else if (map->grid[map->y][map->x] == 'E')
				mlx_image_to_window(mlx, p->img_e, map->x * map->tile_sq, map->y * map->tile_sq);
			else if (map->grid[map->y][map->x] == 'P')
			{
				mlx_image_to_window(mlx, p->img_p, map->x * map->tile_sq, map->y * map->tile_sq);
			}
			map->x++;
		}
		map->y++;
		map->x = 0;
	}
	mlx_image_to_window(mlx, p->img_m, map->charx * map->tile_sq, map->chary * map->tile_sq);
//	mlx_resize_image(p->img_k, map->tile_sq, map->tile_sq);
//	mlx_image_to_window(mlx, p->img_k, 150, 150);
//	mlx_image_to_window(mlx, p->img_k, 800, 500);
//	ft_printf("%s", map->grid[0]);
}
