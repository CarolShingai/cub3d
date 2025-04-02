/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:03:05 by cshingai          #+#    #+#             */
/*   Updated: 2025/04/01 20:03:24 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// color RGB

uint32_t get_rgb(int r, int g, int b)
{
	return (255 << 24 | r << 16 | g << 8 | b);
}

void	init_game(t_game *game, t_cub3d *cub3d)
{
	game->ceiling = get_rgb(cub3d->ceiling_color.blue, cub3d->ceiling_color.green, cub3d->ceiling_color.red);
	game->floor = get_rgb(cub3d->floor_color.blue, cub3d->floor_color.green, cub3d->floor_color.red);
	set_position(game);
	load_texture(game);
	setting_window(game);
	mlx_loop_hook(game->mlx, &draw_view, game);
	mlx_key_hook(game->mlx, &key_action, game);
	mlx_loop(game->mlx);
	clear_textures(game);
	ft_free_all(cub3d);
	mlx_terminate(game->mlx);
}

int32_t	main(int argc, char **argv)
{
	t_game	game;
	t_cub3d	cub3d;

	run_pipeline(argc, argv, &cub3d);
	game.cub3d = cub3d;
	game.ceiling = 0;
	game.floor = 0;
	init_game(&game, &cub3d);
	return (EXIT_SUCCESS);
}
