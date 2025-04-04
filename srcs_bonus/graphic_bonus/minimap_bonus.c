/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 21:38:58 by cshingai          #+#    #+#             */
/*   Updated: 2025/04/03 21:45:25 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	draw_map(t_game *game)
{
	int	x;
	int	y;
	int	draw_x;
	int	draw_y;

	x = -1;
	mlx_image_to_window(game->mlx, game->imgs.minimap, 0, 0);
	while (game->cub3d.map[++x] && x < game->cub3d.map_size)
	{
		y = -1;
		while (game->cub3d.map[x][++y] && y < game->cub3d.map_width)
		{
			draw_x = (y * TILE) + MINIMAP_START_X + 20;
			draw_y = (x * TILE) + MINIMAP_START_Y + 20;
			if (is_vertical_wall(game, y, x))
				mlx_image_to_window(game->mlx, game->imgs.miniwall_y,
					draw_x, draw_y);
			if (is_horizontal_wall(game, y, x))
				mlx_image_to_window(game->mlx, game->imgs.miniwall_x,
					draw_x, draw_y);
			if (is_player(game, x, y))
				mlx_image_to_window(game->mlx, game->imgs.player,
					draw_x, draw_y);
		}
	}
}

int	is_horizontal_wall(t_game *game, int x, int y)
{
	int	y_width;

	y_width = ft_strlen(game->cub3d.map[y]);
	if (game->cub3d.map[y][x] == '1')
	{
		if (x > 0 && x < y_width - 1)
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
		if (x == y_width - 1)
		{
			if (game->cub3d.map[y][x - 1] == '1')
				return (1);
		}
	}
	return (0);
}

int	check_wall_bellow(t_game *game, int x, int y)
{
	if (y > 0 && y < game->cub3d.map_size - 1)
	{
		if (x >= (int)ft_strlen(game->cub3d.map[y + 1]))
			return (0);
		if (game->cub3d.map[y + 1][x] != '1')
			return (0);
		else
			return (1);
	}
	if (y == 0)
	{
		if (y + 1 < game->cub3d.map_size
			&& x < (int)ft_strlen(game->cub3d.map[y + 1])
			&& game->cub3d.map[y + 1][x] == '1')
			return (1);
	}
	return (0);
}

int	check_wall_above(t_game *game, int x, int y)
{
	if (y == game->cub3d.map_size - 1)
	{
		if (y - 1 >= 0 && x < (int)ft_strlen(game->cub3d.map[y - 1])
			&& game->cub3d.map[y - 1][x] == '1')
			return (1);
	}
	return (0);
}

int	is_vertical_wall(t_game *game, int x, int y)
{
	if (y < 0 || y >= game->cub3d.map_size
		|| x < 0 || x >= (int)ft_strlen(game->cub3d.map[y]))
		return (0);
	if (game->cub3d.map[y][x] == '1')
	{
		if (check_wall_above(game, x, y) || check_wall_bellow(game, x, y))
			return (1);
	}
	return (0);
}
