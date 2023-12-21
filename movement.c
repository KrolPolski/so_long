/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:17:00 by rboudwin          #+#    #+#             */
/*   Updated: 2023/12/21 13:03:56 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	move_player(t_map *map, t_img *img, char c)
{
	if (c == 'L')
	{
		ft_printf("We detected intention to move left from x:%d and width of %d\n", map->charx, img->img->width);
	}
	if (c == 'R')
	{
		ft_printf("We detected intention to move left\n");
	}
	if (c == 'U')
	{
		ft_printf("We detected intention to move left\n");
	}
	if (c == 'D')
	{
		ft_printf("We detected intention to move left\n");
	}
}
