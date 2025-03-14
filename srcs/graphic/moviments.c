/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:44:27 by cshingai          #+#    #+#             */
/*   Updated: 2025/03/14 19:12:23 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void    moviments(t_game *game, keys_t key)
{
	double		m_speed;

	m_speed = game->view.mov_speed;
	if (key == MLX_KEY_W)
	{
		game->view.player_pos.x -= game->view.player_dir.x * m_speed;
		game->view.player_pos.y -= game->view.player_dir.y * m_speed;
	}
	else if (key == MLX_KEY_S)
	{
		game->view.player_pos.x += game->view.player_dir.x * m_speed;
		game->view.player_pos.y += game->view.player_dir.y * m_speed;
	}
	else if (key == MLX_KEY_A)
	{
		game->view.player_pos.x -= game->view.player_dir.x * m_speed;
		game->view.player_pos.y -= game->view.player_dir.y * m_speed;
	}
	else if (key == MLX_KEY_D)
	{
		game->view.player_pos.x -= game->view.player_dir.x * m_speed;
		game->view.player_pos.y -= game->view.player_dir.y * m_speed;
	}	
}