/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 02:25:01 by cshingai          #+#    #+#             */
/*   Updated: 2025/04/02 19:22:21 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	check_exit(t_game *game, t_vector new_pos)
{
	int	time;
	// int

	time = 0;
	if (game->cub3d.map[(int)new_pos.y][(int)new_pos.x] == 'X')
	{
		if (game->key_collect == 1)
		{
			system("paplay /nfs/homes/cshingai/projetos/cub3d/sound/ding_sound.wav &");
			clear_game(game);
			mlx_close_window(game->mlx);
			printf("You win!\n");
		}
	}
}
