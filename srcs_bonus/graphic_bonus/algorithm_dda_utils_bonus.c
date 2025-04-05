/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_dda_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 19:52:52 by cshingai          #+#    #+#             */
/*   Updated: 2025/04/05 12:18:35 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	init_rays(t_dda *ray, int pixel)
{
	ray[pixel].has_collectible = 0;
	ray[pixel].collectible_dist = HUGE_VALF;
	ray[pixel].is_collect_start = 1;
}

void	update_ray_map(t_game *game, t_dda *ray)
{
	ray->map.x = game->view.player_pos.x;
	ray->map.y = game->view.player_pos.y;
}

int	is_collectible(t_dda *ray, t_game *game)
{
	if (game->cub3d.map[ray->map.y][ray->map.x] == 'C')
		return (1);
	if (game->cub3d.map[ray->map.y][ray->map.x] == 'B')
		return (1);
	if (game->cub3d.map[ray->map.y][ray->map.x] == 'A')
		return (1);
	if (game->cub3d.map[ray->map.y][ray->map.x] == 'K')
		return (1);
	return (0);
}
