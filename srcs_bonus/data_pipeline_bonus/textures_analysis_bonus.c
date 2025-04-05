/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_analysis_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 23:29:19 by lsouza-r          #+#    #+#             */
/*   Updated: 2025/04/05 16:22:33 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	data_analysis(t_cub3d *cub3d)
{
	check_all_configs(cub3d);
	verify_textures_files(cub3d);
	check_color(cub3d);
	map_analysis(cub3d);
}

void	check_all_configs(t_cub3d *cub3d)
{
	int	i;

	i = NORTH;
	while (i <= CEILING)
	{
		if (!cub3d->config[i])
		{
			ft_free_all(cub3d);
			error_handling(CONFIG_MISSING);
		}
		i++;
	}
	i = NORTH;
	while (i <= CEILING)
	{
		new_line_removal(&cub3d->config[i]);
		i++;
	}
}

void	new_line_removal(char **str)
{
	char	*new_str;
	int		i;

	i = ft_strlen(*str);
	if ((*str)[i - 1] == '\n')
	{
		new_str = ft_substr(*str, 0, i - 1);
		free(*str);
		*str = new_str;
	}
}

void	verify_textures_files(t_cub3d *cub3d)
{
	int	i;
	int	fd;

	i = NORTH;
	while (i <= EAST)
	{
		fd = file_opening(cub3d->config[i], cub3d);
		close(fd);
		check_textures_file_name(cub3d->config[i], cub3d);
		i++;
	}
}
