/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:17:00 by rboudwin          #+#    #+#             */
/*   Updated: 2023/12/21 13:46:37 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	move_player(t_map *map, t_img *img, char c)
{
	if (img)
		if (map)
		ft_printf("We managed to ignore CCC\n");
	ft_printf("We are running move_player with '%c' as a parameter\n", c);
	if (c == 'L')
	{
		ft_printf("We detected intention to move left");//from x:%d and width of %d\n", map->charx, img->img->width);
	}
	if (c == 'R')
	{
		ft_printf("We detected intention to move right\n");
	}
	if (c == 'U')
	{
		ft_printf("We detected intention to move up\n");
	}
	if (c == 'D')
	{
		ft_printf("We detected intention to move down\n");
	}
}
