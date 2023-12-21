/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:50:45 by rboudwin          #+#    #+#             */
/*   Updated: 2023/12/21 11:05:41 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "MLX42/MLX42.h"
# include "Libft/libft.h"
# include "Libft/get_next_line_bonus.h"
# include "Libft/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# define BPP sizeof(int32_t)

typedef struct s_map
{
	int			name_length;
	int			fd;
	int			bytes_read;
	const char	*filename;
	char		**grid;
	char		**grid2;
	int			i;
	int			x;
	int			y;
	int			startx;
	int			starty;
	int			exitx;
	int			exity;
	t_list		*line_list;
	int			line_count;
	int			line_length;
	int			exits;
	int			starts;
	int			collectibles;
	int			curr_col;
	int			tile_width;
	int			tile_length;
	int			tile_sq;
}	t_map;
typedef struct s_img
{
	mlx_texture_t	*txt_k;
	mlx_texture_t	*txt_0;
	mlx_texture_t	*txt_1;
	mlx_texture_t	*txt_c;
	mlx_texture_t	*txt_e;
	mlx_texture_t	*txt_p;
	mlx_image_t		*img_k;
	mlx_image_t		*img;
	mlx_image_t		*img_0;
	mlx_image_t		*img_1;
	mlx_image_t		*img_c;
	mlx_image_t		*img_e;
	mlx_image_t		*img_p;
}	t_img;

int		map_validator(t_map *map);
int		check_borders(t_map *map);
int		count_exits_etc(t_map *map);
void	free_grid(t_map *map, int flag);
int		check_valid_path(t_map *map);
void	draw_map(mlx_t *mlx, t_map *map, t_img *p);
#endif
