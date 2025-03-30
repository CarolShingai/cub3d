/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 02:25:01 by cshingai          #+#    #+#             */
/*   Updated: 2025/03/30 00:03:34 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	check_exit(t_game *game, t_vector new_pos)
{
    if (game->cub3d.map[(int)new_pos.y][(int)new_pos.x] == 'X')
    {
        if (game->key_collect == 1)
        {
            close_game(game);
            printf("You win!\n");
        }
    }
}
