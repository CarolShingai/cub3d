/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:17:09 by cshingai          #+#    #+#             */
/*   Updated: 2025/03/05 18:34:00 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void ft_error(void)
{
	// ft_printf_fd(STDERR_FILENO, "%s", mlx_strerror(mlx_errno));

	exit(EXIT_FAILURE);
}
