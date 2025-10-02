FDF = fdf

FILES = fdf_0_parsing.c fdf_1_init.c fdf_2_save_map.c \
		fdf_3_transfo1.c fdf_3_transfo2.c \
		fdf_4_draw_map.c fdf_5_view.c \
		fdf_x_events_handler.c fdf_x_launch.c \
		fdf_point_utils.c fdf_map_utils.c fdf_calc_utils.c fdf_img_utils.c \
		fdf_bresenham.c

SRCS = $(FILES:%=srcs/%)

LIBFT_MAKE = make --no-print-directory -C libft

LIBFT = libft.a

CC = cc -Wall -Wextra -Werror  -g -g3 -lm

MLX_PATH	=	minilibx-linux

MLX_MAKE	=	make -C $(MLX_PATH)

FLAG_MLX	=   -L$(MLX_PATH) -I/opt/X11/include -Lminilibx-linux -lmlx -L/opt/X11/lib -lX11 -lXext -O3
#FLAG42 = -L"/home/kimnguye/sgoinfre/minilibx-linux" -lmlx -lXext -lX11 -O3


all: $(LIBFT) $(FDF)

clean:
	@echo "Deleting..."
	@$(LIBFT_MAKE) clean
	@echo "rm *.o"

fclean: clean
	@$(LIBFT_MAKE) fclean
	rm -rf $(FDF) $(LIBFT)

re: fclean all

bonus: fclean all

$(LIBFT):
	@$(LIBFT_MAKE) all
	@cp libft/$(LIBFT) .

$(FDF): main.c $(SRCS) $(LIBFT)
	$(CC) -o $(FDF) main.c $(SRCS) $(LIBFT) $(FLAG_MLX)

#.PHONY POUR LES RULES
.PHONY: clean fclean re all bonus
