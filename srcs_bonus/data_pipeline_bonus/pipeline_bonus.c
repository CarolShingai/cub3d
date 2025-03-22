/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:04:39 by lsouza-r          #+#    #+#             */
/*   Updated: 2025/03/22 16:07:05 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	init_cub3d(t_cub3d *cub3d)
{
	cub3d->map = NULL;
	cub3d->map_size = 0;
	cub3d->config = ft_calloc(sizeof(char *), 7);
}

void	run_pipeline(int argc, char **argv, t_cub3d *cub3d)
{
	int i = 0;

	init_cub3d(cub3d);
	check_args_and_file(argc, argv);
	extract(argv[1], cub3d);
	close(cub3d->fd_extract);
	printf("%d\n", cub3d->map_size);
	load(cub3d, argv[1]);
	data_analysis(cub3d);
	while (i < cub3d->map_size)
	{
		printf("linha %d %s", i, cub3d->map[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (i < 7)
	{
		if (cub3d->config[i])
			printf("config %d %s\n", i, cub3d->config[i]);
		i++;
	}
	printf("teste/n");
}
