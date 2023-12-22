/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adv_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:46:53 by rboudwin          #+#    #+#             */
/*   Updated: 2023/12/22 09:37:29 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_exits_etc(t_map *map)
{
	map->x = 0;
	map->y = 0;
	map->starts = 0;
	map->exits = 0;
	map->collectibles = 0;
	while (map->grid[map->y] != NULL)
	{
		while (map->grid[map->y][map->x] != '\0')
		{
			if (map->grid[map->y][map->x] == 'P')
			{
				(map->starts)++;
				map->starty = map->y;
				map->startx = map->x;
			}
			else if (map->grid[map->y][map->x] == 'C')
				(map->collectibles)++;
			else if (map->grid[map->y][map->x] == 'E')
			{
				(map->exits)++;
				map->exitx = map->x;
				map->exity = map->y;
			}
			else if (!ft_strchr("10CEP", map->grid[map->y][map->x]))
			{
				ft_printf("ERROR: Invalid character detected in map\n");
				return (0);
			}
			map->x++;
		}
		map->x = 0;
		map->y++;
	}
	ft_printf("starts %d exits %d collectibles %d\n",
		map->starts, map->exits, map->collectibles);
	if (map->starts != 1 || map->exits != 1 || map->collectibles <= 0)
	{
		ft_printf("ERROR: Invalid map- starts: %d exits: %d collectibles: %d\n",
			map->starts, map->exits, map->collectibles);
		ft_printf("You must have exactly one start, one exit");
		ft_printf(" and at least one collectible\n");
		return (0);
	}
	return (1);
}

int	check_borders(t_map *map)
{
	map->x = 0;
	map->y = 0;
	while (map->grid[0][map->x] != '\0')
	{
		if (map->grid[0][map->x] != '1')
			return (0);
		(map->x)++;
	}
	map->y++;
	map->x = 0;
	while (map->y < map->line_count - 1)
	{
		if (map->grid[map->y][0] != '1'
			|| map->grid[map->y][map->line_length - 1] != '1')
			return (0);
		map->y++;
	}
	while (map->grid[map->line_count - 1][map->x] != '\0')
	{
		if (map->grid[map->line_count - 1][map->x] != '1')
			return (0);
		map->x++;
	}
	return (1);
}

void	check_square(t_map *map)
{
	if (map->grid2[map->y + 1][map->x] == '0'
		|| map->grid2[map->y + 1][map->x] == 'E')
		map->grid2[map->y + 1][map->x] = 'X';
	if (map->grid[map->y + 1][map->x] == 'C')
	{
		map->curr_col--;
		map->grid2[map->y + 1][map->x] = 'X';
	}
	if (map->grid2[map->y - 1][map->x] == '0'
		|| map->grid2[map->y - 1][map->x] == 'E')
		map->grid2[map->y - 1][map->x] = 'X';
	if (map->grid[map->y - 1][map->x] == 'C')
	{
		map->curr_col--;
		map->grid2[map->y - 1][map->x] = 'X';
	}
	if (map->grid2[map->y][map->x + 1] == '0'
		|| map->grid2[map->y][map->x + 1] == 'E')
		map->grid2[map->y][map->x + 1] = 'X';
	if (map->grid[map->y][map->x + 1] == 'C')
	{
		map->curr_col--;
		map->grid2[map->y][map->x + 1] = 'X';
	}
	if (map->grid2[map->y][map->x - 1] == '0'
		|| map->grid2[map->y][map->x - 1] == 'E')
		map->grid2[map->y][map->x - 1] = 'X';
	if (map->grid2[map->y][map->x - 1] == 'C')
	{
		map->curr_col--;
		map->grid2[map->y][map->x - 1] = 'X';
	}
	map->grid2[map->y][map->x] = '*';
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
			ft_printf("current X is at y:%d and x:%d\n", map->y, map->x);
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
	check_square(map);
	while (!collect_exit(map))
	{
		if (!find_x(map))
		{
			while (map->grid2[i] != NULL)
				ft_printf("%s\n", map->grid2[i++]);
			return (0);
		}
		check_square(map);
	}
	while (map->grid2[i] != NULL)
		ft_printf("%s\n", map->grid2[i++]);
	return (1);
}

int	check_valid_path(t_map *map)
{
	map->grid2 = malloc(sizeof(char *) * map->line_count + 1);
	map->y = 0;
	while (map->grid[map->y] != NULL)
	{
		map->grid2[map->y] = ft_strdup(map->grid[map->y]);
		ft_printf("New grid: %s\n", map->grid2[map->y]);
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
	ft_printf("We passed valid path test\n");
	map->y = 0;
	while (map->grid[map->y] != NULL)
		ft_printf("%s\n", map->grid[map->y++]);
	return (1);
}
