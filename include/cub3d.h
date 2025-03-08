/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:26:12 by cshingai          #+#    #+#             */
/*   Updated: 2025/03/07 22:13:48 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "colors.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../libs/libft/libft.h"
# include "../libs/ft_printf/src/ft_printf.h"
# include "../libs/MLX42/include/MLX42/MLX42.h"

# define WIDTH  1360
# define HEIGHT 800

typedef struct s_vector
{
	float	x;
	float	y;
}	t_vector;

typedef struct s_view
{
	t_vector	player_position;
	t_vector	player_direction;
	t_vector	camera_plane;
}	t_view;

typedef struct s_game
{
	mlx_t		*mlx;
	t_view		view;
	char		pov;
	int			ceiling;
	int			floor;
}	t_game;


// error.c
void	ft_error(void);

// setting_window.c
void	setting_window(t_game *game);
void	draw_background(t_game *game);
void	draw_ceiling(t_game *game);
void	draw_floor(t_game *game);

// vector_utils.c
t_vector	add_vector(t_vector v1, t_vector v2);
t_vector	sub_vector(t_vector v1, t_vector v2);
t_vector	create_vector(float x, float y);
t_vector	mult_vector(t_vector vector, double mult);


#endif
