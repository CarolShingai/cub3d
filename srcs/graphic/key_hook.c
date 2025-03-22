/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:59:02 by cshingai          #+#    #+#             */
/*   Updated: 2025/03/22 03:35:41 by cshingai         ###   ########.fr       */
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
	// if (keydata.key == MLX_KEY_M && keydata.action == MLX_PRESS)
	// {

	// }
	// if (keydata.key == MLX_KEY_M && keydata.action == MLX_RELEASE)
	// 	remove_map(game);
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

void	remove_map(t_game *game)
{
	game->imgs.player->instances->enabled = 0;
	game->imgs.miniwall_x->instances->enabled = 0;
	game->imgs.miniwall_y->instances->enabled = 0;
	game->imgs.minimap->instances->enabled = 0;
}
