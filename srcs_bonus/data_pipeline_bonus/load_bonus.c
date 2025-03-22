/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:05:39 by lsouza-r          #+#    #+#             */
/*   Updated: 2025/03/22 16:06:53 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	load(t_cub3d *cub3d, char *file_path)
{
	set_array(cub3d);
	cub3d->fd_load = file_opening(file_path, cub3d);
	read_map(cub3d, LOAD, cub3d->fd_load);
	close(cub3d->fd_load);
}

void	set_array(t_cub3d *cub3d)
{
	cub3d->map = ft_calloc(sizeof(char *), (cub3d->map_size + 1));
	if (!cub3d->map)
		error_handling(ERROR_MALLOC);
}
