# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/12 23:15:03 by hdeniz            #+#    #+#              #
#    Updated: 2023/09/04 12:28:49 by hdeniz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
# [COMPILER]

MLX			=	./minilibx/libmlx.a
# [MINILIBX LIBRARY]

FLAGS		=	-Imlx
# [COMPILER FLAGS]

MAIN_FLAGS	=	-Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit -L./minilibx
# [COMPILER FLAGS]

# [LIBFT]
LIBFT_OBJ	=	./libft/ft_strdup.c \
				./libft/ft_strlen.c \
				./libft/ft_rand.c \
				./libft/ft_strjoin.c \
				./libft/ft_strlcat.c \
				./libft/ft_strlcpy.c \
				./libft/ft_split.c \
				./libft/ft_putnbr.c \
				./libft/ft_free_matrix.c \
				./libft/ft_copy_matrix.c \
				./libft/ft_print_matrix.c \
				./libft/ft_matrixlen.c \
				./libft/ft_numlen.c \
				./libft/ft_math/Other/ft_lerp.c \
				./libft/ft_math/Other/ft_mini.c \
				./libft/ft_math/Other/ft_fabs.c \
				./libft/ft_math/Other/ft_fmax.c \
				./libft/get_next_line/get_next_line_utils.c \
				./libft/get_next_line/get_next_line.c
# [LIBFT]

# [MAIN]
	NAME		=	./main/so_long.a
	# [COMPILED LIBRARY FILE'S NAME (STATIC LINK LIBRARY)]

	MAIN		=	./main/so_long.c
	# [MAIN PRODUCT TO COMPILE]

	SRC			=	./main/exit_functions/mlx_error.c \
					./main/exit_functions/close_window.c \
					./main/set_mlx/set_mlx.c \
					./main/set_mlx/free_textures.c \
					./main/set_mlx/xpm_texture.c \
					./main/set_mlx/free_objects.c \
					./main/set_mlx/set_walls_as_objects.c \
					./main/set_mlx/set_coins_as_objects.c \
					./main/set_mlx/set_map_textures.c \
					./main/set_mlx/load_textures/load_textures.c \
					./main/set_mlx/load_textures/load_player.c \
					./main/set_mlx/load_textures/load_wall.c \
					./main/set_mlx/load_textures/load_coin.c \
					./main/set_mlx/load_textures/load_gate.c \
					./main/check_map/check_map.c \
					./main/check_map/check_map_file.c \
					./main/check_map/check_coin.c \
					./main/check_map/check_gate.c \
					./main/check_map/check_player.c \
					./main/check_map/check_if_rows_equal.c \
					./main/check_map/check_invalid_entity.c \
					./main/check_map/check_if_map_fits.c \
					./main/check_map/check_ambient_walls.c \
					./main/check_map/check_barriers.c \
					./main/check_map/search_in_map.c \
					./main/check_map/count_in_map.c \
					./main/events/key_down.c \
					./main/events/key_up.c \
					./main/events/player_position.c \
					./main/events/debug.c \
					./main/events/game.c \
					./main/events/graphic/draw_background.c \
					./main/events/graphic/draw_wall.c \
					./main/events/graphic/draw_item.c \
					./main/events/graphic/draw_gate.c \
					./main/events/graphic/draw_player.c \
					./main/events/graphic/put_image.c \
					./main/map_generator/map_generator.c
	SRC			+=	$(LIBFT_OBJ)
	# [FILES TO COMPILE]

	OBJ			=	$(eval OBJ := $$(SRC:.c=.o))$(OBJ)
	# [.c FILE NAMES TO .o]
# [MAIN]

# [BONUS]
	BONUS_NAME	=	./bonus/so_long_bonus.a
	# [COMPILED BONUS LIBRARY FILE'S NAME (STATIC LINK LIBRARY)]

	BONUS		=	./bonus/so_long.c
	# [BONUS FILE]

	BONUS_SRC	=	./bonus/exit_functions/mlx_error.c \
					./bonus/exit_functions/close_window.c \
					./bonus/set_mlx/set_mlx.c \
					./bonus/set_mlx/free_textures.c \
					./bonus/set_mlx/xpm_texture.c \
					./bonus/set_mlx/free_objects.c \
					./bonus/set_mlx/set_walls_as_objects.c \
					./bonus/set_mlx/set_coins_as_objects.c \
					./bonus/set_mlx/set_map_textures.c \
					./bonus/set_mlx/create_monsters.c \
					./bonus/set_mlx/load_textures/load_textures.c \
					./bonus/set_mlx/load_textures/load_player.c \
					./bonus/set_mlx/load_textures/load_wall.c \
					./bonus/set_mlx/load_textures/load_coin.c \
					./bonus/set_mlx/load_textures/load_gate.c \
					./bonus/set_mlx/load_textures/load_monster.c \
					./bonus/check_map/check_map.c \
					./bonus/check_map/check_map_file.c \
					./bonus/check_map/check_coin.c \
					./bonus/check_map/check_gate.c \
					./bonus/check_map/check_player.c \
					./bonus/check_map/check_if_rows_equal.c \
					./bonus/check_map/check_invalid_entity.c \
					./bonus/check_map/check_if_map_fits.c \
					./bonus/check_map/check_ambient_walls.c \
					./bonus/check_map/check_barriers.c \
					./bonus/check_map/search_in_map.c \
					./bonus/check_map/count_in_map.c \
					./bonus/events/key_down.c \
					./bonus/events/key_up.c \
					./bonus/events/player_position.c \
					./bonus/events/debug.c \
					./bonus/events/game.c \
					./bonus/events/monster_ai.c \
					./bonus/events/graphic/draw_background.c \
					./bonus/events/graphic/draw_wall.c \
					./bonus/events/graphic/draw_item.c \
					./bonus/events/graphic/draw_gate.c \
					./bonus/events/graphic/draw_player.c \
					./bonus/events/graphic/put_image.c \
					./bonus/events/graphic/draw_monster.c \
					./bonus/map_generator/map_generator.c
	BONUS_SRC		+=	$(LIBFT_OBJ)
	# [BONUS FILES TO COMPILE]

	BONUS_OBJ	=	$(eval BONUS_OBJ := $$(BONUS_SRC:.c=.o))$(BONUS_OBJ)
	# [.c FILE NAMES TO .o]
# [BONUS]

# ANIMATION VARIABLES
N_FILES		:=	0
FILES_N		:=	0
# ANIMATION VARIABLES

# ANIMATION
define progress_bar
	$(eval PBAR := $(shell echo $(1)*100/$(2)*100/100 | bc))
	$(eval PDONE := $(shell echo $(PBAR)*4/10 | bc))
	$(eval PLEFT := $(shell echo 40-$(PDONE) | bc))
	$(eval PSEQ := $(shell seq 0 1 $(PLEFT) 2>/dev/null))
	$(eval PEMPTY := $(shell if [ "$(1)" -ne "$(2)" ]; then printf "░%.0s" $(PSEQ); fi))
	$(eval PFILL := $(shell printf "█%.0s" $(shell seq 1 $(PDONE))))
	@printf "\r $(shell tput setaf 11)[$(shell tput setaf 14)$(PFILL)$(PEMPTY)$(shell tput setaf 11)] $(PBAR)%% - $(shell tput setaf 10)[$(1)/$(2)]$(shell tput setaf 11) [$(shell tput setaf 13)$(3)$(shell tput setaf 11)]                                    "
endef
# ANIMATION

a: all
all: $(NAME)

%.o: %.c
	$(eval FILES_N := $(shell echo $(FILES_N)+1 | bc))
	$(call progress_bar,$(FILES_N),$(N_FILES),$<)
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): mlx files_n_calculator $(OBJ)
	@ar -rcs $(NAME) $(OBJ)
	@echo ""
	@echo ""
	@echo " $(shell tput setab 2)$(shell tput setaf 15)$(NAME) Done !$(shell tput sgr0)"
	@echo ""
	@if [ -a $(MAIN) ]; \
	then \
		$(CC) $(FLAGS) $(MAIN) $(NAME) $(MLX) $(MAIN_FLAGS) -o $(MAIN:.c=); \
		mv $(MAIN:.c=) "./so_long"; \
		echo " $(shell tput setab 2)$(shell tput setaf 15)$(MAIN) Done !$(shell tput sgr0)" ; \
		echo "" ; \
	fi;

c: clean
clear: clear
clean:
	@rm -f $(OBJ)
	@rm -f $(BONUS_OBJ)
	@echo ""
	@echo " $(shell tput setaf 15)$(shell tput setab 1)Clearing Objective Files$(shell tput sgr0)"
	@echo ""

fc: fclean
fclear: fclean
fclean: clean
	@make -C "./minilibx" clean
	@echo " $(shell tput setab 1)$(shell tput setaf 11)minilibx$(shell tput setaf 15) cleared$(shell tput sgr0)"
	@if [ -a $(NAME) ]; \
	then \
		rm -f $(NAME) ; \
		echo "" ; \
		echo " $(shell tput setab 1)$(shell tput setaf 11)$(NAME)$(shell tput setaf 15) deleted$(shell tput sgr0)" ; \
		echo "" ; \
	fi;
	@if [ -a "so_long" ]; \
	then \
		rm -f "so_long" ; \
		echo "" ; \
		echo " $(shell tput setab 1)$(shell tput setaf 11)so_long$(shell tput setaf 15) deleted$(shell tput sgr0)" ; \
		echo "" ; \
	fi;
	@if [ -a "so_long_bonus" ]; \
	then \
		rm -f "so_long_bonus" ; \
		echo "" ; \
		echo " $(shell tput setab 1)$(shell tput setaf 11)so_long_bonus$(shell tput setaf 15) deleted$(shell tput sgr0)" ; \
		echo "" ; \
	fi;

n: norminette
norm: norminette
norminette:
	@echo ""
	@echo " $(shell tput setab 10)$(shell tput setaf 0)Checking Norminette Rules $(shell tput sgr0)"
	@norminette ./main
	@norminette ./bonus
	@norminette ./libft
	@echo ""
	@echo " $(shell tput setab 11)$(shell tput setaf 0)Checking Header Norminette Rules $(shell tput sgr0)"
	@norminette -R CheckDefine *.h

b: bonus
bonus: mlx files_n_calculator_bonus $(BONUS_OBJ)
	@ar -rcs $(BONUS_NAME) $(BONUS_OBJ)
	@$(CC) $(FLAGS) $(BONUS) $(BONUS_NAME) $(MLX) $(MAIN_FLAGS) -o $(BONUS:.c=)
	@mv $(BONUS:.c=) "./so_long_bonus"
	@echo " $(shell tput setab 2)$(shell tput setaf 15)$(BONUS) Done !$(shell tput sgr0)"
	@echo ""

files_n_calculator:
	@echo "$(shell tput sgr0)"
	@echo ""
	$(eval FILES_N := 0)
	$(eval N_FILES := $(shell echo $(SRC) | wc -w | sed "s/ //g" | bc))

files_n_calculator_bonus:
	@echo "$(shell tput sgr0)"
	@echo ""
	$(eval FILES_N := 0)
	$(eval N_FILES := $(shell echo $(BONUS_SRC) | wc -w | sed "s/ //g" | bc))

r: fclean all
re: fclean all

mlx:
	@echo " $(shell tput setab 10)$(shell tput setaf 0)COMPILING MLX!!!! $(shell tput sgr0)"
	@make -C "./minilibx"
	@echo " $(shell tput setab 2)$(shell tput setaf 15)MLX Done !$(shell tput sgr0)"

.PHONY: all a clean clear c fclean fclear fc re r norminette norm n bonus b mlx