/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectable_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:01:52 by cshingai          #+#    #+#             */
/*   Updated: 2025/03/26 21:20:44 by cshingai         ###   ########.fr       */
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
			if (game->cub3d.map[x][y] == 'C')
			{
				itens->pos = create_vector(x + 0.5,  y + 0.5);
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
	float	dist;

	dist = sqrt(pow(game->view.player_pos.x - ray->map.x, 2) +
				pow(game->view.player_pos.y - ray->map.y, 2));
	if (dist < ray->collectible_dist)
	{
		ray->collectible_dist = dist;
		ray->collectible_pos = create_vector(ray->map.x, ray->map.y);
		ray->has_collectible = true;
	}
}

void check_has_collectibles(t_game *game)
{
    for (int i = 0; i < game->num_collectibles; i++)
    {
        if (!game->collectibles[i].collected)
        {
            float dist = sqrt(pow(game->view.player_pos.x - game->collectibles[i].pos.x, 2) +
                              pow(game->view.player_pos.y - game->collectibles[i].pos.y, 2));

            if (dist < 0.5) // Distância mínima para coletar
            {
                game->collectibles[i].collected = true;
                // game->score++; // Atualiza pontuação, se houver
            }
        }
    }
}
