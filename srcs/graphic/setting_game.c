/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 21:55:26 by cshingai          #+#    #+#             */
/*   Updated: 2025/03/13 19:31:04 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	initial_plane(t_game *game)
{
	if (game->pov == 'N')
	{
		game->view.player_dir = create_vector(0, -1);
		game->view.camera_plane = create_vector(0.66, 0);
	}
	else if (game->pov == 'S')
	{
		game->view.player_dir = create_vector(0, 1);
		game->view.camera_plane = create_vector(-0.66, 0);
	}
	else if (game->pov == 'E')
	{
		game->view.player_dir = create_vector(1, 0);
		game->view.camera_plane = create_vector(0, 0.66);
	}
	else if (game->pov == 'W')
	{
		game->view.player_dir = create_vector(-1, 0);
		game->view.camera_plane = create_vector(0, -0.66);
	}
}

void	set_position(t_game *game)
{
	//alterar depois
	game->pov = game->cub3d.start_dir;
	game->view.player_pos.x = game->cub3d.start_pos_x + 0.5;
	game->view.player_pos.y = game->cub3d.start_pos_y + 0.5;
	// static char *map[] = {
    //     "111111111111111111111111",
    //     "1000000E0000111100000001",
    //     "111011111101000101111111",
    //     "100010000001010100000001",
    //     "101110111101010101110101",
    //     "100000100001000100000001",
    //     "101111101111011111101111",
    //     "100000100000010000100001",
    //     "101111111011011011111101",
    //     "100000001010101000000001",
    //     "101111111010101011111101",
    //     "100000000000000000000001",
    //     "111111111111111111111111",
    //     NULL
    // };

    // game->cub3d.map = map;
	initial_plane(game);
}
