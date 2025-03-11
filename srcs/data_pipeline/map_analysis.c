/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_analysis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:40:51 by lsouza-r          #+#    #+#             */
/*   Updated: 2025/03/10 22:23:55 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	map_analysis(t_cub3d *cub3d)
{
	check_map_chars(cub3d);
}

void	check_map_chars(t_cub3d *cub3d)
{
	int i;
	int j;
	int player;
	
	i = 0;
	player = 0;
	while (i < cub3d->map_size)
	{
		j = 0;
		new_line_removal(&cub3d->map[i]);
		while (cub3d->map[i][j])
		{
			if (!ft_strchr("01NSWE", cub3d->map[i][j]) && !ft_is_space(cub3d->map[i][j]))
				error_handling_map(cub3d, INVALID_CHAR);
			if (ft_strchr("NSWE", cub3d->map[i][j]))
			{
				if (player)
					error_handling_map(cub3d, MULTIPLE_PLAYER);
				insert_start_pos(cub3d, i, j, cub3d->map[i][j]);
				player = 1;
			}
			j++;
		}
		i++;
	}
	if (!player)
		error_handling_map(cub3d, NO_PLAYER);
}

void	error_handling_map(t_cub3d *cub3d, char *message)
{
	ft_free_all(cub3d);
	error_handling(message);
}
void	insert_start_pos(t_cub3d *cub3d, int i, int j, char c)
{
	cub3d->start_pos_x = i;
	cub3d->start_pos_y = j;
	cub3d->start_dir = c;
}

