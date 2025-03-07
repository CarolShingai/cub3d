/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:04:39 by lsouza-r          #+#    #+#             */
/*   Updated: 2025/03/06 23:12:49 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_cub3d(t_cub3d *cub3d)
{
	cub3d->map = NULL;
	cub3d->map_size = 0;
}

void	run_pipeline(int argc, char **argv)
{
	t_cub3d	cub3d;
	int i = 0;

	init_cub3d(&cub3d);
	validation(argc, argv);
	extract(argv[1], &cub3d);
	close(cub3d.fd_extract);
	printf("%d\n", cub3d.map_size);
	load(&cub3d, argv[1]);
	while (i < cub3d.map_size)
	{
		printf("linha %d %s", i, cub3d.map[i]);
		i++;
	}	
}