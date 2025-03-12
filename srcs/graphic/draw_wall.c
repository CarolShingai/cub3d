/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:04:11 by cshingai          #+#    #+#             */
/*   Updated: 2025/03/12 19:05:21 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_wall(t_dda ray, t_game *game, int pixel)
{
	// mlx_image_t *wall_img;
	t_wall	wall;
	uint32_t	color;
	(void)game;
	(void)pixel;
	int y;

	wall.wall_height = HEIGHT / ray.perpen_dist;
	// printf("wall_height: %d\n", wall.wall_height);
	wall.line_starty = fmax(0, (HEIGHT / 2 - wall.wall_height / 2));
	// printf("line_starty: %d\n", wall.line_starty);
	wall.line_endy = fmin(HEIGHT, (HEIGHT / 2 + wall.wall_height / 2));
	// printf("line_endy: %d\n", wall.line_endy);
	y = wall.line_starty;
	while (y < wall.line_endy)
	{
		color = get_rgb(255,0,0);
		mlx_put_pixel(game->img, pixel, y, color);
		y++;
	}
}
