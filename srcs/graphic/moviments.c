/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:44:27 by cshingai          #+#    #+#             */
/*   Updated: 2025/03/14 19:50:04 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	moviments(t_game *game, keys_t key)
{
	double		m_speed;

	m_speed = game->view.mov_speed;
	if (key == MLX_KEY_W)
	{
		game->view.player_pos.x += game->view.player_dir.x * m_speed;
		game->view.player_pos.y += game->view.player_dir.y * m_speed;
		printf("x: %f y: %f\n", game->view.player_pos.x, game->view.player_pos.y);
	}
	else if (key == MLX_KEY_S)
	{
		game->view.player_pos.x -= game->view.player_dir.x * m_speed;
		game->view.player_pos.y -= game->view.player_dir.y * m_speed;
		printf("x: %f y: %f\n", game->view.player_pos.x, game->view.player_pos.y);
	}
	else if (key == MLX_KEY_A)
	{
		game->view.player_pos.x -= game->view.player_dir.x * m_speed;
		game->view.player_pos.y -= game->view.player_dir.y * m_speed;
		printf("x: %f y: %f\n", game->view.player_pos.x, game->view.player_pos.y);
	}
	else if (key == MLX_KEY_D)
	{
		game->view.player_pos.x += game->view.player_dir.x * m_speed;
		game->view.player_pos.y += game->view.player_dir.y * m_speed;
		printf("x: %f y: %f\n", game->view.player_pos.x, game->view.player_pos.y);
	}
	else if (key == MLX_KEY_LEFT)
		camera_rotation(game, -game->view.rotate_speed);
	else if (key == MLX_KEY_RIGHT)
		camera_rotation(game, game->view.rotate_speed);
}

void	camera_rotation(t_game *game, double angle)
{
	game->view.player_dir.x = rotate(game->view.player_dir, angle).x;
	game->view.player_dir.y = rotate(game->view.player_dir, angle).y;
	game->view.camera_plane.x = rotate(game->view.camera_plane, angle).x;
	game->view.camera_plane.y = rotate(game->view.camera_plane, angle).y;
	printf("x: %f y: %f\n", game->view.camera_plane.x, game->view.camera_plane.y);
}
