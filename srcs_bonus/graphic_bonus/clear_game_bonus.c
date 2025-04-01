/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:17:09 by cshingai          #+#    #+#             */
/*   Updated: 2025/03/31 15:50:48 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void ft_error(char *msg)
{
	ft_printf_fd(STDERR_FILENO, "%s", msg);
	exit(EXIT_FAILURE);
}

void	clear_game(t_game *game)
{
	free(game->z_buffer);
	clear_textures(game);
	mlx_close_window(game->mlx);
}

void	clear_textures(t_game *game)
{
	mlx_delete_texture(game->texture.north);
	mlx_delete_texture(game->texture.south);
	mlx_delete_texture(game->texture.west);
	mlx_delete_texture(game->texture.east);
}