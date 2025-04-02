/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:04:11 by cshingai          #+#    #+#             */
/*   Updated: 2025/04/02 17:51:05 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	draw_wall(t_dda *ray, t_game *game, int pixel)
{
	mlx_texture_t	*wall_img;
	t_wall			wall;

	game->z_buffer[pixel] = ray->perpen_dist;
	wall.wall_height = HEIGHT / ray->perpen_dist;
	wall.line_starty = fmax(0, (HEIGHT / 2 - wall.wall_height / 2));
	wall.line_endy = fmin(HEIGHT, (HEIGHT / 2 + wall.wall_height / 2));
	set_wall_position(ray);
	wall_img = get_texture(ray, game);
	calc_tex_position(&wall, ray, wall_img, game);
	draw_texture_column(game, wall_img, pixel, &wall);
}

void	draw_texture_column(t_game *game, mlx_texture_t *texture,
	int pixel, t_wall *wall)
{
	uint32_t	color;
	int			y;

	y = wall->line_starty;
	while (y < wall->line_endy)
	{
		wall->tex_y = (int)((y - (HEIGHT / 2 - wall->wall_height / 2))
				/ (double)wall->wall_height * texture->height);
		wall->tex_y = fmax(0, fmin(wall->tex_y, texture->height - 1));
		color = get_pixel_color(texture, wall->tex_x, wall->tex_y);
		if (color != 0)
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
	if (game->cub3d.map[ray->map.y][ray->map.x] == 'X')
		return (game->texture.exit);
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
	if (game->cub3d.map[ray->map.y][ray->map.x] == 'C')
		wall->tex_x = (int)(fmod(ray->hit_pos.x + ray->hit_pos.y, 1.0)
				* wall_img->width);
	if (ray->hit_side == 1)
		wall->tex_x = (int)((ray->hit_pos.x - floor(ray->hit_pos.x))
				* wall_img->width);
	else
		wall->tex_x = (int)((ray->hit_pos.y - floor(ray->hit_pos.y))
				* wall_img->width);
}
