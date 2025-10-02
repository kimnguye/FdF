FDF 		= 	fdf

FILES 		= 	main.c \
				fdf_0_parsing.c fdf_1_init.c fdf_2_save_map.c \
				fdf_3_transfo1.c fdf_3_transfo2.c \
				fdf_4_draw_map.c fdf_5_view.c \
				fdf_x_events_handler.c fdf_x_launch.c \
				fdf_point_utils.c fdf_map_utils.c fdf_calc_utils.c fdf_img_utils.c \
				fdf_bresenham.c

SRCS 		= 	$(FILES:%=srcs/%)

CC 			= 	cc -Wall -Wextra -Werror  -g -g3 -lm

MLX_PATH	=	minilibx-linux

MLX_MAKE	=	make --no-print-directory  -C $(MLX_PATH)

FLAG_MLX	=   -L$(MLX_PATH) -I/opt/X11/include -Lminilibx-linux -lmlx -L/opt/X11/lib -lX11 -lXext -O3

LIBFT_MAKE 	= 	make --no-print-directory -C libft

LIBFT 		= 	libft.a


all: $(LIBFT) $(FDF)

update:
	@git submodule update --init --recursive

clean:
	@echo "\033[1;32m""Deleting...""\033[0m"
	@$(MLX_MAKE) clean
	@$(LIBFT_MAKE) clean
	@echo "\033[1;32m""make clean: SUCCESS""\033[0m"

fclean: clean
	@$(LIBFT_MAKE) fclean
	@rm -rf $(FDF) $(LIBFT)
	@echo "\033[1;32m""make fclean: SUCCESS""\033[0m"

re: fclean all

bonus: fclean all

$(LIBFT):
	@$(LIBFT_MAKE) all
	@cp libft/$(LIBFT) .

$(FDF): $(SRCS) $(LIBFT)
	@$(MLX_MAKE)
	@$(CC) -o $(FDF) $(SRCS) $(LIBFT) $(FLAG_MLX)
	@echo "\033[1;32m""🎉 compilation of $(FDF): ""SUCCESS !🎉""\033[0m"

#.PHONY POUR LES RULES
.PHONY: clean fclean re all bonus
