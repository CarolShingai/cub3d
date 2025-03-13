/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 22:29:08 by cshingai          #+#    #+#             */
/*   Updated: 2025/03/13 02:17:02 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_view(void *param)
{
	t_game *game;

	game = (t_game *)param;
	draw_rays(game);
	mlx_put_pixel(game->img, 100, HEIGHT -50, get_rgb(255, 255, 255));
}
