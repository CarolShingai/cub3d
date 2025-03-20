/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_dda.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:04:02 by cshingai          #+#    #+#             */
/*   Updated: 2025/03/20 04:14:46 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_rays(t_game *game)
{
	int pixel;
	t_vector camera_pixel;
	float	multiplier;
	t_dda	ray;

	pixel = 0;
	while (pixel < WIDTH)
	{
		multiplier = 2 * pixel / (float)WIDTH - 1;
		camera_pixel = mult_vector(game->view.camera_plane, multiplier);
		ray.ray_dir = add_vector(game->view.player_dir, camera_pixel);
		// printf("vector x:%f y:%f\n", game->view.player_dir.x, game->view.player_dir.y);
		// printf("ray_dirx: %f raydiry: %f\n", ray.ray_dir.x, ray.ray_dir.y);
		// calcule of distance between column and lines
		calcule_delta_dist(&ray);
		calcule_dist_to_side(&ray, game);
		// printf("distx: %f disty: %f\n", ray.dist_to_side.x, ray.dist_to_side.y);
		// algorithm dda
		algorithm_dda(&ray, game);
		// renderizar parede
		draw_wall(&ray, game, pixel);
		pixel++;
	}
}

void	calcule_delta_dist(t_dda *ray)
{
	if (ray->ray_dir.x == 0)
		ray->delta_dist.x = HUGE_VALF;
	else
	ray->delta_dist.x = fabsf(1/ ray->ray_dir.x);
	if (ray->ray_dir.y == 0)
	ray->delta_dist.y = HUGE_VALF;
	else
	ray->delta_dist.y = fabsf(1/ ray->ray_dir.y);
	// printf("delta_distx: %f delta_disty: %f\n", ray->delta_dist.x, ray->delta_dist.y);
}

void	calcule_dist_to_side(t_dda *ray, t_game *game)
{
	update_ray_map(game, ray);
	if (ray->ray_dir.x < 0)
	{
		ray->dist_to_side.x = (game->view.player_pos.x - ray->map.x) * ray->delta_dist.x;
		ray->step.x = -1;
	}
	else
	{
		ray->dist_to_side.x = (ray->map.x + 1 - game->view.player_pos.x) * ray->delta_dist.x;
		ray->step.x = 1;
	}
	if (ray->ray_dir.y < 0)
	{
		ray->dist_to_side.y = (game->view.player_pos.y - ray->map.y) * ray->delta_dist.y;
		ray->step.y = -1;
	}
	else
	{
		ray->dist_to_side.y = (ray->map.y + 1 - game->view.player_pos.y ) * ray->delta_dist.y;
		ray->step.y = 1;
	}
	// printf("map[%d][%d]\n", ray->map.x, ray->map.y);
	// printf("dist_sidex: %f, dist_sidey: %f\n", ray->dist_to_side.x, ray->dist_to_side.y);
}

//map vazio
void	algorithm_dda(t_dda *ray, t_game *game)
{
	ray->hit_side = -1;
	while (game->cub3d.map[ray->map.y][ray->map.x] != '1')
	{
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
	// printf("hit_side: %d", ray->hit_side);
	// printf("map[%d][%d]\n", ray->map.x, ray->map.y);
	// printf("ray_dirx: %f raydiry: %f\n", ray->ray_dir.x, ray->ray_dir.y);
	// printf("perp: %f\n", ray->perpen_dist);
}

void	update_ray_map(t_game *game, t_dda *ray)
{
	ray->map.x = game->view.player_pos.x;
	ray->map.y = game->view.player_pos.y;
}
