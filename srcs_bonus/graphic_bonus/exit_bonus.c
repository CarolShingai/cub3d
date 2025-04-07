/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 02:25:01 by cshingai          #+#    #+#             */
/*   Updated: 2025/04/07 19:19:17 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	check_exit(t_game *game, t_vector new_pos)
{
	char	*cmd;
	char	*path;
	char	*str;

	path = getenv("PWD");
	str = ft_strjoin("paplay ", path);
	cmd = ft_strjoin(str, "/sound/ding_sound.wav &");
	free(str);
	if (game->cub3d.map[(int)new_pos.y][(int)new_pos.x] == 'X')
	{
		if (game->key_collect == 1)
		{
			system(cmd);
			mlx_close_window(game->mlx);
			printf("You win!\n");
		}
	}
	free(cmd);
}
