NAME = cub3D
NAME_BONUS = cub3D_bonus
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
			graphic/texture.c \
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

SRCS_BONUS = ${addprefix srcs_bonus/, \
			graphic_bonus/clear_game_bonus.c \
			graphic_bonus/draw_background_bonus.c \
			graphic_bonus/vector_utils_bonus.c \
			graphic_bonus/setting_game_bonus.c \
			graphic_bonus/draw_wall_bonus.c \
			graphic_bonus/algorithm_dda_bonus.c \
			graphic_bonus/draw_view_bonus.c \
			graphic_bonus/moviments_bonus.c \
			graphic_bonus/moviments_restriction_bonus.c \
			graphic_bonus/key_hook_bonus.c \
			graphic_bonus/texture_bonus.c \
			graphic_bonus/minimap_bonus.c \
			graphic_bonus/collectable_bonus.c \
			graphic_bonus/collectibles_utils_bonus.c\
			graphic_bonus/draw_collectibles_bonus.c \
			graphic_bonus/exit_bonus.c \
			graphic_bonus/sounds_bonus.c \
			main_bonus.c \
			data_pipeline_bonus/validation_bonus.c \
			data_pipeline_bonus/extract_bonus.c \
			data_pipeline_bonus/pipeline_bonus.c \
			data_pipeline_bonus/load_bonus.c \
			data_pipeline_bonus/utils_bonus.c \
			data_pipeline_bonus/textures_analysis_bonus.c \
			data_pipeline_bonus/color_analysis_bonus.c \
			data_pipeline_bonus/map_analysis_bonus.c \
}

OBJS = $(SRCS:srcs/%.c=obj/%.o)

OBJS_BONUS = $(SRCS_BONUS:srcs_bonus/%.c=obj_bonus/%.o)

# RULES MANDATORY
all: $(NAME)

$(NAME): libmlx  libft ft_printf $(OBJS)
	@echo "Compiling cub3d"
	@cc $(FLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "$(GREEN)cub3d is read!✅$(RESET)"

obj/%.o: srcs/%.c
	@mkdir -p obj $(dir $@)
	@cc $(FLAGS) -c $< -o $@

# RULES BONUS
bonus: $(NAME_BONUS)

$(NAME_BONUS): libmlx  libft ft_printf $(OBJS_BONUS)
	@echo "Compiling cub3d"
	@cc $(FLAGS) $(OBJS_BONUS) $(LIBS) -o $(NAME_BONUS)
	@echo "$(GREEN)cub3d_bonus is read!✅$(RESET)"

obj_bonus/%.o: srcs_bonus/%.c include/cub3d_bonus.h
	@mkdir -p obj_bonus $(dir $@)
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
	--show-leak-kinds=all --track-origins=yes ./$(NAME_BONUS) ./maps.cub/map_bonus1.cub

# cleaning object files
clean:
	@echo "Removing objects..."
	@rm -rf obj
	@rm -rf obj_bonus
	@rm -rf $(LIBMLX)/build
	@make clean -C $(LIBFT) > /dev/null
	@make clean -C $(FT_PRINTF) > /dev/null
	@echo "$(YELLOW)Object cleaned!$(RESET)"

# cleaning executable file
fclean: clean
	@echo "Removing Executables..."
	@rm -rf $(NAME)
	@rm -rf $(NAME_BONUS)
	@make fclean -C $(LIBFT)
	@make fclean -C $(FT_PRINTF)
	@echo "$(YELLOW)Cleaning complete!$(RESET)"

re: fclean all

.PHONY: all bonus clean fclean re valgrind
