/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:54:31 by cshingai          #+#    #+#             */
/*   Updated: 2025/03/21 05:14:33 by cshingai         ###   ########.fr       */
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
	game->imgs.img_ceiling = mlx_new_image(game->mlx, WIDTH, HEIGHT / 2);
	ft_memset_32(game->imgs.img_ceiling->pixels,
		game->ceiling, WIDTH * HEIGHT / 2);
	mlx_image_to_window(game->mlx, game->imgs.img_ceiling, 0, 0);
}

void	draw_floor(t_game *game)
{
	game->imgs.img_floor = mlx_new_image(game->mlx, WIDTH, HEIGHT / 2);
	ft_memset_32(game->imgs.img_floor->pixels, game->floor, WIDTH * HEIGHT / 2);
	mlx_image_to_window(game->mlx, game->imgs.img_floor, 0, HEIGHT / 2);
}

void	setting_window(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", true);
	if (!game->mlx)
		ft_error(MLX);
	draw_background(game);
	game->imgs.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(game->mlx, game->imgs.img, 0, 0);
}
