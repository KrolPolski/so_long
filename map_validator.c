/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 09:35:48 by rboudwin          #+#    #+#             */
/*   Updated: 2023/12/19 11:01:21 by rboudwin         ###   ########.fr       */
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
	int		curr_line_length;
	t_list	*curr;

	curr = map->line_list;
	while (curr->next != NULL)
	{
		curr_line_length = ft_strlen(curr->content);
		if (curr_line_length != map->line_length)
			return (0);
		curr = curr->next;
	}
	curr_line_length = ft_strlen(curr->content);
	if (curr_line_length != map->line_length)
		return (0);
	return (1);
}
/*static int	populate_grid(t_map *map)
{
	//how much memory to allocate? substrings are taken care of, but how many strings need to be in the array?
	//we don't know in advance.
	//maybe this is when we use a linked list? except those will be a pain to iterate through that is why
	//we wanted to use an array in the first place.
//	map->i = 0;
//	map->grid[0] = get_next_line(map->fd);
//	map->grid[i]
}*/
int	read_map(t_map *map)
{
	char *current_line;
	current_line = get_next_line(map->fd);
	t_list *current_lst;
	if (current_line)
	{
		(map->line_list) = ft_lstnew(current_line);
		//ft_printf("First line is '%s'\n", map->line_list->content);
		while (current_line)
		{
			current_line = get_next_line(map->fd);
			if (current_line)
			{
				current_lst = ft_lstnew(current_line);
				ft_lstadd_back(&map->line_list, current_lst);
		//		ft_printf("Next line is '%s'\n", current_lst->content);
			}
		}
	}
	map->line_count = ft_lstsize(map->line_list);
	map->line_length = ft_strlen(map->line_list->content);
//ft_printf("there are '%d' nodes in the list", map->line_count);
// add error check for malloc failures and whatnot
	return (1);
}
int	map_validator(t_map *map)
{
	if (!initial_checks(map))
		return (0);
	if (!read_map(map))
		return (0);
	if (!check_shape(map))
	{
		ft_printf("The map is not rectangular\n");
		return (0);
	}
	// check for rectangular shape
	// Check for exactly 1 exit
	// Check for at least one collectible
	// check for exactly one starting position
	// check for if it is closed on all four sides
	// check for a valid path
	return (1);
}
