/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:59:02 by cshingai          #+#    #+#             */
/*   Updated: 2025/04/04 18:37:07 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	key_action(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		clear_game(game);
	if (player_keys(keydata.key) && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		moviments(game, keydata.key);
}

void	clear_game(t_game *game)
{
	mlx_close_window(game->mlx);
}

int	player_keys(keys_t key)
{
	if (key == MLX_KEY_W || key == MLX_KEY_S || key == MLX_KEY_A
		|| key == MLX_KEY_M || key == MLX_KEY_D || key == MLX_KEY_LEFT
		|| key == MLX_KEY_RIGHT)
		return (1);
	else
		return (0);
}
