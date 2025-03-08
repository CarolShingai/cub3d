/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 21:55:26 by cshingai          #+#    #+#             */
/*   Updated: 2025/03/07 22:24:59 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	initial_plane(t_game *game)
{
	if (game->pov == 'N')
	{
		game->view.player_direction = create_vector(0, -1);
		game->view.camera_plane = create_vector(0.66, 0);
	}
	else if (game->pov == 'S')
	{
		game->view.player_direction = create_vector(0, 1);
		game->view.camera_plane = create_vector(-0.66, 0);
	}
	else if (game->pov == 'E')
	{
		game->view.player_direction = create_vector(1, 0);
		game->view.camera_plane = create_vector(0, 0.66);
	}
	else if (game->pov == 'W')
	{
		game->view.player_direction = create_vector(-1, 0);
		game->view.camera_plane = create_vector(0, -0.66);
	}
}
