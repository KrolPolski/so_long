/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:50:19 by rboudwin          #+#    #+#             */
/*   Updated: 2023/12/21 13:33:16 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//TODO: libft doesn't always make the right way, left out bonuses. check on this
//TODO: We have to trim \n from the array grid or everything breaks
int	main(int argc, const char **argv)
{
	mlx_t		*mlx;
	t_map		map;
	t_img		p;
	
	map.img = &p;
// need to make sure we free the grid arrays and also the linked lists in all possible exit states
	if (argc <= 1)
	{
		ft_printf("Please specify a *.ber file to read: so_long <filename>\n");
		return (EXIT_FAILURE);
	}
	if (argc > 2)
	{
		ft_printf("Too many parameters\n");
		return (EXIT_FAILURE);
	}
	map.filename = argv[1];
	if (!map_validator(&map))
		return (EXIT_FAILURE);
	mlx = mlx_init(1366, 768, "so_long", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	draw_map(mlx, &map, &p);
	mlx_key_hook(mlx, my_keyhook, &map);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	map.i = 0;
	while(map.grid[map.i] != NULL)
		free(map.grid[map.i++]);
	free(map.grid);
	return (EXIT_SUCCESS);
}