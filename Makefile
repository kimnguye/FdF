FDF = fdf

UTILS = fdf_point_utils.c fdf_map_utils.c fdf_calc_utils.c fdf_img_utils.c

SRCS = fdf_map_read.c fdf_map_view.c fdf_map_draw.c\
		fdf_transfo_all.c fdf_transfo_rotation.c \
		fdf_events_handler.c fdf_launch.c \
		fdf_bresenham.c fdf_utils.c $(UTILS:%=utils/%)

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
	$(CC) -o $(FDF) $(FDF).c $(SRCS) $(LIBFT) $(FLAGS) -lm

#.PHONY POUR LES RULES
.PHONY: clean fclean re all bonus
