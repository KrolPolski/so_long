/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:50:45 by rboudwin          #+#    #+#             */
/*   Updated: 2023/12/20 11:46:40 by rboudwin         ###   ########.fr       */
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
	int			i;
	int			x;
	int			y;
	t_list		*line_list;
	int			line_count;
	int			line_length;
	int			exits;
	int			starts;
	int			collectibles;
}	t_map;
int	map_validator(t_map *map);
int	check_borders(t_map *map);
int	count_exits_etc(t_map *map);
#endif
