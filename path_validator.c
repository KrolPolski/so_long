/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 10:26:34 by rboudwin          #+#    #+#             */
/*   Updated: 2023/12/27 17:13:16 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	resolve_collectible(t_map *map, int y, int x)
{
		map->curr_col--;
		map->grid2[y][x] = 'X';
}

void	check_square(t_map *map, int y, int x)
{
	if (map->grid2[y + 1][x] == '0'	|| map->grid2[y + 1][x] == 'E')
		map->grid2[y + 1][x] = 'X';
	if (map->grid[y + 1][x] == 'C')
		resolve_collectible(map, y + 1, x);
	if (map->grid2[y - 1][x] == '0'	|| map->grid2[y - 1][x] == 'E')
		map->grid2[y - 1][x] = 'X';
	if (map->grid[y - 1][x] == 'C')
		resolve_collectible(map, y - 1, x);
	if (map->grid2[y][x + 1] == '0'	|| map->grid2[y][x + 1] == 'E')
		map->grid2[y][x + 1] = 'X';
	if (map->grid[y][x + 1] == 'C')
		resolve_collectible(map, y, x + 1);
	if (map->grid2[y][x - 1] == '0'	|| map->grid2[y][x - 1] == 'E')
		map->grid2[y][x - 1] = 'X';
	if (map->grid2[y][x - 1] == 'C')
		resolve_collectible(map, y, x - 1);
	map->grid2[y][x] = '*';
}

int	collect_exit(t_map *map)
{
	if (map->curr_col > 0)
		return (0);
	if (map->grid2[map->exity][map->exitx] == 'E')
		return (0);
	return (1);
}

int	find_x(t_map *map)
{
	map->y = 0;
	map->x = 0;
	while (map->grid2[map->y] != NULL)
	{
		while (map->grid2[map->y][map->x] != '\0'
			&& map->grid2[map->y][map->x] != 'X')
		{
			map->x++;
		}
		if (map->grid2[map->y][map->x] == 'X')
		{
			return (1);
		}
		else
		{
			map->x = 0;
			map->y++;
		}
	}
	return (0);
}

int	mark_paths(t_map *map)
{
	int	i;

	i = 0;
	map->curr_col = map->collectibles;
	check_square(map, map->y, map->x);
	while (!collect_exit(map))
	{
		if (!find_x(map))
		{
			while (map->grid2[i] != NULL)
				ft_printf("%s\n", map->grid2[i++]);
			return (0);
		}
		check_square(map, map->y, map->x);
	}
	//while (map->grid2[i] != NULL)
	//	ft_printf("%s\n", map->grid2[i++]);
	return (1);
}

int	check_valid_path(t_map *map)
{
	map->grid2 = malloc(sizeof(char *) * map->line_count + 1);
	map->y = 0;
	while (map->grid[map->y] != NULL)
	{
		map->grid2[map->y] = ft_strdup(map->grid[map->y]);
	//	ft_printf("New grid: %s\n", map->grid2[map->y]);
		map->y++;
	}
	map->grid2[map->y] = NULL;
	map->y = map->starty;
	map->x = map->startx;
	if (!mark_paths(map))
	{
		free_grid(map, 2);
		ft_printf("ERROR: No valid path detected\n");
		return (0);
	}
	free_grid(map, 2);
	//ft_printf("We passed valid path test\n");
	map->y = 0;
//	while (map->grid[map->y] != NULL)
//		ft_printf("%s\n", map->grid[map->y++]);
	return (1);
}
