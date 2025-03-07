/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 22:51:28 by lsouza-r          #+#    #+#             */
/*   Updated: 2025/03/06 23:05:01 by lsouza-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_read_file(int fd, t_find *file, t_gnl **root)
{
	file->bytes = read(fd, file->buffer, BUFFER_SIZE);
	if (file->bytes < 0)
	{
		ft_dealloc(root);
		return (0);
	}
	if (file->bytes == 0)
		return (1);
	file->buffer[file->bytes] = '\0';
	return (2);
}

char	*get_next_line(int fd)
{
	static t_find	file;
	t_gnl			*root;
	int				len;
	int				verify;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	root = NULL;
	len = 0;
	while (ft_lstchr(root) == 0)
	{
		if (file.pos > 0 && file.pos != file.bytes && file.bytes != 0)
		{
			len += ft_build_line(&file, &root, file.bytes);
			continue ;
		}
		verify = ft_read_file(fd, &file, &root);
		if (verify == 0)
			return (NULL);
		if (verify == 1)
			break ;
		len += ft_build_line(&file, &root, file.bytes);
	}
	return (ft_transform(root, len));
}