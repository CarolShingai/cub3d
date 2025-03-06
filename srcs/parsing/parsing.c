/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 22:56:06 by lsouza-r          #+#    #+#             */
/*   Updated: 2025/03/05 23:47:04 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_file(char *file_path)
{
	int		fd;
	char	*line;
	int		is_map;

	is_map = 0;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		perror(RED"Error\n"RST);
		exit(1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		//verificar se é linha do mapa
		is_map = check_line(line, is_map);
		if (is_map == 2)
			break ;
		save_to_array(line);
	}
}

int	check_line(char *line, int is_map)
{
	int	i;

	i = 0;
	while(line[i])
	{
		if (line[i] == ' ')
			i++;
		else if (line[i] == 1)
			return (1);
	}
	if (is_map == 1)
		return (2);
	return (0);
}

void	save_to_array(char *line)
{
	
}