/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 21:38:58 by cshingai          #+#    #+#             */
/*   Updated: 2025/03/20 22:22:49 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_map(t_game *game)
{
	int		x;
	int		y;

	y = -1;
	game->imgs.img_map = mlx_new_image(game->mlx, 200, 200);
	while(game->cub3d.map[++y])
	{
		x = 0;
		while (game->cub3d.map[y][x])
		{
			if (game->cub3d.map[y][x] == '1')
				mlx_put_pixel(game->imgs.img_map, x, y,  0x00FF00);
			else if (game->cub3d.map[y][x] == '0')
				mlx_put_pixel(game->imgs.img_map, x, y, 0x0000FF);
			// draw_square(game, x, y, 0x00FF00);
			// draw_square(game, x, y, 0x0000FF);
			// else if (game->cub3d.map[y][x] == '2')
			// 	draw_square(game, x, y, 0xFF0000);
			// mlx_put_pixel(game->imgs.img_map, x, y, 0xFFFFFF);
			x++;
		}
	}
}
