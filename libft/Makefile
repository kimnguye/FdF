#DIRECTORIES
SRC_DIR = src
OBJ_DIR = obj

#FILES .c
LIBFT = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
		ft_strncmp.c ft_strnstr.c ft_memset.c ft_memcpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c ft_bzero.c ft_toupper.c ft_tolower.c \
		ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_atoi_base.c

LST = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

GNL = get_next_line.c get_next_line_utils.c

PRINTF = ft_printf.c ft_printf_c.c ft_printf_d.c ft_printf_i.c ft_printf_p.c \
		ft_printf_s.c ft_printf_u.c ft_printf_x.c ft_printf_X.c ft_put_lld_base.c \
		ft_pow.c

SRCS = $(addprefix $(SRC_DIR)/, $(LIBFT)) $(addprefix $(SRC_DIR)/, $(LST)) \
		$(addprefix $(SRC_DIR)/, $(GNL)) $(addprefix $(SRC_DIR)/, $(PRINTF))

#TARGETS
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
LIBFT_A = libft.a

#COMPILATION COMMAND
CC = cc -Wall -Wextra -Werror

#RULES
all: $(LIBFT_A)
clean:
	@rm -rf $(OBJS)
fclean: clean
	@rm -rf $(LIBFT_A) $(OBJ_DIR)
re: fclean all

#archive several files in one archive file
$(LIBFT_A): $(OBJS)
	@ar rcs $(LIBFT_A) $(OBJS)

# $@ : target
# $< : dependances
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) -c $< -o $@

.PHONY: clean fclean re all bonus

