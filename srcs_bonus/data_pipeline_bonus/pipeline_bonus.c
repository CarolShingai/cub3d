/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:04:39 by lsouza-r          #+#    #+#             */
/*   Updated: 2025/04/06 22:42:27 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	init_cub3d(t_cub3d *cub3d)
{
	cub3d->map = NULL;
	cub3d->map_size = 0;
	cub3d->map_width = 0;
	cub3d->config = ft_calloc(sizeof(char *), 7);
}

void	run_pipeline(int argc, char **argv, t_cub3d *cub3d)
{
	init_cub3d(cub3d);
	check_args_and_file(argc, argv);
	extract(argv[1], cub3d);
	close(cub3d->fd_extract);
	load(cub3d, argv[1]);
	data_analysis(cub3d);
}

void	error_handling_and_free(t_cub3d *cub3d, char *message)
{
	ft_free_all(cub3d);
	error_handling(message);
}
