/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:48:10 by cshingai          #+#    #+#             */
/*   Updated: 2025/04/07 19:36:50 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_gnl
{
	char			c;
	struct s_gnl	*next;
}	t_gnl;

typedef struct s_find
{
	char	buffer[BUFFER_SIZE];
	int		pos;
	int		bytes;
}	t_find;

int		ft_atoi(const char *str);
void	ft_bzero(void *str, size_t n);
void	*ft_calloc(size_t n_element, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	*ft_memchr(void *str, int c, size_t n);
int		ft_memcmp(void *str1, const void *str2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, void *src, size_t n);
void	*ft_memset(void *ptr, int n, size_t x);
void	*ft_memset_32(void *ptr, __uint32_t n, size_t x);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(char *str, int c);
char	*ft_strdup(char *c);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strcmp(char *str1, char *str2);
size_t	ft_strlcat(char *dest, char *src, size_t n);
size_t	ft_strlcpy(char *dest, char *src, size_t n);
int		ft_strlen(const char *str);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(char *str1, char *str2, size_t n);
char	*ft_strnstr(char *big, char *lit, size_t len);
char	*ft_strrchr(char *str, size_t n);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_is_space(char c);
//get next line
char	*get_next_line(int fd);
char	*ft_transform(t_gnl *root, int len);
void	ft_insert_end(t_gnl **root, char c);
void	ft_dealloc(t_gnl **root);
int		ft_build_line(t_find *file, t_gnl **root, int bytes);
int		ft_read_file(int fd, t_find *file, t_gnl **root);
int		ft_lstchr(t_gnl *root);

#endif
