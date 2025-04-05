/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:00:07 by cshingai          #+#    #+#             */
/*   Updated: 2025/04/05 12:44:10 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

//fazer ft_error
mlx_texture_t	*init_texture(char *path, t_game *game)
{
	mlx_texture_t	*new_img;

	new_img = mlx_load_png(path);
	if (!new_img)
		ft_error(TEXTURE_ERROR, game);
	return (new_img);
}

void	load_texture(t_game *game)
{
	game->texture.north = init_texture(game->cub3d.config[3], game);
	game->texture.south = init_texture(game->cub3d.config[2], game);
	game->texture.west = init_texture(game->cub3d.config[1], game);
	game->texture.east = init_texture(game->cub3d.config[2], game);
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
}
