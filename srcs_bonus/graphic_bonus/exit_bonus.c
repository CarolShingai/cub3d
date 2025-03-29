/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 02:25:01 by cshingai          #+#    #+#             */
/*   Updated: 2025/03/29 18:46:08 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	check_exit(t_dda *ray, t_game *game)
{
    (void)game;
    ray->hit_side = EXIT;
    printf("entrou aqui\n");
    if (ray->perpen_dist < 0.2)
    {
        if (game->key_collect == 1)
        {
            mlx_close_window(game->mlx);
            ft_printf("You win!\n");
            exit(0);
        }
        else
        {
            ft_printf("You need to collect the Key Card before exiting.\n");
        }
    }
}
