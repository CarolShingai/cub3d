/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_collectibles_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:56:38 by cshingai          #+#    #+#             */
/*   Updated: 2025/03/28 19:48:18 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

// void draw_collectible(t_dda *ray, t_game *game)
// {
// 	int	draw_starty;
// 	int	draw_endy;
// 	int	sprite_height;

// 	mlx_texture_t *tex = game->texture.collectible;

// 	collect_dimensions(ray, &draw_starty, &draw_endy, &sprite_height);
// 	render_collectible(game, draw_starty, draw_endy, sprite_height, tex);
// }

// void	collect_dimensions(t_dda *ray, int *draw_starty, int *draw_endy, int *sprite_height)
// {
// 	*sprite_height = HEIGHT / ray->collectible_dist;
// 	*draw_starty = fmax(0, HEIGHT / 2 - *sprite_height / 2);
// 	*draw_endy = fmax(0, HEIGHT / 2 - *sprite_height / 2);
// }

// void	render_collectible(t_game *game, int draw_starty, int draw_endy, int sprite_height, mlx_texture_t *tex)
// {
// 	int	x;
// 	int	y;
// 	int	tex_x;
// 	int	tex_y;

// 	uint32_t color;
// 	x = game->ray.collec_start;
// 	while(x <= game->ray.collec_end)
// 	{
// 		y = draw_starty;
// 		while (y < draw_endy)
// 		{
// 			tex_x = (x - game->ray.collec_start) * tex->width / (game->ray.collec_start - game->ray.collec_end + 1);
// 			tex_y = (y - draw_starty) * tex->height / sprite_height;
// 			color = get_pixel_color(tex, tex_x, tex_y);
// 			if (color == 0)
// 				continue;
// 			mlx_put_pixel(game->imgs.img, x, y, color);
// 			y++;
// 		}
// 		x++;
// 	}
// }

void draw_collectible(t_dda *ray, t_game *game)
{
	mlx_texture_t *tex = game->texture.collectible;

	if (!ray->has_collectible || ray->collectible_dist == HUGE_VALF)
		return;
	if (!tex)
		return;
	int sprite_height = HEIGHT / ray->collectible_dist;
	int draw_start_y = fmax(0, HEIGHT / 2 - sprite_height / 2);
	int draw_end_y = fmin(HEIGHT, HEIGHT / 2 + sprite_height / 2);
		for (int x = ray->collec_start; x <= ray->collec_end; x++)
		{
			for (int y = draw_start_y; y < draw_end_y; y++)
			{
				int tex_x = (x - ray->collec_start) * tex->width / (ray->collec_end - ray->collec_start + 1);
				int tex_y = (y - draw_start_y) * tex->height / sprite_height;
				uint32_t color = get_pixel_color(tex, tex_x, tex_y);
				if (color  == 0)
					continue ;
				mlx_put_pixel(game->imgs.img, x, y, color);
			}
		}
}
