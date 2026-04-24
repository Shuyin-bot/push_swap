NAME = push_swap

CC = cc
#CFLAGS = -Wall -Werror -Wextra -I.
CFLAGS =  -I. -g

OBJ_DIR = obj

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# **************************************************************************** #
#                                  SOURCES                                     #
# **************************************************************************** #

SRC =	main.c \


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

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)
	@printf "$(CYAN) ✨ Compiled Successfully! $(NC)\n"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@printf "$(RED) 🧹 Cleaning o-files...$(NC)\n"
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@printf "$(GREEN) ✓ Clean complete!$(NC)\n"

fclean: clean
	@printf "$(RED)🗑️  Removing binary & o-files...$(NC)\n"
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@printf "$(GREEN)✓ Everything cleaned!$(NC)\n"

re: fclean all

.PHONY: all clean fclean re
