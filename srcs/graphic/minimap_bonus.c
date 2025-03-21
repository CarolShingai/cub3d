/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 21:38:58 by cshingai          #+#    #+#             */
/*   Updated: 2025/03/21 17:53:37 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

mlx_image_t	*create_image(mlx_t *mlx, char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(path);
	if (!texture)
		ft_error(TEXTURE_ERROR);
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
		ft_error(IMAGE_ERROR);
	mlx_delete_texture(texture);
	return (img);
}

void	insert_minimap(t_game *game)
{
	game->minimap.img = 
		create_image(game->mlx, "textures/Lumon_case/minimap/minimap.png");
	game->imgs.miniwall_x = create_image(game->mlx, "textures/Lumon_case/minimap/minix.png");
	game->imgs.miniwall_y = create_image(game->mlx, "textures/Lumon_case/minimap/miniy.png");
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	mlx_image_to_window(game->mlx, game->minimap.img, 10, 10);
	while(game->cub3d.map[x])
	{
		y = 0;
		while (game->cub3d.map[x][y])
		{
			if (is_vertical_wall(game, y, x))
				mlx_image_to_window(game->mlx, game->imgs.miniwall_y, y * TILE + 150, x * TILE + 150);
			if (is_horizontal_wall(game, y, x))
				mlx_image_to_window(game->mlx, game->imgs.miniwall_x, y * TILE + 150, x * TILE + 150);
			y++;
		}
		x++;
	}
	// draw_player_square(game, 50, 50);
}

int	is_horizontal_wall(t_game *game, int x, int y)
{
	if (game->cub3d.map[y][x] == '1')
	{

		if (x > 0 && x < game->cub3d.map_size - 1)
		{
			if (game->cub3d.map[y][x - 1] == '1' && game->cub3d.map[y][x + 1] == '0')
				return (0);
		}
		if ((x > 0 && game->cub3d.map[y][x - 1] == '1') ||
			(x < game->cub3d.map_size - 1 && game->cub3d.map[y][x + 1] == '1'))
			return (1);
	}
	return (0);
}

int	is_vertical_wall(t_game *game, int x, int y)
{
	if (game->cub3d.map[y][x] == '1')
	{
		if (y > 0 && y < 12 - 1)
		{
			if (game->cub3d.map[y - 1][x] == '1' && game->cub3d.map[y + 1][x] == '0')
				return (0);
		}
		if ((y > 0 && game->cub3d.map[y - 1][x] == '1') ||
			(y < 12 -1 && game->cub3d.map[y + 1][x] == '1'))
			return (1);
	}
	return (0);
}

void	draw_player_square(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0
}