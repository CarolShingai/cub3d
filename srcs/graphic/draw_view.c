/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 22:29:08 by cshingai          #+#    #+#             */
/*   Updated: 2025/03/20 22:23:28 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_view(void *param)
{
	t_game	*game;
	int		time_frame;

	time_frame = 0;
	time_frame++;
	game = (t_game *)param;
	clear_image(game->imgs.img, 0x000000);
	draw_rays(game);
}

void	clear_image(mlx_image_t *img, uint32_t color)
{
	size_t		total;
	size_t		i;
	uint32_t	*pixels;

	total = (size_t)img->width * img->height;
	i = 0;
	pixels = (uint32_t *)img->pixels;
	while (i < total)
	{
		pixels[i] = color;
		i = i + 1;
	}
}
