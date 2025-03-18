/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments_restriction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:24:32 by cshingai          #+#    #+#             */
/*   Updated: 2025/03/17 22:05:40 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	verify_signal(float value)
{
	if (value < 0)
		return (-1);
	return (1);
}
int	collision(t_game *game, t_vector *new_pos)
{
	int		x;
	int		y;
	int		x_cam;
	int		y_cam;
	float	margin;

	margin = 0.2;
	x = (int)(new_pos->x + margin *
		verify_signal(new_pos->x - game->view.player_pos.x));
	y = (int)(new_pos->y + margin *
		verify_signal(new_pos->y - game->view.player_pos.y));
	x_cam = (int)(new_pos->x + margin * verify_signal(game->view.camera_plane.x));
	y_cam = (int)(new_pos->y + margin * verify_signal(game->view.camera_plane.y));
	if (game->cub3d.map[(int)new_pos->y][x] == '1'
		|| game->cub3d.map[(int)new_pos->y][x] == ' ')
		return (1);
	if (game->cub3d.map[y][(int)new_pos->x] == '1'
		|| game->cub3d.map[y][(int)new_pos->x] == ' ')
		return (1);
	if (game->cub3d.map[(int)new_pos->y][x_cam] == '1'
		|| game->cub3d.map[(int)new_pos->y][x_cam] == ' ')
		return (1);
	if (game->cub3d.map[y_cam][(int)new_pos->x] == '1'
		|| game->cub3d.map[y_cam][(int)new_pos->x] == ' ')
		return (1);
	return (0);
}
