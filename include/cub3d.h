/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:26:12 by cshingai          #+#    #+#             */
/*   Updated: 2025/03/06 22:48:00 by lsouza-r         ###   ########.fr       */
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
# include "../libs/libft/libft.h"
# include "../libs/ft_printf/src/ft_printf.h"
# include "../libs/MLX42/include/MLX42/MLX42.h"

# define WIDTH  1360
# define HEIGHT 800

# define ERROR_ARGS "Number of arguments is invalid."
# define ERROR_FILE_NAME "File is not cub type."
# define ERROR_MAP_MISSING "Map is missing."
# define ERROR_MALLOC "Malloc failed."

enum e_is_map
{
	NO_MAP,
	IS_MAP,
	END_MAP
};

enum e_pipe_mode
{
	EXTRACT,
	LOAD
};

typedef struct s_game
{
	mlx_t		*mlx;
	int			ceiling;
	int			floor;
}	t_game;

typedef struct s_cub3d
{
	char	**map;
	int		map_size;
	int		fd_extract;
	int		fd_load;
}	t_cub3d;

// error.c
void	ft_error(void);

// setting_window.c
void	setting_window(t_game *game);
void	draw_background(t_game *game);
void	draw_ceiling(t_game *game);
void	draw_floor(t_game *game);

//validation
void	error_handling(char *message);
void	validation(int argc, char **argv);
void	check_args_and_file(int argc, char **argv);
void	check_file_name(char *file_name);
//pipeline
void	init_cub3d(t_cub3d *cub3d);
void	run_pipeline(int argc, char **argv);
//extract
void	extract(char *file_path, t_cub3d *cub3d);
void	read_map(t_cub3d *cub3d, int mode, int fd);
int		file_opening(char *file_path);
int		check_line(char *line, int is_map);
//load
void	load(t_cub3d *cub3d, char *file_path);
void	set_array(t_cub3d *cub3d);

#endif
