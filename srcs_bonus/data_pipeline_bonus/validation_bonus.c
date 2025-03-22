/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 22:11:41 by lsouza-r          #+#    #+#             */
/*   Updated: 2025/03/22 16:07:20 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	check_args_and_file(int argc, char **argv)
{
	if (argc != 2)
		error_handling(ERROR_ARGS);
	check_file_name(argv[1]);
}

void	check_file_name(char *file_name)
{
	int	str_len;

	str_len = ft_strlen(file_name);
	if (str_len < 4)
		error_handling(VERIFY_NAME);
	if (ft_strncmp(&file_name[str_len - 4], ".cub", 4) != 0)
		error_handling(ERROR_FILE_NAME);
}

void	error_handling(char *message)
{
	printf(RED"Error\n%s\n"ANGRY"\n"RST, message);
	exit(1);
}

void	check_textures_file_name(char *file_name, t_cub3d *cub3d)
{
	int	str_len;

	str_len = ft_strlen(file_name);
	if (str_len < 4)
	{
		ft_free_all(cub3d);
		error_handling(VERIFY_NAME);
	}
	if (ft_strncmp(&file_name[str_len - 4], ".png", 4) != 0)
	{
		ft_free_all(cub3d);
		error_handling(ERROR_FILE_NAME);
	}
}