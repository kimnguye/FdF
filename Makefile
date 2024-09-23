FDF = fdf

UTILS = fdf_point_utils.c fdf_map_utils.c fdf_calc_utils.c fdf_img_utils.c \
		fdf_bresenham.c

FILES = fdf_0_parsing.c fdf_1_init.c fdf_2_save_map.c \
		fdf_3_transfo1.c fdf_3_transfo2.c \
		fdf_4_draw_map.c fdf_5_view.c \
		fdf_x_events_handler.c fdf_x_launch.c

SRCS = $(UTILS:%=utils/%) $(FILES:%=srcs/%)

LIBFT_MAKE = make --no-print-directory -C libft
LIBFT = libft.a
CC = cc -Wall -Wextra -Werror
FLAGS = -L"\\wsl.localhost\Ubuntu\mnt\wslg\distro\usr\local\lib\libmlx.a" -lmlx -lXext -lX11
FLAG42 = -L"/home/kimnguye/sgoinfre/minilibx-linux" -lmlx -lXext -lX11
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

$(FDF): $(FDF).c $(SRCS) $(LIBFT)
	$(CC) -o $(FDF) $(FDF).c $(SRCS) $(LIBFT) $(FLAG42) -lm

#.PHONY POUR LES RULES
.PHONY: clean fclean re all bonus
