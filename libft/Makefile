# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qianshuyin <qianshuyin@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/16 00:29:40 by sqian             #+#    #+#              #
#    Updated: 2026/04/25 14:30:08 by qianshuyin       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                   SETTINGS                                   #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Werror -Wextra -I.

# Directories
SRC_DIR = src
OBJ_DIR = obj
DEBUG_DIR = obj/debug


# **************************************************************************** #
#                                  SOURCES                                     #
# **************************************************************************** #
IS_DIR =	$(SRC_DIR)/ft_is/ft_isalpha.c\
			$(SRC_DIR)/ft_is/ft_isalnum.c\
			$(SRC_DIR)/ft_is/ft_isascii.c\
			$(SRC_DIR)/ft_is/ft_isdigit.c\
			$(SRC_DIR)/ft_is/ft_isprint.c\

MEM_DIR =	$(SRC_DIR)/ft_mem/ft_memchr.c\
			$(SRC_DIR)/ft_mem/ft_memcmp.c\
			$(SRC_DIR)/ft_mem/ft_memcpy.c\
			$(SRC_DIR)/ft_mem/ft_memmove.c\
			$(SRC_DIR)/ft_mem/ft_memset.c\
			$(SRC_DIR)/ft_mem/ft_bzero.c\
			$(SRC_DIR)/ft_mem/ft_calloc.c\

STR_DIR =	$(SRC_DIR)/ft_str/ft_strchr.c\
			$(SRC_DIR)/ft_str/ft_strrchr.c\
			$(SRC_DIR)/ft_str/ft_strnstr.c\
			$(SRC_DIR)/ft_str/ft_strncmp.c\
			$(SRC_DIR)/ft_str/ft_strlen.c\
			$(SRC_DIR)/ft_str/ft_strlcpy.c\
			$(SRC_DIR)/ft_str/ft_strdup.c\
			$(SRC_DIR)/ft_str/ft_strjoin.c\
			$(SRC_DIR)/ft_str/ft_strlcat.c\
			$(SRC_DIR)/ft_str/ft_substr.c\
			$(SRC_DIR)/ft_str/ft_split.c\
			$(SRC_DIR)/ft_str/ft_strtrim.c\
			$(SRC_DIR)/ft_str/ft_striteri.c\
			$(SRC_DIR)/ft_str/ft_strmapi.c\

TO_DIR =	$(SRC_DIR)/ft_to/ft_atoi.c\
			$(SRC_DIR)/ft_to/ft_itoa.c\
			$(SRC_DIR)/ft_to/ft_tolower.c\
			$(SRC_DIR)/ft_to/ft_toupper.c\

PUT_DIR =	$(SRC_DIR)/ft_put/ft_putchar_fd.c\
			$(SRC_DIR)/ft_put/ft_putnbr_fd.c\
			$(SRC_DIR)/ft_put/ft_putstr_fd.c\
			$(SRC_DIR)/ft_put/ft_putendl_fd.c\

LST_DIR =	$(SRC_DIR)/ft_lst/ft_lstnew_bonus.c\
			$(SRC_DIR)/ft_lst/ft_lstlast_bonus.c\
			$(SRC_DIR)/ft_lst/ft_lstmap_bonus.c\
			$(SRC_DIR)/ft_lst/ft_lstsize_bonus.c\
			$(SRC_DIR)/ft_lst/ft_lstiter_bonus.c\
			$(SRC_DIR)/ft_lst/ft_lstadd_front_bonus.c\
			$(SRC_DIR)/ft_lst/ft_lstadd_back_bonus.c\
			$(SRC_DIR)/ft_lst/ft_lstdelone_bonus.c\
			$(SRC_DIR)/ft_lst/ft_lstclear_bonus.c

# Concatenate all source files
SRC = $(IS_DIR) $(MEM_DIR) $(STR_DIR) $(TO_DIR) $(PUT_DIR)
SRC_BONUS = $(LST_DIR)

# SRC = $(shell find $(SRC_DIR) -name "*.c")
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
BOBJ = $(SRC_BONUS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEBUG_OBJ = $(SRC:$(SRC_DIR)/%.c=$(DEBUG_DIR)/%.debug.o)


# **************************************************************************** #
#                                   COLORS                                     #
# **************************************************************************** #

NC		= \033[0m
RED		= \033[0;31m
GREEN	= \033[1;32m
YELLOW	= \033[0;33m
BLUE	= \033[0;34m
PURPLE	= \033[0;35m
CYAN	= \033[0;36m


# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: $(NAME)
# tell make the goal is to make the lib

# Normal Objects
$(NAME): $(OBJ)
	ar rcs $@ $^
	@printf "$(CYAN) ✨ Compiled Sucessfully! $(NC)\n"
# rule to make the lib
#r → replace: 替换库里同名的对象文件
#c → create: 如果库不存在就创建
#s → index: 生成符号索引，方便链接

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
# rule to make o-files

# Bonus
bonus: $(OBJ) $(BOBJ)
	ar rcs $(NAME) $^

# Debug Build
$(DEBUG_DIR)/%.debug.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $(DEBUG_DIR))
	$(CC) $(CFLAGS) -g -o0 -c $< -o $@
#Add debug info(line number, variable name, symbol table)
#Explicitly tell the compiler not to perform any optimizations

debug: $(DEBUG_OBJ)
	$(CC) $(DEBUG_OBJ) -o magic

# Cleaning
clean:
	@printf "$(RED) 🧹 Cleaning o-files...$(NC)\n"
	@rm -rf $(OBJ) $(DEBUG_OBJ) $(BOBJ) $(OBJ_DIR)
	@printf "$(GREEN) ✓ Clean complete!$(NC)\n"

fclean: clean
	@printf "$(RED)🗑️ Removing library & o-files...$(NC)\n"
	@rm -rf $(NAME)
	@printf "$(GREEN)✓ Everything cleaned!$(NC)\n"

re: fclean all

push:
	git add .
	git commit -m "o directory removed"
	git push

.PHONY: all bonus debug clean fclean re push
