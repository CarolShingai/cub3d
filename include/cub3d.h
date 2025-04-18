/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:26:12 by cshingai          #+#    #+#             */
/*   Updated: 2025/04/07 18:34:51 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "colors.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include "../libs/libft/libft.h"
# include "../libs/ft_printf/src/ft_printf.h"
# include "../libs/MLX42/include/MLX42/MLX42.h"

# define ERROR_ARGS "Number of arguments is invalid."
# define ERROR_FILE_NAME "File is not cub type."
# define ERROR_MAP_MISSING "Map is missing."
# define ERROR_MALLOC "Malloc failed."
# define DUPLICATE_CONFIG "Duplicate parameter. North, South, East, West, \
Floor and Ceiling must be unique."
# define AFTER_MAP "Map should be the last parameter"
# define CONFIG_MISSING "North, South, East, West, Floor and Ceiling \
must be set."
# define IS_A_DIRECTORY "The map and textures must be files not directories"
# define VERIFY_NAME "Check the name of the files"
# define CONFIG_COLOR "Color must be in the format R,G,B without spaces. \
The values must be between 0 and 255."
# define INVALID_CHAR "Invalid character in the map."
# define MULTIPLE_PLAYER "Multiple players"
# define NO_PLAYER "Player not found"
# define MAP_NOT_CLOSED "Map is not closed"
# define TEXTURE_ERROR "ERROR! Problem with the texture image."
# define IMAGE_ERROR "ERROR! Problem loading the image."
# define MLX "ERROR! Problem with mlx."

// Screen size
# define WIDTH  1000
# define HEIGHT 800

// Game settings
# define MOV_SPEED 0.05
# define ROTATE_SPEED 0.05
# define FOV 0.66
# define MARGIN_COLLISION 0.2

enum e_is_map
{
	NO_MAP,
	IS_MAP,
	END_MAP,
	ERROR_CONFIG,
	ERROR_MAP
};

enum e_pipe_mode
{
	EXTRACT,
	LOAD
};

enum e_map_config
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
	FLOOR,
	CEILING
};

typedef struct s_imgs
{
	mlx_image_t	*img;
	mlx_image_t	*img_ceiling;
	mlx_image_t	*img_floor;
	mlx_image_t	*minimap;
	mlx_image_t	*miniwall_x;
	mlx_image_t	*miniwall_y;
	mlx_image_t	*player;
}	t_imgs;

typedef struct s_texture
{
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*east;
	mlx_texture_t	*west;
}	t_texture;

typedef struct s_colors
{
	int		red;
	int		green;
	int		blue;
}	t_colors;

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
	t_vector	hit_pos;
	t_cord		map;
	t_cord		step;
	int			hit_side;
	int			side;
	float		perpen_dist;
}	t_dda;

typedef struct s_wall
{
	t_dda	dda;
	int		wall_height;
	int		line_starty;
	int		line_endy;
	int		tex_x;
	int		tex_y;
	int		tex_pos;
	int		tex_step;
}	t_wall;

typedef struct s_view
{
	t_vector	player_pos;
	t_vector	player_dir;
	t_vector	camera_plane;
	double		mov_speed;
	double		rotate_speed;
	float		fov;
}	t_view;

typedef struct s_cub3d
{
	t_colors	floor_color;
	t_colors	ceiling_color;
	int			start_pos_x;
	int			start_pos_y;
	char		start_dir;
	char		**config;
	char		**map;
	int			map_size;
	int			fd_extract;
	int			fd_load;
}	t_cub3d;

typedef struct s_game
{
	mlx_t		*mlx;
	t_imgs		imgs;
	t_view		view;
	t_cub3d		cub3d;
	t_texture	texture;
	t_dda		ray;
	char		pov;
	int			minimap_visible;
	int			ceiling;
	int			floor;
	double		*frame_time;
}	t_game;

// error.c
void			ft_error(char *msg, t_game *game);
// setting_window.c
void			setting_window(t_game *game);
void			draw_background(t_game *game);
void			draw_ceiling(t_game *game);
void			draw_floor(t_game *game);
uint32_t		get_rgb(int r, int g, int b);
//validation
void			error_handling(char *message);
void			check_args_and_file(int argc, char **argv);
void			check_file_name(char *file_name);
//pipeline
void			init_cub3d(t_cub3d *cub3d);
void			run_pipeline(int argc, char **argv, t_cub3d *cub3d);
//extract
void			extract(char *file_path, t_cub3d *cub3d);
void			read_map(t_cub3d *cub3d, int mode, int fd);
int				file_opening(char *file_path, t_cub3d *cub3d);
int				check_line(char *line, int map_was, t_cub3d *cub3d, int mode);
int				check_config(char c1, char c2);
int				save_config_to_array(char *line, t_cub3d *cub3d, int config);
void			error_handling_extract(int is_map, t_cub3d *cub3d,
					int fd, int mode);
//load
void			load(t_cub3d *cub3d, char *file_path);
void			set_array(t_cub3d *cub3d);
//utils
void			ft_free_array_str(char **split);
void			ft_free_all(t_cub3d *cub3d);
void			ft_free_config(t_cub3d *cub3d);
//textures_analysis
void			check_all_configs(t_cub3d *cub3d);
void			data_analysis(t_cub3d *cub3d);
void			verify_textures_files(t_cub3d *cub3d);
void			new_line_removal(char **str);
void			check_textures_file_name(char *file_name, t_cub3d *cub3d);
//color_analysis
void			check_color(t_cub3d *cub3d);
void			error_handling_and_free(t_cub3d *cub3d, char *message);
int				check_three_colors(char *str);
int				convert_color(char *str, int type, t_cub3d *cub3d);
void			set_colors(t_colors colors, int type, t_cub3d *cub3d);
//map_analysis
void			map_analysis(t_cub3d *cub3d);
void			check_map_chars(t_cub3d *cub3d);
void			check_and_set_player(t_cub3d *cub3d, int i, int j, int *player);
void			check_map_walls(t_cub3d *cub3d);
int				check_arround_zeros(t_cub3d *cub3d, int i, int j);
//algorithm_dda
void			draw_rays(t_game *game);
void			calcule_delta_dist(t_dda *ray);
void			calcule_dist_to_side(t_dda *ray, t_game *game);
void			algorithm_dda(t_dda *ray, t_game *game);
void			update_ray_map(t_game *game, t_dda *ray);
// vector_utils.c
t_vector		add_vector(t_vector v1, t_vector v2);
t_vector		sub_vector(t_vector v1, t_vector v2);
t_vector		create_vector(float x, float y);
t_vector		mult_vector(t_vector vector, double mult);
t_vector		copy_vector(t_vector v);
t_vector		rotate(t_vector v, double angle);
// setting_game.c
void			set_position(t_game *game);
void			initial_plane(t_game *game);
// draw_wall.c
void			draw_wall(t_dda *ray, t_game *game, int pixel);
void			set_wall_position(t_dda *ray);
mlx_texture_t	*get_texture(t_dda *ray, t_game *game);
void			calc_tex_position(t_wall *wall, t_dda *ray,
					mlx_texture_t *wall_img, t_game *game);
uint32_t		get_pixel_color(mlx_texture_t *tex, int x, int y);
// draw_view.c
void			draw_view(void *param);
void			clear_image(mlx_image_t *img, uint32_t color);
// key_hook
void			key_action(mlx_key_data_t keydata, void *param);
void			clear_game(t_game *game);
int				player_keys(keys_t key);
void			visible_map(t_game *game);
void			unvisible_map(t_game *game);
// moviments.c
void			moviments(t_game *game, keys_t key);
void			horizontal_moviments(t_game *game, keys_t key,
					double m_speed, t_vector *new_pos);
void			vertical_moviments(t_game *game, keys_t key,
					double m_speed, t_vector *new_pos);
void			get_new_pos(t_game *game, keys_t key, t_vector *new_pos);
void			camera_rotation(t_game *game, keys_t key, double angle);
// moviments_restrition.c
int				collision(t_game *game, t_vector *new_pos);
int				check_collision_mov(t_game *game, t_vector *new_pos,
					float margin);
int				check_collision_camera(t_game *game, t_vector *new_pos,
					float margin);
// texture.c
mlx_texture_t	*init_texture(char *path, t_game *game);
void			load_texture(t_game *game);
void			clear_textures(t_game *game);

#endif
