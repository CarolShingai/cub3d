/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_analysis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:20:40 by lsouza-r          #+#    #+#             */
/*   Updated: 2025/03/11 21:58:38 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/cub3d.h"

void	check_color(t_cub3d *cub3d)
{
	int i;

	i = FLOOR;
	while (i <= CEILING)
	{
		if (!cub3d->config[i])
			error_handling(CONFIG_MISSING);
		new_line_removal(&cub3d->config[i]);
		if (!check_three_colors(cub3d->config[i]))
			error_handling_and_free(cub3d, CONFIG_COLOR);
		if (!convert_color(cub3d->config[i], i, cub3d))
			error_handling_and_free(cub3d, CONFIG_COLOR);
		i++;
	}
}

int	check_three_colors(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			count++;
			while (str[i] && ft_isdigit(str[i]))
				i++;
		}
		if (str[i] == ',')
			i++;
		if (count > 3 || (str[i] && !ft_isdigit(str[i])))
			return (0);
	}
	if (count != 3)
		return (0);
	return (1);
}

int	convert_color(char *str, int type, t_cub3d *cub3d)
{
	char **split;
	t_colors colors;

	split = ft_split(str, ',');
	if (!split)
		return (0);
	colors.red = ft_atoi(split[0]);
	colors.green = ft_atoi(split[1]);
	colors.blue = ft_atoi(split[2]);
	if (colors.red < 0 || colors.red > 255
		|| colors.green < 0 || colors.green > 255
		|| colors.blue < 0 || colors.blue > 255)
	{
		ft_free_array_str(split);
		return (0);
	}
	if (type == FLOOR)
		cub3d->floor_color = (colors.red << 24 | colors.green << 16 | colors.blue << 8 | 255);
	else
		cub3d->floor_color = (colors.red << 24 | colors.green << 16 | colors.blue << 8 | 255);
	ft_free_array_str(split);
	return (1);
}
