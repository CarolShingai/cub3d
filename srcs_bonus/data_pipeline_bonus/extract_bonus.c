/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 22:56:06 by lsouza-r          #+#    #+#             */
/*   Updated: 2025/04/07 18:40:42 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	extract(char *file_path, t_cub3d *cub3d)
{
	cub3d->fd_extract = file_opening(file_path, cub3d);
	read_map(cub3d, EXTRACT, cub3d->fd_extract);
}

void	read_map(t_cub3d *cub3d, int mode, int fd)
{
	char	*line;
	int		is_map;
	int		i;

	is_map = NO_MAP;
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line || is_map == ERROR_MAP || is_map == ERROR_CONFIG)
			break ;
		is_map = check_line(line, is_map, cub3d, mode);
		if (is_map == IS_MAP && mode == EXTRACT)
		{
			cub3d->map_size++;
			if (ft_strlen(line) > cub3d->map_width)
				cub3d->map_width = ft_strlen(line);
		}
		if (is_map == IS_MAP && mode == LOAD)
			cub3d->map[i++] = ft_strdup(line);
		free(line);
	}	
	free(line);
	if (is_map != END_MAP)
		error_handling_extract(is_map, cub3d, fd, mode);
}

int	check_line(char *line, int map_was, t_cub3d *cub3d, int mode)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_is_space(line[i]) || line[i] == '\n')
			i++;
		else if (map_was == NO_MAP && line[i + 1]
			&& check_config(line[i], line[i + 1]) >= 0)
		{
			if (mode == EXTRACT)
				return (save_config_to_array(line, cub3d,
						check_config(line[i], line[i + 1])));
			return (NO_MAP);
		}
		else if (line[i])
		{
			if (map_was == END_MAP)
				return (ERROR_MAP);
			return (IS_MAP);
		}
	}
	if (map_was == IS_MAP || map_was == END_MAP)
		return (END_MAP);
	return (NO_MAP);
}

int	check_config(char c1, char c2)
{
	if (c1 == 'N' && c2 == 'O')
		return (NORTH);
	else if (c1 == 'S' && c2 == 'O')
		return (SOUTH);
	else if (c1 == 'W' && c2 == 'E')
		return (WEST);
	else if (c1 == 'E' && c2 == 'A')
		return (EAST);
	else if (c1 == 'F' && c2 == ' ')
		return (FLOOR);
	else if (c1 == 'C' && c2 == ' ')
		return (CEILING);
	return (-1);
}

int	save_config_to_array(char *line, t_cub3d *cub3d, int config)
{
	char	**temp;

	if (cub3d->config[config])
		return (ERROR_CONFIG);
	temp = ft_split(line, ' ');
	cub3d->config[config] = ft_strdup(temp[1]);
	ft_free_array_str(temp);
	return (NO_MAP);
}
