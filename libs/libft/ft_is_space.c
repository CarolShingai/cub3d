/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:31:59 by lsouza-r          #+#    #+#             */
/*   Updated: 2025/04/07 19:37:55 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_space(char c)
{
	if (c == 32 || c == 9 || c == 11 || c == 13)
		return (1);
	return (0);
}
