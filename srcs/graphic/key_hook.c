/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:59:02 by cshingai          #+#    #+#             */
/*   Updated: 2025/03/22 04:54:01 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	key_action(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		close_game(game);
	if (player_keys(keydata.key) && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
			moviments(game, keydata.key);
	if (keydata.key == MLX_KEY_M && keydata.action == MLX_PRESS)
		visible_map(game);
	if (keydata.key == MLX_KEY_M && keydata.action == MLX_RELEASE)
		unvisible_map(game);
}

void	close_game(t_game *game)
{
	clear_textures(game);
	mlx_close_window(game->mlx);
}

int	player_keys(keys_t key)
{
	if (key == MLX_KEY_W || key == MLX_KEY_S || key == MLX_KEY_A || key == MLX_KEY_M
		|| key == MLX_KEY_D || key == MLX_KEY_LEFT || key == MLX_KEY_RIGHT)
		return (1);
	else
		return (0);
}

void	unvisible_map(t_game *game)
{
	game->imgs.minimap->instances->enabled = 0;
	game->imgs.miniwall_x->enabled = 0;
	game->imgs.miniwall_y->enabled = 0;
	game->imgs.player->enabled = 0;
}

void	visible_map(t_game *game)
{
	game->imgs.minimap->instances->enabled = 1;
	game->imgs.miniwall_x->enabled = 1;
	game->imgs.miniwall_y->enabled = 1;
	game->imgs.player->enabled = 1;
}