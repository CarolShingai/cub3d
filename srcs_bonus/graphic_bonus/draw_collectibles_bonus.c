/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_collectibles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:56:38 by cshingai          #+#    #+#             */
/*   Updated: 2025/03/25 19:00:37 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	draw_collectible(t_dda *ray, t_game *game, int index)
{
	mlx_texture_t *sprite = game->texture.collectible;
	t_wall collectible;
	int y;

	collectible.wall_height = HEIGHT / ray->perpen_dist;
	collectible.line_starty = fmax(0, (HEIGHT / 2 - collectible.wall_height / 2));
	collectible.line_endy = fmin(HEIGHT, (HEIGHT / 2 + collectible.wall_height / 2));

	y = collectible.line_starty;
	while (y < collectible.line_endy)
	{
		int tex_y = (int)((y - (HEIGHT / 2 - collectible.wall_height / 2))
		/ (double)collectible.wall_height * sprite->height);
		tex_y = fmax(0, fmin(tex_y, sprite->height - 1));

		uint32_t color = get_pixel_color(sprite, 0, tex_y);
		mlx_put_pixel(game->imgs.img, ray->map.x, y, color);
		y++;
	}
}
