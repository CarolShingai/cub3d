/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 21:39:41 by lsouza-r          #+#    #+#             */
/*   Updated: 2025/03/07 23:22:01 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_free_array_str(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	ft_free_all(t_cub3d *cub3d)
{
	ft_free_array_str(cub3d->config);
	ft_free_array_str(cub3d->map);
}

int	file_opening(char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		perror(RED"Error\n"RST);
		exit(1);
	}
	return (fd);
}

void	error_handling_extract(int is_map, t_cub3d *cub3d, int fd, int mode)
{
	if (is_map == ERROR_CONFIG)
	{
		close(fd);
		ft_free_array_str(cub3d->config);
		error_handling(DUPLICATE_CONFIG);
	}
	if (cub3d->map_size == 0 && mode == LOAD)
	{
		close(fd);
		ft_free_array_str(cub3d->config);
		error_handling(ERROR_MAP_MISSING);
	}
}
