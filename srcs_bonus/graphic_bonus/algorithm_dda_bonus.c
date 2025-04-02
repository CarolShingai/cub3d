/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_dda_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:04:02 by cshingai          #+#    #+#             */
/*   Updated: 2025/04/01 19:19:46 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	draw_rays(t_game *game)
{
	t_dda		ray[WIDTH];
	int			pixel;
	t_vector	camera_pixel;
	float		multiplier;

	pixel = 0;
	ray[pixel].has_collectible = 0;
	ray[pixel].collectible_dist = HUGE_VALF;
	ray[pixel].is_collect_start = 1;
	while (pixel < WIDTH)
	{
		multiplier = 2 * pixel / (float)WIDTH - 1;
		camera_pixel = mult_vector(game->view.camera_plane, multiplier);
		ray[pixel].ray_dir = add_vector(game->view.player_dir, camera_pixel);
		calcule_delta_dist(&ray[pixel]);
		calcule_dist_to_side(&ray[pixel], game);
		algorithm_dda(&ray[pixel], game);
		draw_wall(&ray[pixel], game, pixel);
		// if (ray[pixel].has_collectible) //importante
		// 	update_collectible_pos_pixel(&ray[pixel], game, pixel);//importante
		pixel++;
	}
	pixel = 0;
    while (pixel < WIDTH)
    {
        if (ray[pixel].has_collectible && ray[pixel].collectible_dist < game->z_buffer[pixel])
            draw_collectible(&ray[pixel], game, pixel);
        pixel++;
    }
	// draw_sprite(&ray[pixel], game);
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


void	calcule_delta_dist(t_dda *ray)
{
	if (ray->ray_dir.x == 0)
		ray->delta_dist.x = HUGE_VALF;
	else
		ray->delta_dist.x = fabsf(1 / ray->ray_dir.x);
	if (ray->ray_dir.y == 0)
		ray->delta_dist.y = HUGE_VALF;
	else
	ray->delta_dist.y = fabsf(1 / ray->ray_dir.y);
}

void	calcule_dist_to_side(t_dda *ray, t_game *game)
{
	update_ray_map(game, ray);
	if (ray->ray_dir.x < 0)
	{
		ray->dist_to_side.x = (game->view.player_pos.x - ray->map.x)
			* ray->delta_dist.x;
		ray->step.x = -1;
	}
	else
	{
		ray->dist_to_side.x = (ray->map.x + 1 - game->view.player_pos.x)
			* ray->delta_dist.x;
		ray->step.x = 1;
	}
	if (ray->ray_dir.y < 0)
	{
		ray->dist_to_side.y = (game->view.player_pos.y - ray->map.y)
			* ray->delta_dist.y;
		ray->step.y = -1;
	}
	else
	{
		ray->dist_to_side.y = (ray->map.y + 1 - game->view.player_pos.y)
			* ray->delta_dist.y;
		ray->step.y = 1;
	}
}

void	algorithm_dda(t_dda *ray, t_game *game)
{
	ray->hit_side = -1;
	ray->has_collectible = 0;
	while (1)
	{
		if (game->cub3d.map[ray->map.y][ray->map.x] == '1'
				|| game->cub3d.map[ray->map.y][ray->map.x] == 'X')
			break;
		if (game->cub3d.map[ray->map.y][ray->map.x] == 'C' && !ray->has_collectible )
				check_collectible_dda(ray, game);
		if (ray->dist_to_side.x < ray->dist_to_side.y)
		{
			ray->dist_to_side.x += ray->delta_dist.x;
			ray->map.x += ray->step.x;
			ray->hit_side = 0;
		}
		else
		{
			ray->dist_to_side.y += ray->delta_dist.y;
			ray->map.y += ray->step.y;
			ray->hit_side = 1;
		}
	}
	if (ray->hit_side == 0)
		ray->perpen_dist = (ray->map.x - game->view.player_pos.x
		+ (1.0 - ray->step.x) / 2) / ray->ray_dir.x;
	else
		ray->perpen_dist = (ray->map.y - game->view.player_pos.y
			+ (1.0 - ray->step.y) / 2) / ray->ray_dir.y;
}

void	update_ray_map(t_game *game, t_dda *ray)
{
	ray->map.x = game->view.player_pos.x;
	ray->map.y = game->view.player_pos.y;
}
