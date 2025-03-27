/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_collectibles_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:56:38 by cshingai          #+#    #+#             */
/*   Updated: 2025/03/26 22:05:49 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	insert_collectible(t_game *game)
{
	game->imgs.collectible = create_image(game->mlx, "textures/Lumon_case/collectible.png");
}

void draw_collectible(t_dda *ray, t_game *game)
{
    if (!ray->has_collectible || ray->collectible_dist == HUGE_VALF)
        return;

    mlx_texture_t *tex = game->texture.collectible;
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

            if (color != 0xFF000000) // Ignora pixels transparentes
                mlx_put_pixel(game->imgs.img, x, y, color);
        }
    }
}

