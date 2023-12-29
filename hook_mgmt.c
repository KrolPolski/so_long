/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mgmt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:56:38 by rboudwin          #+#    #+#             */
/*   Updated: 2023/12/29 09:49:30 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		free_grid(map, 1);
		exit(EXIT_SUCCESS);
	}
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& (keydata.action == MLX_PRESS))
		move_player(map, map->img, 'U');
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& keydata.action == MLX_PRESS)
		move_player(map, map->img, 'L');
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& keydata.action == MLX_PRESS)
		move_player(map, map->img, 'D');
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action == MLX_PRESS)
		move_player(map, map->img, 'R');
}

void alt_manage_images(mlx_t *mlx, t_map *map, t_img *p)
{
	map->x = 0;
	map->y = 0;
	determine_tile_size(map);
	mlx_delete_image(mlx, p->img);
	mlx_delete_image(mlx, p->img_k);
	mlx_delete_image(mlx, p->img_0);
	mlx_delete_image(mlx, p->img_1);
	mlx_delete_image(mlx, p->img_c);
	mlx_delete_image(mlx, p->img_cc);
	mlx_delete_image(mlx, p->img_e);
	mlx_delete_image(mlx, p->img_p);
	mlx_delete_image(mlx, p->img_m);
	mlx_delete_image(mlx, p->img_eo);
	p->img = mlx_new_image(mlx, map->window_width, map->window_height);
	ft_memset(p->img->pixels, 150, p->img->width * p->img->height * BPP);
	mlx_image_to_window(mlx, p->img, 0, 0);
	p->img_k = mlx_texture_to_image(mlx, p->txt_k);
	p->img_0 = mlx_texture_to_image(mlx, p->txt_0);
	p->img_1 = mlx_texture_to_image(mlx, p->txt_1);
	p->img_c = mlx_texture_to_image(mlx, p->txt_c);
	p->img_e = mlx_texture_to_image(mlx, p->txt_e);
	p->img_p = mlx_texture_to_image(mlx, p->txt_p);
	p->img_m = mlx_texture_to_image(mlx, p->txt_m);
	p->img_cc = mlx_texture_to_image(mlx, p->txt_cc);
	p->img_eo = mlx_texture_to_image(mlx, p->txt_eo);
	mlx_resize_image(p->img_k, map->tile_sq, map->tile_sq);
	mlx_resize_image(p->img_0, map->tile_sq, map->tile_sq);
	mlx_resize_image(p->img_1, map->tile_sq, map->tile_sq);
	mlx_resize_image(p->img_c, map->tile_sq, map->tile_sq);
	mlx_resize_image(p->img_cc, map->tile_sq, map->tile_sq);
	mlx_resize_image(p->img_e, map->tile_sq, map->tile_sq);
	mlx_resize_image(p->img_p, map->tile_sq, map->tile_sq);
	mlx_resize_image(p->img_m, map->tile_sq, map->tile_sq);
	mlx_resize_image(p->img_eo, map->tile_sq, map->tile_sq);
}
void	my_resize_hook(int32_t width, int32_t height, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	map->window_height = height;
	map->window_width = width;
	alt_manage_images(map->mlx, map, map->img);
	draw_map(map->mlx, map, map->img);
}

void	my_close_hook(void *param)
{
	t_map	*map;

	map = (t_map *)param;
	free_grid(map, 1);
	exit(EXIT_SUCCESS);
}
