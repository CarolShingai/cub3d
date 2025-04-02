/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 21:38:58 by cshingai          #+#    #+#             */
/*   Updated: 2025/04/02 20:05:48 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

mlx_image_t	*create_image(mlx_t *mlx, char *path, t_game *game)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(path);
	if (!texture)
		ft_error(TEXTURE_ERROR, game);
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
	{
		mlx_delete_texture(texture);
		ft_error(IMAGE_ERROR, game);
	}
	mlx_delete_texture(texture);
	return (img);
}

void	insert_minimap(t_game *game)
{
	game->imgs.minimap
		= create_image(game->mlx, "textures/Lumon_case/minimap/minimap.png", game);
	game->imgs.miniwall_x = create_image(game->mlx,
			"textures/Lumon_case/minimap/minix.png", game);
	game->imgs.miniwall_y = create_image(game->mlx,
			"textures/Lumon_case/minimap/miniy.png", game);
	game->imgs.player = create_image(game->mlx,
			"textures/Lumon_case/minimap/player.png", game);
	game->imgs.block = create_image(game->mlx,
			"textures/Lumon_case/minimap/block2.png", game);
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;
	int	draw_x;
	int	draw_y;

	x = 0;
	mlx_image_to_window(game->mlx, game->imgs.minimap, 0, 0);
	while (game->cub3d.map[x] && x < game->cub3d.map_size)
	{
		y = 0;
		while (game->cub3d.map[x][y] && y < game->cub3d.map_width)
		{
			draw_x = (y * TILE) + MINIMAP_START_X + 20;
			draw_y = (x * TILE) + MINIMAP_START_Y + 20;
			if (is_vertical_wall(game, y, x))
				mlx_image_to_window(game->mlx, game->imgs.miniwall_y, draw_x, draw_y);
			if (is_horizontal_wall(game, y, x))
				mlx_image_to_window(game->mlx, game->imgs.miniwall_x, draw_x, draw_y);
			if (is_player(game, x, y))
				mlx_image_to_window(game->mlx, game->imgs.player, draw_x, draw_y);
			y++;
		}
		x++;
	}
}

int	is_horizontal_wall(t_game *game, int x, int y)
{
	if (game->cub3d.map[y][x] == '1')
	{
		if (x > 0 && x < game->cub3d.map_width - 2)
		{
			if (game->cub3d.map[y][x + 1] != '1')
				return (0);
			else
				return (1);
		}
		if (x == 0)
		{
			if (game->cub3d.map[y][x + 1] == '1')
				return (1);
		}
		if (x == game->cub3d.map_width - 2)
		{
			if (game->cub3d.map[y][x - 1] == '1')
				return (1);
		}
	}
	return (0);
}

int	is_vertical_wall(t_game *game, int x, int y)
{
	if (y < 0 || y >= game->cub3d.map_size || x < 0 || x >= game->cub3d.map_width)
		return (0);
	if (game->cub3d.map[y][x] == '1')
	{
		if (y > 0 && y < game->cub3d.map_size - 1)
		{
			if (game->cub3d.map[y + 1][x] != '1')
				return (0);
			else
				return (1);
		}
		if (y == 0)
		{
			if (game->cub3d.map[y + 1][x] == '1')
				return (1);
		}
		if (y == game->cub3d.map_size - 1)
		{
			if (game->cub3d.map[y - 1][x] == '1')
				return (1);
		}
	}
	return (0);
}

	// int is_blocked_diagonal(t_game *game, int x, int y)
	// {
	// 	if (game->cub3d.map[y][x] == 1)
	// 		return (0);
	// 	if (y > 0 && x > 0 &&
	// 		game->cub3d.map[y - 1][x] == '1' && game->cub3d.map[y][x - 1] == '1' &&
	// 		game->cub3d.map[y - 1][x - 1] == '0')
	// 		return (1);
	// 	if (y > 0 && x < game->cub3d.map_size - 1 &&
	// 		game->cub3d.map[y - 1][x] == '1' && game->cub3d.map[y][x + 1] == '1' &&
	// 		game->cub3d.map[y - 1][x + 1] == '0')
	// 		return (2);
	// 	if (y < game->cub3d.map_size - 1 && x > 0 &&
	// 		game->cub3d.map[y + 1][x] == '1' && game->cub3d.map[y][x - 1] == '1' &&
	// 		game->cub3d.map[y + 1][x - 1] == '0')
	// 		return (3);
	// 	if (y < game->cub3d.map_size - 1 && x < game->cub3d.map_size - 1 &&
	// 		game->cub3d.map[y + 1][x] == '1' && game->cub3d.map[y][x + 1] == '1' &&
	// 		game->cub3d.map[y + 1][x + 1] == '0')
	// 		return (4);
	// 	return (0);
	// }
