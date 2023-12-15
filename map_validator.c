/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 09:35:48 by rboudwin          #+#    #+#             */
/*   Updated: 2023/12/15 09:51:24 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_validator(const char *filename)
{
	int	name_length;

	if (!filename)
	{
		ft_printf("NULL filename passed to map_validator\n");
		return (0);
	}
	name_length = ft_strlen(filename);
	// First check for .ber extension
	if (ft_strncmp(&filename[name_length - 4], ".ber", 4))
	{
		ft_printf("Map name does not end in .ber extension\n");	
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
