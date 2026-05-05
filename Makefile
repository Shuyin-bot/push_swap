NAME = push_swap

CC = cc
CFLAGS =  -I. -g -fsanitize=address -Wall -Werror -Wextra

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
GREEN	= \033[1;32m
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
	@printf "$(CYAN) ✨ Compiled Successfully! $(NC)\n"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@printf "$(RED) 🧹 Cleaning o-files...$(NC)\n"
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean
	@printf "$(GREEN) ✓ Clean complete!$(NC)\n"

fclean: clean
	@printf "$(RED)🗑️  Removing binary & o-files...$(NC)\n"
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@printf "$(GREEN)✓ Everything cleaned!$(NC)\n"

re: fclean all

norm:
	norminette $(SRC)

.PHONY: all clean fclean re norm
