/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:04:11 by cshingai          #+#    #+#             */
/*   Updated: 2025/03/13 19:52:00 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_wall(t_dda ray, t_game *game, int pixel)
{
	uint32_t	color;
	t_wall	wall;
	(void)game;
	(void)pixel;
	int y;

	wall.wall_height = HEIGHT / ray.perpen_dist;
	wall.line_starty = fmax(0, (HEIGHT / 2 - wall.wall_height / 2));
	wall.line_endy = fmin(HEIGHT, (HEIGHT / 2 + wall.wall_height / 2));
	y = wall.line_starty;
	if (ray.hit_side == 1)
		color = get_rgb(140, 179, 255);
	else
		color = get_rgb(255, 100, 255);
	while (y < wall.line_endy)
	{
		mlx_put_pixel(game->img, pixel, y, color);
		y++;
	}
	// printf("y:%d pixel:%d\n", y, pixel);
}
