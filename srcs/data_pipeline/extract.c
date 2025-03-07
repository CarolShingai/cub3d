/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 22:56:06 by lsouza-r          #+#    #+#             */
/*   Updated: 2025/03/06 23:14:20 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	extract(char *file_path, t_cub3d *cub3d)
{
	cub3d->fd_extract = file_opening(file_path);
	read_map(cub3d, EXTRACT, cub3d->fd_extract);
}

void	read_map(t_cub3d *cub3d, int mode, int fd)
{
	char	*line;
	int		is_map;
	int		temp;
	int		i;
	
	is_map = NO_MAP;
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		temp = is_map;
		is_map = check_line(line, temp);
		if (is_map == END_MAP)
			break ;
		if (is_map == IS_MAP && mode == EXTRACT)
			cub3d->map_size++;
		if (is_map == IS_MAP && mode == LOAD)
			cub3d->map[i++] = ft_strdup(line);
	}
	free(line);
	if (cub3d->map_size == 0 && mode == EXTRACT)
		error_handling(ERROR_MAP_MISSING);
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

int	check_line(char *line, int map_was)
{
	int	i;

	i = 0;
	while(line[i])
	{
		if (ft_is_space(line[i]) || line[i] == '\n')
			i++;
		else if (line[i])
			return (IS_MAP);
	}
	if (map_was == IS_MAP)
		return (END_MAP);
	return (NO_MAP);
}
