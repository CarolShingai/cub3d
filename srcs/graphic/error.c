/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:17:09 by cshingai          #+#    #+#             */
/*   Updated: 2025/04/03 22:00:17 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void ft_error(char *msg, t_game *game)
{
	ft_printf_fd(STDERR_FILENO, "%s", msg);
	if (game)
		clear_textures(game);
	exit(EXIT_FAILURE);
}
