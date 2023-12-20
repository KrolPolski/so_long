/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adv_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:46:53 by rboudwin          #+#    #+#             */
/*   Updated: 2023/12/20 14:42:21 by rboudwin         ###   ########.fr       */
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
	//	ft_printf("about to do a row\n");
		while (map->grid[map->y][map->x] != '\0')
		{
			//ft_printf("%c y: %d x: %d\n", map->grid[map->y][map->x], map->y, map->x);
			if (map->grid[map->y][map->x] == 'P')
			{
				(map->starts)++;
				map->starty = map->y;
				map->startx = map->x;
				ft_printf("Starting position is at Y:%d X:%d\n", map->startx, map->starty);
			}
			else if (map->grid[map->y][map->x] == 'C')
				(map->collectibles)++;
			else if (map->grid[map->y][map->x] == 'E')
				(map->exits)++;
			map->x++;
		}
		map->x = 0;
		map->y++;
	}
	ft_printf("starts %d exits %d collectibles %d\n", map->starts, map->exits, map->collectibles);
	if (map->starts != 1 || map->exits != 1 || map->collectibles <= 0)
	{
		ft_printf("ERROR: Invalid map- starts: %d exits: %d collectibles: %d\n", map->starts, map->exits, map->collectibles);
		ft_printf("You must have exactly one start, one exit, and at least one collectible\n");
		return(0);
	}
	return (1);
}
int	check_borders(t_map *map)
{
	//ft_printf("Hello advanced validator baby\n");
	map->x = 0;
	map->y = 0;
	while (map->grid[0][map->x] != '\0')
	{
		//ft_printf("We are trying to check the first line\n");
		if (map->grid[0][map->x] != '1')
			return (0);
		(map->x)++;
	}
	map->y++;
	map->x = 0;
	while (map->y < map->line_count - 1)
	{
		if (map->grid[map->y][0] != '1' || map->grid[map->y][map->line_length - 1] != '1')
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
	if (map->grid2[map->y + 1][map->x] == '0')
		map->grid2[map->y + 1][map->x] = 'X';
	if (map->grid[map->y + 1][map->x] == 'C')
		{
			map->curr_col--;
			map->grid2[map->y + 1][map->x] = 'X';
		}
	if (map->grid2[map->y - 1][map->x] == '0')
		map->grid2[map->y - 1][map->x] = 'X';
	if (map->grid[map->y - 1][map->x] == 'C')
	{
		map->curr_col--;
		map->grid2[map->y - 1][map->x] = 'X';
	}
	if (map->grid2[map->y][map->x + 1] == '0')
		map->grid2[map->y][map->x + 1] = 'X';
	if (map->grid[map->y][map->x + 1] == 'C')
	{
		map->curr_col--;
		map->grid2[map->y][map->x + 1] = 'X';
	}
	if (map->grid2[map->y][map->x - 1] == '0') 
		map->grid2[map->y][map->x - 1] = 'X';
	if (map->grid[map->y][map->x - 1] == 'C')
	{
		map->curr_col--;
		map->grid2[map->y][map->x - 1] = 'X';
	}
	map->grid2[map->y][map->x] = '*';
}
void	collect_exit(t_map *map)
{
	map->i = 0;
}
void	mark_paths(t_map *map)
{
	int i; 
	i = 0;
	map->curr_col = map->collectibles;
	check_square(map);
	// check if there are collectibles left, or if we see the exit
	collect_exit(map);
	while (map->grid2[i] != NULL)
		ft_printf("%s\n", map->grid2[i++]);
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
	//start from starting position
	map->y = map->starty;
	map->x = map->startx;

		//mark all possible moves with x
	//mark current position with *
	mark_paths(map);
return (1);
	//make a copy of the grid by just reading it again

	//check for Xs
	//mark current positin with *
	//mark all possible moves with X
	//loop until we see an E or we run out
	//discard grid copy
	//free both grids if we find an error
}
