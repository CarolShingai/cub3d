/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 21:38:58 by cshingai          #+#    #+#             */
/*   Updated: 2025/03/22 04:15:29 by cshingai         ###   ########.fr       */
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
	game->imgs.player = create_image(game->mlx, "textures/Lumon_case/minimap/player.png");
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;
	int	draw_x;
	int	draw_y;

	x = 0;
	mlx_image_to_window(game->mlx, game->minimap.img, 10, 10);
	while(game->cub3d.map[x])
	{
		y = 0;
		while (game->cub3d.map[x][y])
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

int	is_player(t_game *game, int x, int y)
{
	if (game->cub3d.map[x][y] == 'N' || game->cub3d.map[x][y] == 'S' ||
		game->cub3d.map[x][y] == 'E' || game->cub3d.map[x][y] == 'W')
		return (1);
	else
		return (0);
}
