/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_game_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 21:55:26 by cshingai          #+#    #+#             */
/*   Updated: 2025/04/01 02:31:16 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	initial_plane(t_game *game)
{
	float	f;

	f = game->view.fov;
	if (game->pov == 'N')
	{
		game->view.player_dir = create_vector(0, -1);
		game->view.camera_plane = create_vector(f, 0);
	}
	else if (game->pov == 'S')
	{
		game->view.player_dir = create_vector(0, 1);
		game->view.camera_plane = create_vector(-f, 0);
	}
	else if (game->pov == 'E')
	{
		game->view.player_dir = create_vector(1, 0);
		game->view.camera_plane = create_vector(0, f);
	}
	else if (game->pov == 'W')
	{
		game->view.player_dir = create_vector(-1, 0);
		game->view.camera_plane = create_vector(0, -f);
	}
}

void	set_position(t_game *game)
{
	game->pov = game->cub3d.start_dir;
	game->view.player_pos.x = game->cub3d.start_pos_x + 0.5;
	game->view.player_pos.y = game->cub3d.start_pos_y + 0.5;
	game->view.fov = FOV;
	game->view.mov_speed = MOV_SPEED;
	game->view.rotate_speed = ROTATE_SPEED;
	initial_plane(game);
}
