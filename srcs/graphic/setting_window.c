/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:54:31 by cshingai          #+#    #+#             */
/*   Updated: 2025/03/12 20:24:56 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

#define BPP sizeof(int32_t)

void	draw_background(t_game *game)
{
	draw_ceiling(game);
	draw_floor(game);
}

void	draw_ceiling(t_game *game)
{
	mlx_image_t *img_ceiling;
	uint32_t	x;
	uint32_t	y;

	img_ceiling = mlx_new_image(game->mlx, WIDTH, HEIGHT / 2);
	y = 0;
	while (y < img_ceiling->height)
	{
		x = 0;
		while (x < img_ceiling->width)
		{
			mlx_put_pixel(img_ceiling, x, y, game->ceiling);
			x++;
		}
		y++;
	}
	mlx_image_to_window(game->mlx, img_ceiling, 0, 0);
}

void draw_floor(t_game *game)
{
	mlx_image_t *img_floor;
	uint32_t	x;
	uint32_t	y;

	img_floor = mlx_new_image(game->mlx, WIDTH, HEIGHT / 2);
	y = 0;
	while (y < img_floor->height)
	{
		x = 0;
		while (x < img_floor->width)
		{
			mlx_put_pixel(img_floor, x, y, game->floor);
			x++;
		}
		y++;
	}
	mlx_image_to_window(game->mlx, img_floor, 0, HEIGHT / 2);
}

void    setting_window(t_game *game)
{
	// mlx_set_setting(MLX_MAXIMIZED, true);
	game->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", true);
	if (!game->mlx)
		ft_error();
	draw_background(game);
}

