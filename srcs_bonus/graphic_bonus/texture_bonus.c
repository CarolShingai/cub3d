/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:00:07 by cshingai          #+#    #+#             */
/*   Updated: 2025/04/04 20:57:37 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

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
	game->texture.east = init_texture(game->cub3d.config[0], game);
	game->texture.exit = init_texture("textures/Lumon_case/exit.png", game);
	game->texture.collectible_0 = init_texture
		("textures/Lumon_case/keycard.png", game);
	game->texture.collectible_1 = init_texture
		("textures/Lumon_case/book.png", game);
}

uint32_t	get_pixel_color(mlx_texture_t *tex, int x, int y)
{
	int			tex_pos;
	uint8_t		*color;
	uint32_t	final_color;

	if (!tex || !tex->pixels)
		return (0);
	if (x < 0 || x >= (int)tex->width || y < 0 || y >= (int)tex->height)
		return (0);
	tex_pos = (y * tex->width + x) * tex->bytes_per_pixel;
	color = &tex->pixels[tex_pos];
	final_color = (color[0] << 24) | (color[1] << 16)
		| (color[2] << 8) | color[3];
	return (final_color);
}
