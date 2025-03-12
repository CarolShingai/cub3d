/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 21:39:41 by lsouza-r          #+#    #+#             */
/*   Updated: 2025/03/11 22:03:30 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_free_array_str(char **str_array)
{
	int	i;

	i = 0;
	if (!str_array)
		return ;
	while (str_array[i])
	{
		free(str_array[i]);
		i++;
	}
	free(str_array);
}

void	ft_free_config(t_cub3d *cub3d)
{
	int	i;

	i = NORTH;
	if (!cub3d->config)
		return ;
	while (i <= CEILING)
	{
		if (cub3d->config[i])
			free(cub3d->config[i]);
		i++;
	}
	free(cub3d->config);
}

void	ft_free_all(t_cub3d *cub3d)
{
	ft_free_config(cub3d);
	ft_free_array_str(cub3d->map);
}

int	file_opening(char *file_path, t_cub3d *cub3d)
{
	int	fd;
	char	*message;

	fd = open(file_path, O_RDONLY | __O_DIRECTORY);
	if (fd >= 0)
	{
		close(fd);
		ft_free_all(cub3d);
		error_handling(IS_A_DIRECTORY);
	}
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		message = ft_strjoin(RED"Error\n"RST, file_path);
		perror(message);
		free(message);
		ft_free_all(cub3d);
		exit(1);
	}
	return (fd);
}

void	error_handling_extract(int is_map, t_cub3d *cub3d, int fd, int mode)
{
	if (is_map == ERROR_CONFIG)
	{
		close(fd);
		ft_free_config(cub3d);
		error_handling(DUPLICATE_CONFIG);
	}
	if (cub3d->map_size == 0 && mode == LOAD)
	{
		close(fd);
		ft_free_config(cub3d);
		error_handling(ERROR_MAP_MISSING);
	}
}

void	error_handling_and_free(t_cub3d *cub3d, char *message)
{
	ft_free_all(cub3d);
	error_handling(message);
}
