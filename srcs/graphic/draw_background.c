/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:54:31 by cshingai          #+#    #+#             */
/*   Updated: 2025/03/13 19:14:22 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_background(t_game *game)
{
	draw_ceiling(game);
	draw_floor(game);
}

void	draw_ceiling(t_game *game)
{
	mlx_image_t *img_ceiling;

	img_ceiling = mlx_new_image(game->mlx, WIDTH, HEIGHT / 2);
	ft_memset_32(img_ceiling->pixels, game->ceiling, WIDTH * HEIGHT / 2);
	mlx_image_to_window(game->mlx, img_ceiling, 0, 0);
}

void	draw_floor(t_game *game)
{
	mlx_image_t *img_floor;

	img_floor = mlx_new_image(game->mlx, WIDTH, HEIGHT / 2);
	ft_memset_32(img_floor->pixels, game->floor, WIDTH * HEIGHT / 2);
	mlx_image_to_window(game->mlx, img_floor, 0, HEIGHT / 2);
}

void	setting_window(t_game *game)
{
	// mlx_set_setting(MLX_MAXIMIZED, true);
	game->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", true);
	if (!game->mlx)
		ft_error();
	draw_background(game);
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	draw_rays(game);
	mlx_image_to_window(game->mlx, game->img, 0, 0);
}
