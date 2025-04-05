/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_dda_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 19:52:52 by cshingai          #+#    #+#             */
/*   Updated: 2025/04/04 20:01:20 by cshingai         ###   ########.fr       */
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

void	update_collectible_pos_pixel(t_dda *ray, t_game *game, int pixel)
{
	(void)game;
	if (ray->is_collect_start)
	{
		ray->is_collect_start = 0;
		ray->collec_start = pixel;
	}
	else
		ray->collec_end = pixel;
}
