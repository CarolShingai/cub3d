/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:01:52 by cshingai          #+#    #+#             */
/*   Updated: 2025/03/25 17:40:26 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	draw_collectible(t_dda *ray, t_game *game)
{
	mlx_texture_t	*collect_img;
	t_wall			collect;
	int				y;
	uint32_t		color;

	// 🔹 Calcula altura e posição do coletável na tela
	collect.wall_height = HEIGHT / ray->perpen_dist;
	collect.line_starty = fmax(0, (HEIGHT / 2 - collect.wall_height / 2));
	collect.line_endy = fmin(HEIGHT, (HEIGHT / 2 + collect.wall_height / 2));
	y = collect.line_starty;

	// 🔹 Obtém a textura do coletável
	collect_img = game->texture.collectible;

	// 🔹 Calcula posição da textura na tela
	ray->hit_pos.x = game->view.player_pos.x + (ray->ray_dir.x * ray->perpen_dist);
	ray->hit_pos.y = game->view.player_pos.y + (ray->ray_dir.y * ray->perpen_dist);
	collect.tex_x = (int)((ray->hit_pos.x - floor(ray->hit_pos.x)) * collect_img->width);

	// 🔹 Desenha coletável pixel a pixel
	while (y < collect.line_endy)
	{
		collect.tex_y = (int)((y - (HEIGHT / 2 - collect.wall_height / 2))
				/ (double)collect.wall_height * collect_img->height);
		collect.tex_y = fmax(0, fmin(collect.tex_y, collect_img->height - 1));

		color = get_pixel_color(collect_img, collect.tex_x, collect.tex_y);
		mlx_put_pixel(game->imgs.img, ray->map.x, y, color);  // Desenha na posição correta
		y++;
	}
}