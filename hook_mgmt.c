/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mgmt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:56:38 by rboudwin          #+#    #+#             */
/*   Updated: 2023/12/27 17:32:19 by rboudwin         ###   ########.fr       */
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

void	my_resize_hook(int32_t width, int32_t height, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	ft_printf("We should resize now to %d by %d\n", width, height);
	map->window_height = height;
	map->window_width = width;
	draw_map(map->mlx, map, map->img);
}

void	my_close_hook(void *param)
{
	t_map	*map;

	map = (t_map *)param;
	free_grid(map, 1);
	exit(EXIT_SUCCESS);
}
