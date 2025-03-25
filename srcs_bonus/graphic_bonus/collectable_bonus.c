/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectable_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:01:52 by cshingai          #+#    #+#             */
/*   Updated: 2025/03/25 19:02:43 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	init_collectables(t_game *game)
{
	int i;

	i = 0;
	game->num_collectibles = count_collectibles(game);
	while (i <= MAXCOLLECTIBLES)
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
				itens.pos = create_vector(x, y);
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
	x = 0;
	while (game->cub3d.map[x])
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
	while (i < game->num_collectibles)
	{
		if (!game->collectibles[i].collected &&
			(int)game->collectibles[i].pos.x == ray->map.x &&
			(int)game->collectibles[i].pos.y == ray->map.y)
		{
			game->collectibles[i].collected = 1;
			draw_collectible(ray, game, i); // Renderiza o sprite
		}
		i++;
	}
}
