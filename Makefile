NAME = cub3d
FLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast -g3
LIBMLX = libs/MLX42
LIBS = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

SRCS = ${addprefix srcs/, \
			main.c \
}

OBJS = $(SRCS:srcs/%.c=obj/%.o)


# RULES
all: $(NAME)

$(NAME): libmlx $(OBJS)
	@cc $(FLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "Compiling cub3d"

obj/%.o: srcs/%.c
	@mkdir -p obj
	@cc $(FLAGS) -c $< -o $@

libmlx:
	@echo "compiling graphics..."
	@cmake $(LIBMLX) -B $(LIBMLX)/build > /dev/null
	@make -C $(LIBMLX)/build -j4 --no-print-directory > /dev/null

clean: 
	@echo "Removing objects..."
	@rm -rf obj
	@rm -rf $(LIBMLX)/build

fclean: clean
	@echo "Removing Executables"
	@rm -rf $(NAME)

re: fclean all

.PHONY = all clean fclean re