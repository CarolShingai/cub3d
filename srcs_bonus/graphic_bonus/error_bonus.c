/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:17:09 by cshingai          #+#    #+#             */
/*   Updated: 2025/03/22 16:04:18 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void ft_error(char *msg)
{
	ft_printf_fd(STDERR_FILENO, "%s", msg);
	exit(EXIT_FAILURE);
}
