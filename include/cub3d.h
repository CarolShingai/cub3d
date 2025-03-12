/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:26:12 by cshingai          #+#    #+#             */
/*   Updated: 2025/03/12 18:05:43 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "colors.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include "../libs/libft/libft.h"
# include "../libs/ft_printf/src/ft_printf.h"
# include "../libs/MLX42/include/MLX42/MLX42.h"

# define WIDTH  800
# define HEIGHT 600

typedef struct s_vector
{
	float	x;
	float	y;
}	t_vector;

typedef struct s_cord
{
	int	x;
	int	y;
}	t_cord;

typedef struct s_dda
{
	t_vector	ray_dir;
	t_vector	delta_dist;
	t_vector	dist_to_side;
	t_cord		map;
	t_cord		step;
	int			hit_side;
	float		perpen_dist;
}	t_dda;

typedef struct s_wall
{
	t_dda	dda;
	int		wall_height;
	int		line_starty;
	int		line_endy;
}	t_wall;

typedef struct s_view
{
	t_vector	player_pos;
	t_vector	player_dir;
	t_vector	camera_plane;
}	t_view;

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_view		view;
	char		pov;
	int			ceiling;
	int			floor;
	char		**map;
}	t_game;



uint32_t get_rgb(int r, int g, int b);
// error.c
void	ft_error(void);

// setting_window.c
void	setting_window(t_game *game);
void	draw_background(t_game *game);
void	draw_ceiling(t_game *game);
void	draw_floor(t_game *game);
void	draw_rays(t_game *game);
void	calcule_delta_dist(t_dda *ray);
void	calcule_dist_to_side(t_dda *ray, t_game *game);
void	algorithm_dda(t_dda *ray, t_game *game);

// vector_utils.c
t_vector	add_vector(t_vector v1, t_vector v2);
t_vector	sub_vector(t_vector v1, t_vector v2);
t_vector	create_vector(float x, float y);
t_vector	mult_vector(t_vector vector, double mult);

// setting_game.c
void	set_position(t_game *game);
void	initial_plane(t_game *game);

// draw_wall.c
void    draw_wall(t_dda ray, t_game *game, int pixel);
// draw_view.c
void	draw_view(void *param);
void	update_ray_map(t_game *game, t_dda *ray);

#endif
