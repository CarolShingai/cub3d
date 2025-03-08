/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_analysis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 23:29:19 by lsouza-r          #+#    #+#             */
/*   Updated: 2025/03/07 23:45:54 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	data_analysis(t_cub3d *cub3d)
{
	check_all_configs(cub3d);
}

void	check_all_configs(t_cub3d *cub3d)
{
	int i;

	i = NORTH;
	while (i <= CEILING)
	{
		if (!cub3d->config[i])
		{
			printf("config %d %s\n", i, cub3d->config[i]);
			ft_free_all(cub3d);
			error_handling(CONFIG_MISSING);
		}
		i++;
	}
}