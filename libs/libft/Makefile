# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsouza-r <lsouza-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 17:34:20 by cshingai          #+#    #+#              #
#    Updated: 2025/03/06 23:07:29 by lsouza-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Werror -Wextra -c

FILES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
 ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
 ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
 ft_putstr_fd.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
 ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
 ft_substr.c ft_tolower.c ft_toupper.c ft_strmapi.c ft_split.c ft_realloc.c \
 ft_strcmp.c get_next_line.c ft_is_space.c gnl_utils.c \

OBJ_DIR = obj

OBJ = $(FILES:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@cc $(FLAGS) $< -o $@ -I includes
	
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

all: ${NAME}

${NAME}: ${OBJ}
	@echo "compiling libft"
	@ar rcs ${NAME} ${OBJ}

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f ${NAME}

re: fclean all
