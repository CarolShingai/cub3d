/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:17:09 by cshingai          #+#    #+#             */
/*   Updated: 2025/04/05 12:15:56 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	ft_error(char *msg, t_game *game)
{
	ft_printf_fd(STDERR_FILENO, "%s", msg);
	if (game)
		clear_game(game);
	exit(EXIT_FAILURE);
}

void	clear_game(t_game *game)
{
	clear_textures(game);
	clear_minimap(game);
	if (game->z_buffer)
		free(game->z_buffer);
	mlx_close_window(game->mlx);
}

void	clear_textures(t_game *game)
{
	if (game->texture.north)
		mlx_delete_texture(game->texture.north);
	if (game->texture.south)
		mlx_delete_texture(game->texture.south);
	if (game->texture.west)
		mlx_delete_texture(game->texture.west);
	if (game->texture.east)
		mlx_delete_texture(game->texture.east);
	if (game->texture.exit)
		mlx_delete_texture(game->texture.exit);
	if (game->texture.collectible_0)
		mlx_delete_texture(game->texture.collectible_0);
	if (game->texture.collectible_1)
		mlx_delete_texture(game->texture.collectible_1);
	if (game->texture.collectible_2)
		mlx_delete_texture(game->texture.collectible_2);
	if (game->texture.key)
		mlx_delete_texture(game->texture.key);
}
