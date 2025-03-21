/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:04:11 by cshingai          #+#    #+#             */
/*   Updated: 2025/03/21 05:00:21 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_wall(t_dda *ray, t_game *game, int pixel)
{
	uint32_t		color;
	mlx_texture_t	*wall_img;
	t_wall			wall;
	int				y;

	wall.wall_height = HEIGHT / ray->perpen_dist;
	wall.line_starty = fmax(0, (HEIGHT / 2 - wall.wall_height / 2));
	wall.line_endy = fmin(HEIGHT, (HEIGHT / 2 + wall.wall_height / 2));
	y = wall.line_starty;
	set_wall_position(ray);
	wall_img = get_texture(ray, game);
	calc_tex_position(&wall, ray, wall_img, game);
	while (y < wall.line_endy)
	{
		wall.tex_y = (int)((y - (HEIGHT / 2 - wall.wall_height / 2))
				/ (double)wall.wall_height * wall_img->height);
		wall.tex_y = fmax(0, fmin(wall.tex_y, wall_img->height - 1));
		color = get_pixel_color(wall_img, wall.tex_x, wall.tex_y);
		mlx_put_pixel(game->imgs.img, pixel, y, color);
		y++;
	}
}

void	set_wall_position(t_dda *ray)
{
	if (ray->hit_side == 1)
	{
		if (ray->ray_dir.y < 0)
			ray->side = NORTH;
		else
			ray->side = SOUTH;
	}
	else
	{
		if (ray->ray_dir.x < 0)
			ray->side = WEST;
		else
			ray->side = EAST;
	}
}

mlx_texture_t	*get_texture(t_dda *ray, t_game *game)
{
	if (ray->side == NORTH)
		return (game->texture.north);
	else if (ray->side == SOUTH)
		return (game->texture.south);
	else if (ray->side == WEST)
		return (game->texture.west);
	else if (ray->side == EAST)
		return (game->texture.east);
	else
		return (NULL);
}

void	calc_tex_position(t_wall *wall, t_dda *ray,
	mlx_texture_t *wall_img, t_game *game)
{
	ray->hit_pos.x = game->view.player_pos.x + (ray->ray_dir.x
			* ray->perpen_dist);
	ray->hit_pos.y = game->view.player_pos.y + (ray->ray_dir.y
			* ray->perpen_dist);
	if (ray->hit_side == 1)
		wall->tex_x = (int)((ray->hit_pos.x - floor(ray->hit_pos.x))
				* wall_img->width);
	else
		wall->tex_x = (int)((ray->hit_pos.y - floor(ray->hit_pos.y))
				* wall_img->width);
}

uint32_t	get_pixel_color(mlx_texture_t *tex, int x, int y)
{
	int			tex_pos;
	uint8_t		*color;
	uint32_t	final_color;

	if (x < 0 || x >= (int)tex->width || y < 0 || y >= (int)tex->height)
		return (0);
	tex_pos = (y * tex->width + x) * tex->bytes_per_pixel;
	color = &tex->pixels[tex_pos];
	final_color = (color[0] << 24) | (color[1] << 16)
		| (color[2] << 8) | color[3];
	return (final_color);
}
