/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_collectibles_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:56:38 by cshingai          #+#    #+#             */
/*   Updated: 2025/04/05 04:13:01 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

mlx_texture_t	*get_collectible_texture(t_dda *ray, t_game *game)
{
	if (game->cub3d.map[ray->collec_y][ray->collec_x] == 'B')
		return (game->texture.collectible_1);
	else
		return (game->texture.collectible_0);
}

void	draw_collectible(t_dda *ray, t_game *game, int pixel)
{
	mlx_texture_t	*tex;
	t_wall			wall;

	tex = get_collectible_texture(ray, game);
	if (ray->has_collectible == 0 || !tex)
		return ;
	if (ray->collectible_dist >= game->z_buffer[pixel] - 0.01)
		return ;
	wall.wall_height = HEIGHT / ray->collectible_dist;
	wall.line_starty = fmax(0, (HEIGHT - wall.wall_height) / 2);
	wall.line_endy = fmin(HEIGHT, (HEIGHT + wall.wall_height) / 2);
	wall.collec_dist = ray->collectible_dist;
	if (ray->hit_side == 1)
		wall.tex_x = (int)((game->view.player_pos.x
					+ ray->collectible_dist * ray->ray_dir.x)
				* tex->width) % tex->width;
	else
		wall.tex_x = (int)((game->view.player_pos.x
					+ ray->collectible_dist * ray->ray_dir.x)
				* tex->width) % tex->width;
	wall.tex_x = fmax(10, fmin(wall.tex_x, tex->width - 1));
	draw_transparent_column(game, tex, pixel, &wall);
}

void	draw_transparent_column(t_game *game, mlx_texture_t *texture,
	int pixel, t_wall *wall)
{
	uint32_t	color;
	int			y;

	y = wall->line_starty;
	while (y < wall->line_endy)
	{
		if (wall->collec_dist < game->z_buffer[pixel])
		{
			wall->tex_y = (int)((y - (HEIGHT / 2 - wall->wall_height / 2))
					/ (double)wall->wall_height * texture->height);
			wall->tex_y = fmax(0, fmin(wall->tex_y, texture->height - 1));
			color = get_pixel_color(texture, wall->tex_x, wall->tex_y);
			if (color != 0)
				mlx_put_pixel(game->imgs.img, pixel, y, color);
		}
		y++;
	}
}
