/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 09:35:48 by rboudwin          #+#    #+#             */
/*   Updated: 2023/12/15 10:39:53 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
static int	initial_checks(t_map *map)
{
	if (!map->filename)
	{
		ft_printf("NULL filename passed to map_validator\n");
		return (0);
	}
	map->name_length = ft_strlen(map->filename);
	// First check for .ber extension
	if (ft_strncmp(&map->filename[map->name_length - 4], ".ber", 4))
	{
		ft_printf("Map name does not end in .ber extension\n");	
		return (0);
	}
	// try to open it
	map->fd = open(map->filename, O_RDONLY);
	if (map->fd == -1)
	{
		perror("Unable to open map");
		return (0);
	}
	return (1);
}
static int	check_shape(t_map *map)
{
	return (1);
}
static int	populate_grid(t_map *map)
{
	//how much memory to allocate? substrings are taken care of, but how many strings need to be in the array?
	//we don't know in advance.
	//maybe this is when we use a linked list? except those will be a pain to iterate through that is why
	//we wanted to use an array in the first place.
	map->i = 0;
	map->grid[0] = get_next_line(map->fd);
	map->grid[i]
}
int	map_validator(t_map *map)
{
	if (!initial_checks(map))
		return(0);
	if (!check_shape(map))
		return(0);
	// check for rectangular shape
	// Check for exactly 1 exit
	// Check for at least one collectible
	// check for exactly one starting position
	// check for if it is closed on all four sides
	// check for a valid path
	return (1);
}
