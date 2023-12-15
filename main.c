/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:50:19 by rboudwin          #+#    #+#             */
/*   Updated: 2023/12/15 09:53:30 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, const char **argv)
{
	mlx_t *mlx;
	mlx_image_t *img;

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
	if (!map_validator(argv[1]))
		return (EXIT_FAILURE);
	mlx = mlx_init(512, 512, "so_long", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	img = mlx_new_image(mlx, 512, 512);
	ft_memset(img->pixels, 255, img->width * img-> height * BPP);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);

	return (EXIT_SUCCESS);
}