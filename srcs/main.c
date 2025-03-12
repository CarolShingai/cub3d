/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:03:05 by cshingai          #+#    #+#             */
/*   Updated: 2025/03/11 22:03:21 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// color RGB

uint32_t get_rgb(int r, int g, int b)
{
	return (255 << 24 | r << 16 | g << 8 | b);
}

void	init_game(t_game *game)
{
	game->ceiling = get_rgb(0,255,255);
	game->floor = get_rgb(255, 0, 0);
	//atribuindo valores necessarios para as variveis de dda;
	set_position(game);
	setting_window(game);
	// mlx_key_hook(game->mlx, &key_action, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}


int32_t	main(void)
{
	// Start mlx
	t_game	game;

	// game = malloc(sizeof(t_game));
	// if (!game)
		// return (EXIT_FAILURE);
	game.ceiling = 0;
	game.floor = 0;

	init_game(&game);
	return (EXIT_SUCCESS);
}
