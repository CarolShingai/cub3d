/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:00:07 by cshingai          #+#    #+#             */
/*   Updated: 2025/04/01 19:05:12 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

mlx_texture_t	*init_texture(char *path)
{
	mlx_texture_t	*new_img;

	new_img = mlx_load_png(path);
	if (!new_img)
		ft_error(TEXTURE_ERROR);
	return (new_img);
}

void	load_texture(t_game *game)
{
	game->texture.north = init_texture(game->cub3d.config[3]);
	game->texture.south = init_texture(game->cub3d.config[2]);
	game->texture.west = init_texture(game->cub3d.config[1]);
	game->texture.east = init_texture(game->cub3d.config[0]);
	game->texture.exit = init_texture("textures/Lumon_case/exit.png");
	game->texture.collectible_0 = init_texture("textures/Lumon_case/keycard.png");
	// game->texture.collectible_1 = init_texture("textures/Lumon_case/collectable.png");
}
