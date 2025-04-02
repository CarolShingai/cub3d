/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_collectibles_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:56:38 by cshingai          #+#    #+#             */
/*   Updated: 2025/04/02 20:25:12 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

//colocar uma flag para indicar o que atingiu
void	draw_sprite(t_dda *ray, t_game *game)
{
	t_sprite		sprite;
	mlx_texture_t	*sprite_img;

	if (!ray->has_collectible || ray->collectible_dist == HUGE_VALF)
		return ;
	sprite_img = game->texture.collectible_0;
	if (!sprite_img)
		return ;
	sprite_dimensions(ray, &sprite);
	draw_sprite_column(game, ray, &sprite, sprite_img);
}

void	sprite_dimensions(t_dda *ray, t_sprite *sprite)
{
	sprite->sprite_height = HEIGHT / ray->collectible_dist;
	sprite->draw_starty = fmax(0, (HEIGHT / 2) - (sprite->sprite_height / 2));
	sprite->draw_endy = fmin(HEIGHT, (HEIGHT / 2) + (sprite->sprite_height / 2));
}

void	draw_sprite_column(t_game *game, t_dda *ray, t_sprite *sprite, mlx_texture_t *tex)
{
	int			pixel;
	int			y;
	uint32_t	color;

	pixel = ray->collec_start;
	while (pixel <= ray->collec_end)
	{
		y = sprite->draw_starty;
		while (y < sprite->draw_endy)
		{
			sprite->tex_x = (pixel - ray->collec_start) * tex->width / (ray->collec_end - ray->collec_start + 1);
			sprite->tex_y = (y - sprite->draw_starty) * tex->height / sprite->sprite_height;
			color = get_pixel_color(tex, sprite->tex_x, sprite->tex_y);
			if (color != 0)
				mlx_put_pixel(game->imgs.img, pixel, y, color);
			y++;
		}
		pixel++;
	}
}

void	draw_collectible(t_dda *ray, t_game *game, int pixel)
{
	mlx_texture_t	*tex;
	t_wall			wall;

	tex = game->texture.collectible_0;
	if (ray->has_collectible == 0 || !tex)
		return ;
	if (ray->collectible_dist >= game->z_buffer[pixel])
		return ;
	wall.wall_height = HEIGHT / ray->collectible_dist;
	wall.line_starty = fmax(0, (HEIGHT - wall.wall_height) / 2);
	wall.line_endy = fmin(HEIGHT, (HEIGHT + wall.wall_height) / 2);
	if (ray->hit_side == 1)
		wall.tex_x = (int)((game->view.player_pos.x
			+ ray->collectible_dist * ray->ray_dir.x) * tex->width) % tex->width;
	else
		wall.tex_x = 0;
	wall.tex_x = fmax(10, fmin(wall.tex_x, tex->width - 1));
	draw_transparent_column(game, ray, tex, pixel, &wall);
}

void	draw_transparent_column(t_game *game, t_dda *ray,
		mlx_texture_t *texture, int pixel, t_wall *wall)
{
	uint32_t	color;
	int			y;

	y = wall->line_starty;
	(void)ray;
	while (y < wall->line_endy)
	{
		if (ray->collectible_dist < game->z_buffer[pixel])
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
