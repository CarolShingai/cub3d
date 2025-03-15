/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 22:29:08 by cshingai          #+#    #+#             */
/*   Updated: 2025/03/14 22:00:44 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_view(void *param)
{
	t_game *game;

	game = (t_game *)param;
	mlx_key_hook(game->mlx, &key_action, game);
	draw_rays(game);
	remove_frames(game);
}

void	remove_frames(t_game *game)
{
	int frame_count;

	game->frame_time = &game->mlx->delta_time;
	frame_count = 0;
	frame_count++;
	if (frame_count % 100 == 0)
	{
		mlx_delete_image(game->mlx, game->imgs.img);
		// mlx_delete_image(game->mlx, game->imgs.img_ceiling);
		// mlx_delete_image(game->mlx, game->imgs.img_floor);
		game->imgs.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
		frame_count = 0;
	}
}
