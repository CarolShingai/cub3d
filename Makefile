NAME = cub3d

MAKEFLAGS += --no-print-directory
FLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast -g3

GREEN = $(shell tput setaf 2)
YELLOW = $(shell tput setaf 3)
RESET = $(shell tput sgr0)

LIBMLX = libs/MLX42
LIBFT = libs/libft
FT_PRINTF = libs/ft_printf
LIBS = $(LIBFT)/libft.a $(FT_PRINTF)/libftprintf.a $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

SRCS = ${addprefix srcs/, \
			graphic/error.c \
			graphic/draw_background.c \
			graphic/vector_utils.c \
			graphic/setting_game.c \
			graphic/draw_wall.c \
			graphic/algorithm_dda.c \
			graphic/draw_view.c \
			graphic/moviments.c \
			graphic/moviments_restriction.c \
			graphic/key_hook.c \
			main.c \
			data_pipeline/validation.c \
			data_pipeline/extract.c \
			data_pipeline/pipeline.c \
			data_pipeline/load.c \
			data_pipeline/utils.c \
			data_pipeline/textures_analysis.c \
			data_pipeline/color_analysis.c \
			data_pipeline/map_analysis.c \
}

OBJS = $(SRCS:srcs/%.c=obj/%.o)


# RULES
all: $(NAME)

$(NAME): libmlx  libft ft_printf $(OBJS)
	@echo "Compiling cub3d"
	@cc $(FLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "$(GREEN)cub3d is read!✅$(RESET)"

obj/%.o: srcs/%.c
	@mkdir -p obj $(dir $@)
	@cc $(FLAGS) -c $< -o $@

# Building libraries
libft:
	@make -C $(LIBFT) all
	@echo "Libft is read!"

ft_printf:
	@make -C $(FT_PRINTF) all

libmlx:
	@echo "compiling MLX42..."
	@cmake $(LIBMLX) -B $(LIBMLX)/build > /dev/null
	@make -C $(LIBMLX)/build -j4 --no-print-directory > /dev/null
	@echo "Libmlx is read!"

# valgrind
valgrind: $(NAME)
	@valgrind --suppressions=./supressions.sup --leak-check=full \
	--show-leak-kinds=all --track-origins=yes --track-fds=yes ./$(NAME) ./maps.cub/map2.cub

# cleaning object files
clean:
	@echo "Removing objects..."
	@rm -rf obj
	@rm -rf $(LIBMLX)/build
	@make clean -C $(LIBFT) > /dev/null
	@make clean -C $(FT_PRINTF) > /dev/null
	@echo "$(YELLOW)Object cleaned!$(RESET)"

# cleaning executable file
fclean: clean
	@echo "Removing Executables..."
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT)
	@make fclean -C $(FT_PRINTF)
	@echo "$(YELLOW)Cleaning complete!$(RESET)"

re: fclean all

.PHONY: all clean fclean re valgrind
