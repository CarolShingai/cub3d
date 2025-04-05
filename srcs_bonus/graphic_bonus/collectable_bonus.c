/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectable_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:01:52 by cshingai          #+#    #+#             */
/*   Updated: 2025/04/05 12:22:22 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	init_collectables(t_game *game)
{
	int	i;

	i = 0;
	game->num_collectibles = count_collectibles(game);
	while (i <= game->num_collectibles)
	{
		game->collectibles[i].pos = create_vector(-1, -1);
		game->collectibles[i].collected = 0;
		get_collects_pos(game, &game->collectibles[i]);
		i++;
	}
}

void	get_collects_pos(t_game *game, t_collectible *itens)
{
	int	x;
	int	y;

	x = -1;
	while (game->cub3d.map[++x])
	{
		y = 0;
		while (game->cub3d.map[x][y])
		{
			if (game->cub3d.map[x][y] == 'C' || game->cub3d.map[x][y] == 'B'
			|| game->cub3d.map[x][y] == 'K' || game->cub3d.map[x][y] == 'A')
			{
				itens->pos = create_vector(x + 0.5, y + 0.5);
				itens->collected = 0;
				break ;
			}
			y++;
		}
	}
}

int	count_collectibles(t_game *game)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	x = -1;
	while (game->cub3d.map[++x])
	{
		y = 0;
		while (game->cub3d.map[x][y])
		{
			if (game->cub3d.map[x][y] == 'C' || game->cub3d.map[x][y] == 'B'
				|| game->cub3d.map[x][y] == 'A')
				count++;
			y++;
		}
	}
	return (count);
}

void	collect_item(t_game *game, int x, int y)
{
	if (game->cub3d.map[y][x] == 'K')
		game->key_collect = 1;
	game->cub3d.map[y][x] = '0';
	game->ray.has_collectible = false;
}

void	check_collectible_dda(t_dda *ray, t_game *game)
{
	(void)game;
	ray->has_collectible = true;
	ray->collec_x = ray->map.x;
	ray->collec_y = ray->map.y;
	if (ray->dist_to_side.x < ray->dist_to_side.y)
		ray->collectible_dist = ray->dist_to_side.x;
	else
		ray->collectible_dist = ray->dist_to_side.y;
	ray->collectible_pos = create_vector(ray->map.x, ray->map.y);
}
