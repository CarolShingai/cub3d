/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:27:55 by cshingai          #+#    #+#             */
/*   Updated: 2025/04/07 19:38:50 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int n, size_t x)
{
	size_t			index;
	unsigned char	*char_ptr;

	char_ptr = (unsigned char *) ptr;
	index = 0;
	while (index < x)
	{
		char_ptr[index] = (unsigned char)n;
		index++;
	}
	return (ptr);
}

void	*ft_memset_32(void *ptr, __uint32_t n, size_t x)
{
	size_t			index;
	__uint32_t		*int_ptr;

	int_ptr = (__uint32_t *) ptr;
	index = 0;
	while (index < x)
	{
		int_ptr[index] = n;
		index++;
	}
	return (ptr);
}
