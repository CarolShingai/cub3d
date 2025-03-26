/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectable_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:01:52 by cshingai          #+#    #+#             */
/*   Updated: 2025/03/25 21:04:28 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	init_collectables(t_game *game)
{
	int i;

	i = 0;
	game->num_collectibles = count_collectibles(game);
	// printf("num_collectibles: %d\n", game->num_collectibles);
	while (i <= game->num_collectibles)
	{
		game->collectibles[i].pos = create_vector(-1, -1);
		game->collectibles[i].collected = 0;
		get_collects_pos(game, game->collectibles[i]);
		i++;
	}
}

void	get_collects_pos(t_game *game, t_collectible itens)
{
	int	x;
	int	y;

	x = -1;
	while (game->cub3d.map[++x])
	{
		y = 0;
		while (game->cub3d.map[x][y])
		{
			if (game->cub3d.map[x][y] == 'C')
			{
				itens.pos = create_vector(x + 0.5,  y + 0.5);
				itens.collected = 0;
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
		while(game->cub3d.map[x][y])
		{
			if (game->cub3d.map[x][y] == 'C')
				count++;
			y++;
		}
	}
	return (count);
}

void	collect_item(t_game *game, int x, int y)
{
		game->cub3d.map[y][x] = '0';
}

void	check_collectible(t_dda *ray, t_game *game)
{
	int i;

	i = 0;
	// printf("num_collectibles: %d %d\n", game->num_collectibles, i);
	while (i <= game->num_collectibles)
	{
		printf("map[%d][%d]: %c\n", ray->map.y, ray->map.x, game->cub3d.map[ray->map.y][ray->map.x]);
		printf("map[%f][%f]:\n", game->collectibles[i].pos.x, game->collectibles[i].pos.y);
		if (!game->collectibles[i].collected &&
			(int)game->collectibles[i].pos.x == ray->map.x &&
			(int)game->collectibles[i].pos.y == ray->map.y)
		{
			printf("collectible\n");
			game->collectibles[i].collected = 1;
			draw_collectible(ray, game);
		}
		i++;
	}
}
