/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:06:56 by rboudwin          #+#    #+#             */
/*   Updated: 2023/12/27 17:16:39 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collect_chest(t_map *map, t_img *img, mlx_t *mlx)
{
	map->curr_col++;
	ft_printf("You now have %d/%d chests.\n", map->curr_col, map->collectibles);
	mlx_image_to_window(mlx, img->img_cc,
		map->charx * map->tile_sq, map->chary * map->tile_sq);
	map->grid[map->chary][map->charx] = 'c';
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

int	report_bad_border(void)
{
	ft_printf("ERROR: The map does not have obstacles across all edges\n");
	return (0);
}

int	report_map_count_error(t_map *map)
{
	ft_printf("ERROR: Invalid map- starts: %d exits: %d collectibles: %d\n",
		map->starts, map->exits, map->collectibles);
	ft_printf("You must have exactly one start, one exit");
	ft_printf(" and at least one collectible\n");
	return (0);
}

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

void	resolve_collectible(t_map *map, int y, int x)
{
	map->curr_col--;
	map->grid2[y][x] = 'X';
}
