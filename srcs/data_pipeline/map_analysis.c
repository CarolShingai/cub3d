/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_analysis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:40:51 by lsouza-r          #+#    #+#             */
/*   Updated: 2025/04/05 15:50:38 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	map_analysis(t_cub3d *cub3d)
{
	check_map_chars(cub3d);
	check_map_walls(cub3d);
}

void	check_map_chars(t_cub3d *cub3d)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	while (i < cub3d->map_size)
	{
		j = 0;
		new_line_removal(&cub3d->map[i]);
		while (cub3d->map[i][j])
		{
			if (!ft_strchr("01NSWE", cub3d->map[i][j])
				&& !ft_is_space(cub3d->map[i][j]))
				error_handling_and_free(cub3d, INVALID_CHAR);
			check_and_set_player(cub3d, i, j, &player);
			j++;
		}
		i++;
	}
	if (!player)
		error_handling_and_free(cub3d, NO_PLAYER);
}

void	check_and_set_player(t_cub3d *cub3d, int i, int j, int *player)
{
	if (ft_strchr("NSWE", cub3d->map[i][j]))
	{
		if (*player)
			error_handling_and_free(cub3d, MULTIPLE_PLAYER);
		cub3d->start_pos_x = j;
		cub3d->start_pos_y = i;
		cub3d->start_dir = cub3d->map[i][j];
	*player = 1;
	}
}

void	check_map_walls(t_cub3d *cub3d)
{
	int	i;
	int	j;

	i = 0;
	while (i < cub3d->map_size)
	{
		j = 0;
		while (cub3d->map[i][j])
		{
			if (cub3d->map[i][j] == '0'
				|| (i == cub3d->start_pos_y && j == cub3d->start_pos_x))
			{
				if (check_arround_zeros(cub3d, i, j) == 1)
					error_handling_and_free(cub3d, MAP_NOT_CLOSED);
			}
			j++;
		}
		i++;
	}
}

int	check_arround_zeros(t_cub3d *cub3d, int i, int j)
{
	if (i == 0 || i == cub3d->map_size - 1
		|| j == 0 || j == ft_strlen(cub3d->map[i]) - 1)
		return (1);
	else if (j >= ft_strlen(cub3d->map[i - 1])
		|| j >= ft_strlen(cub3d->map[i + 1]))
		return (1);
	else if (ft_is_space(cub3d->map[i - 1][j])
		|| ft_is_space(cub3d->map[i + 1][j])
		|| ft_is_space(cub3d->map[i][j - 1])
		|| ft_is_space(cub3d->map[i][j + 1]))
		return (1);
	return (0);
}
