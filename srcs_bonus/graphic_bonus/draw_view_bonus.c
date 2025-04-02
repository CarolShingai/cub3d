/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 22:29:08 by cshingai          #+#    #+#             */
/*   Updated: 2025/04/02 19:48:22 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	draw_view(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	update_time(game);
	reset_zbuffer(game);
	clear_image(game->imgs.img, 0x000000);
	draw_rays(game);
}

void	clear_image(mlx_image_t *img, uint32_t color)
{
	uint32_t	*pixels;
	size_t		total;

	pixels = (uint32_t *)img->pixels;
	total = img->width * img->height;
	ft_memset_32(pixels, color, total);
}

void	reset_zbuffer(t_game *game)
{
	int	pixel;

	pixel = 0;
	while (pixel < WIDTH)
	{
		game->z_buffer[pixel] = HUGE_VALF;
		pixel++;
	}
}

void	update_time(t_game *game)
{
	static double	last_time;
	double			current_time;
	double			delta_time;

	last_time = 0;
	current_time = mlx_get_time();
	delta_time = current_time - last_time;
	game->animation.time += delta_time;
	last_time = current_time;
}
