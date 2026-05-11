NAME = push_swap

CC = cc
CFLAGS =  -I. -g -Wall -Werror -Wextra

OBJ_DIR = obj

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

# **************************************************************************** #
#                                  SOURCES                                     #
# **************************************************************************** #

SRC =	main.c \
		operators/push.c \
		operators/rev_rotate.c \
		operators/rotate.c \
		operators/swap.c \
		operators/utility.c \
		init.c \
		utility1.c \
		utility2.c \
		utility3.c \
		sort.c \
		error_handler.c

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

# **************************************************************************** #
#                                   COLORS                                     #
# **************************************************************************** #

NC		= \033[0m
RED		= \033[0;31m
GREEN	= \033[0;32m
CYAN	= \033[0;36m

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: $(LIBFT) $(PRINTF) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -L$(PRINTF_DIR) -lft -lftprintf -o $(NAME)
	@printf "$(CYAN) ✨ Push_Swap Compiled Successfully! $(NC)\n"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean

fclean:
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@printf "$(GREEN) 🗑️  Push_Swap everything cleaned!$(NC)\n"

re: fclean all

norm:
	norminette $(SRC)

.PHONY: all clean fclean re norm
