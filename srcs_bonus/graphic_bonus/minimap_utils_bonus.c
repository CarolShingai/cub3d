/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:04:03 by cshingai          #+#    #+#             */
/*   Updated: 2025/04/02 20:05:23 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

int	is_player(t_game *game, int x, int y)
{
	if (game->cub3d.map[x][y] == 'N' || game->cub3d.map[x][y] == 'S' ||
		game->cub3d.map[x][y] == 'E' || game->cub3d.map[x][y] == 'W')
		return (1);
	else
		return (0);
}

void	setting_minimap(t_game *game)
{
	insert_minimap(game);
	draw_map(game);
	game->imgs.minimap->instances->enabled = 0;
	game->imgs.miniwall_x->enabled = 0;
	game->imgs.miniwall_y->enabled = 0;
	game->imgs.block->enabled = 0;
	game->imgs.player->enabled = 0;
}

	void	clear_minimap(t_game *game)
{
	if (game->imgs.minimap)
		mlx_delete_image(game->mlx, game->imgs.minimap);
	if (game->imgs.miniwall_x)
		mlx_delete_image(game->mlx, game->imgs.miniwall_x);
	if (game->imgs.miniwall_y)
		mlx_delete_image(game->mlx, game->imgs.miniwall_y);
	if (game->imgs.block)
		mlx_delete_image(game->mlx, game->imgs.block);
	if (game->imgs.player)
		mlx_delete_image(game->mlx, game->imgs.player);
}
