/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mgmt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:56:38 by rboudwin          #+#    #+#             */
/*   Updated: 2023/12/21 13:37:08 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_map *map;
	
	map = (t_map *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		free_grid(map, 1);
		exit(EXIT_SUCCESS); // consider leaks for this condition
	}
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_player(map, map->img, 'U');
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_player(map, map->img, 'L');
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_player(map, map->img, 'D');
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_player(map, map->img, 'R');
}