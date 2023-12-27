/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:50:19 by rboudwin          #+#    #+#             */
/*   Updated: 2023/12/27 16:09:13 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//TODO: libft doesn't always make the right way, left out bonuses. check on this
void	check_args(int argc, const char **argv, t_map *map)
{
	if (argc <= 1)
	{
		ft_printf("Please specify a *.ber file to read: so_long <filename>\n");
		exit(EXIT_FAILURE);
	}
	if (argc > 2)
	{
		ft_printf("Too many parameters\n");
		exit(EXIT_FAILURE);
	}
	map->filename = argv[1];
}

int	main(int argc, const char **argv)
{
	mlx_t	*mlx;
	t_map	map;
	t_img	p;

	map.img = &p;
	check_args(argc, argv, &map);
	if (!map_validator(&map))
		return (EXIT_FAILURE);
	mlx = mlx_init(1366, 768, "so_long", true);
	map.window_width = 1366;
	map.window_height = 768;
	map.mlx = mlx;
	if (!mlx)
		exit(EXIT_FAILURE);
	map.charx = map.startx;
	map.chary = map.starty;
	draw_map(mlx, &map, &p);
	mlx_key_hook(mlx, my_keyhook, &map);
	mlx_resize_hook(mlx, my_resize_hook, &map);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	map.i = 0;
	while (map.grid[map.i] != NULL)
		free(map.grid[map.i++]);
	free(map.grid);
	return (EXIT_SUCCESS);
}
