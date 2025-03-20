/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:00:07 by cshingai          #+#    #+#             */
/*   Updated: 2025/03/20 15:23:39 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

mlx_texture_t	*init_texture(char *path)
{
	//fazer ft_error
	mlx_texture_t   *new_img;

	new_img = mlx_load_png(path);
	if (!new_img)
		ft_error();
	return (new_img);
}

void	load_texture(t_game *game)
{
	game->north = init_texture(game->cub3d.config[0]);
	game->south = init_texture(game->cub3d.config[1]);
	game->west = init_texture(game->cub3d.config[2]);
	game->east = init_texture(game->cub3d.config[3]);
}

void	clear_textures(t_game *game)
{
	mlx_delete_texture(game->north);
	mlx_delete_texture(game->south);
	mlx_delete_texture(game->west);
	mlx_delete_texture(game->east);
}