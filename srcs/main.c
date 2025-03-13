/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:03:05 by cshingai          #+#    #+#             */
/*   Updated: 2025/03/12 20:28:06 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


// color RGB

uint32_t get_rgb(int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8 | 255);
}

void	init_game(t_game *game, t_cub3d *cub3d)
{
	game->floor = get_rgb(cub3d->floor_color.red, cub3d->floor_color.green,
		cub3d->floor_color.blue);
	game->ceiling = get_rgb(cub3d->ceiling_color.red, cub3d->ceiling_color.green,
		cub3d->ceiling_color.blue);

	setting_window(game);
	// mlx_key_hook(game->mlx, &key_action, game);
	mlx_loop(game->mlx);
	ft_free_all(cub3d);
	mlx_terminate(game->mlx);
}

int32_t	main(int argc, char **argv)
{
	// Start mlx
	t_game	game;
	t_cub3d	cub3d;

	run_pipeline(argc, argv, &cub3d);
	game.ceiling = 0;
	game.floor = 0;
	init_game(&game, &cub3d);
	return (EXIT_SUCCESS);
}
