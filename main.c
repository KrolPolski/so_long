/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:50:19 by rboudwin          #+#    #+#             */
/*   Updated: 2023/12/14 14:11:22 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	mlx_t *mlx;
	mlx_image_t *img;

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