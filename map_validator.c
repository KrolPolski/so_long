/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 09:35:48 by rboudwin          #+#    #+#             */
/*   Updated: 2023/12/27 17:01:12 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	initial_checks(t_map *map)
{
	if (!map->filename)
	{
		ft_printf("ERROR: NULL filename passed to map_validator\n");
		return (0);
	}
	map->name_length = ft_strlen(map->filename);
	if (ft_strncmp(&map->filename[map->name_length - 4], ".ber", 4))
	{
		ft_printf("ERROR: Map name does not end in .ber extension\n");
		return (0);
	}
	map->fd = open(map->filename, O_RDONLY);
	if (map->fd == -1)
	{
		perror("ERROR: Unable to open map");
		return (0);
	}
	return (1);
}

static int	check_shape(t_map *map)
{
	int		curr_line_length;
	t_list	*curr;

	curr = map->line_list;
	while (curr != NULL)
	{
		curr_line_length = ft_strlen(curr->content);
		if (curr_line_length != map->line_length)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	read_map(t_map *map)
{
	char	*current_line;
	t_list	*current_lst;

	current_line = get_next_line(map->fd);
	if (current_line[ft_strlen(current_line) - 1] == '\n')
		current_line[ft_strlen(current_line) - 1] = '\0';
	if (current_line)
	{
		(map->line_list) = ft_lstnew(current_line);
		while (current_line)
		{
			current_line = get_next_line(map->fd);
			if (current_line)
			{
				if (current_line[ft_strlen(current_line) - 1] == '\n')
					current_line[ft_strlen(current_line) - 1] = '\0';
				current_lst = ft_lstnew(current_line);
				ft_lstadd_back(&map->line_list, current_lst);
			}
		}
	}
	map->line_count = ft_lstsize(map->line_list);
	map->line_length = ft_strlen(map->line_list->content);
	return (1);
}

int	convert_to_array(t_map *map)
{
	char	*line_array;
	t_list	*curr;

	map->grid = malloc(sizeof(char *) * (map->line_count + 1));
	if (!map->grid)
		return (0);
	map->i = 0;
	curr = map->line_list;
	while (curr != NULL)
	{
		line_array = ft_strdup(curr->content);
		if (!line_array)
			return (0);
		map->grid[map->i] = line_array;
		map->i++;
		curr = curr->next;
	}
	map->grid[map->i] = NULL;
	ft_lstclear(&map->line_list, free);
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
		ft_printf("ERROR: The map is not rectangular\n");
		ft_lstclear(&map->line_list, free);
		return (0);
	}
	if (!convert_to_array(map) || !check_borders(map)
		|| !count_exits_etc(map) || !check_valid_path(map))
	{
		free_grid(map, 1);
		return (0);
	}
	map->charx = map->startx;
	map->chary = map->starty;
	return (1);
}
