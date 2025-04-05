/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments_restriction_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:24:32 by cshingai          #+#    #+#             */
/*   Updated: 2025/04/05 04:48:33 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

static int	verify_signal(float value)
{
	if (value < 0)
		return (-1);
	return (1);
}

int	collision(t_game *game, t_vector *new_pos)
{
	float	margin;

	margin = COLISION_MARGIN;
	if (check_collision_mov(game, new_pos, margin))
		return (1);
	if (check_collision_camera(game, new_pos, margin))
		return (1);
	return (0);
}

int	check_collision_mov(t_game *game, t_vector *new_pos, float margin)
{
	int		x;
	int		y;

	x = (int)(new_pos->x + margin * verify_signal(new_pos->x
				- game->view.player_pos.x));
	y = (int)(new_pos->y + margin * verify_signal(new_pos->y
				- game->view.player_pos.y));
	if (game->cub3d.map[(int)new_pos->y][x] == '1'
		|| game->cub3d.map[(int)new_pos->y][x] == ' '
		|| (game->cub3d.map[(int)new_pos->y][x] == 'X'
		&& game->key_collect == 0))
		return (1);
	if (game->cub3d.map[y][(int)new_pos->x] == '1'
		|| game->cub3d.map[y][(int)new_pos->x] == ' '
		|| (game->cub3d.map[y][(int)new_pos->x] == 'X'
		&& game->key_collect == 0))
		return (1);
	return (0);
}

int	check_collision_camera(t_game *game, t_vector *new_pos, float margin)
{
	int		x_cam;
	int		y_cam;

	x_cam = (int)(new_pos->x + margin
			* verify_signal(game->view.camera_plane.x));
	y_cam = (int)(new_pos->y + margin
			* verify_signal(game->view.camera_plane.y));
	if (game->cub3d.map[(int)new_pos->y][x_cam] == '1'
		|| game->cub3d.map[(int)new_pos->y][x_cam] == ' ')
		return (1);
	if (game->cub3d.map[y_cam][(int)new_pos->x] == '1'
		|| game->cub3d.map[y_cam][(int)new_pos->x] == ' ')
		return (1);
	return (0);
}

void	check_collision_collectable(t_game *game, t_vector *new_pos,
		float margin)
{
	int	x;
	int	y;

	x = (int)(new_pos->x + margin * verify_signal(new_pos->x
				- game->view.player_pos.x));
	y = (int)(new_pos->y + margin * verify_signal(new_pos->y
				- game->view.player_pos.y));
	if (game->cub3d.map[y][x] == 'C' || game->cub3d.map[y][x] == 'B')	
		collect_item(game, x, y);
}
