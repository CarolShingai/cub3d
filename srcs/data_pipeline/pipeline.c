/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:04:39 by lsouza-r          #+#    #+#             */
/*   Updated: 2025/04/05 16:07:41 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_cub3d(t_cub3d *cub3d)
{
	cub3d->map = NULL;
	cub3d->map_size = 0;
	cub3d->config = ft_calloc(sizeof(char *), 7);
}

void	run_pipeline(int argc, char **argv, t_cub3d *cub3d)
{
	int	i;

	i = 0;
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
