/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:44:27 by cshingai          #+#    #+#             */
/*   Updated: 2025/04/02 19:43:56 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	moviments(t_game *game, keys_t key)
{
	t_vector	new_pos;

	game->mov = 1;
	new_pos = create_vector(game->view.player_pos.x, game->view.player_pos.y);
	get_new_pos(game, key, &new_pos);
	if (!collision(game, &new_pos))
	{
		check_exit(game, new_pos);
		check_collision_collectable(game, &new_pos, 0.001);
		game->view.player_pos.x = new_pos.x;
		game->view.player_pos.y = new_pos.y;
		game->imgs.player->instances[0].x = MINIMAP_START_X
			+ (game->view.player_pos.x * TILE);
		game->imgs.player->instances[0].y = MINIMAP_START_Y
			+ (game->view.player_pos.y * TILE);
	}
	if (key == MLX_KEY_LEFT || key == MLX_KEY_RIGHT)
		camera_rotation(game, key, game->view.rotate_speed);
}

void	get_new_pos(t_game *game, keys_t key, t_vector *new_pos)
{
	double		m_speed;

	m_speed = game->view.mov_speed;
	if (key == MLX_KEY_W || key == MLX_KEY_S)
		vertical_moviments(game, key, m_speed, new_pos);
	else if (key == MLX_KEY_A || key == MLX_KEY_D)
		horizontal_moviments(game, key, m_speed, new_pos);
}

void	vertical_moviments(t_game *game, keys_t key,
	double m_speed, t_vector *new_pos)
{
	if (key == MLX_KEY_W)
	{
		new_pos->x += game->view.player_dir.x * m_speed;
		new_pos->y += game->view.player_dir.y * m_speed;
	}
	else if (key == MLX_KEY_S)
	{
		new_pos->x -= game->view.player_dir.x * m_speed;
		new_pos->y -= game->view.player_dir.y * m_speed;
	}
}

void	horizontal_moviments(t_game *game, keys_t key,
	double m_speed, t_vector *new_pos)
{
	if (key == MLX_KEY_A)
	{
		new_pos->x -= game->view.camera_plane.x * m_speed;
		new_pos->y -= game->view.camera_plane.y * m_speed;
	}
	else if (key == MLX_KEY_D)
	{
		new_pos->x += game->view.camera_plane.x * m_speed;
		new_pos->y += game->view.camera_plane.y * m_speed;
	}
}

void	camera_rotation(t_game *game, keys_t key, double angle)
{
	if (key == MLX_KEY_LEFT)
		angle = -angle;
	game->view.player_dir = rotate(game->view.player_dir, angle);
	game->view.camera_plane = rotate(game->view.camera_plane, angle);
}
