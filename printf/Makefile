# **************************************************************************** #
#                                   SETTINGS                                   #
# **************************************************************************** #

NAME = libftprintf.a

#Directories
SRC_DIR = src/
OBJ_DIR = obj/

#Complier and Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I .
# -I .: Tell the compiler: “Also search for header files in the
#	current directory .,” so #include "libft.h" can be found here.

CFILES = $(SRC_DIR)/my_printf.c $(SRC_DIR)/putstuff.c $(SRC_DIR)/ft_putptr.c
OFILES = $(CFILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
#CFILES = $(wildcard*.c) #only search in current directory
#CFILES = $(shell find $(SRC_DIR) -name "*.c")
#OFILES = $(CFILES:.c=.o)


# **************************************************************************** #
#                                   COLORS                                     #
# **************************************************************************** #

BOLD	= \033[1m
BLACK	= \033[0;30m
RED		= \033[0;31m
GREEN	= \033[0;32m
YELLOW	= \033[0;33m
BLUE	= \033[0;34m
PURPLE	= \033[0;35m
CYAN	= \033[0;36m
WHITE	= \033[0;37m
NC		= \033[0m
#[0; default [1; bold [2; dim [3; italic
#[4; underline [5; slow blink [7; invert colors


# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: $(NAME)

#Build Library
$(NAME): lft $(OFILES)
	@ar rcs $@ $(OFILES)
	@printf "$(CYAN) ✨ Printf compiled Sucessfully! $(NC)\n"
#ar = archive 工具（做静态库的）
#r = replace/insert（往库里放文件）
#c = create（不存在就创建）
#s = 写索引（方便链接器查找）
# Manual in shell: ar rcs libftprintf.a *.o

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@cc $(CFLAGS) -c $< -o $@
# $< first prerequisite (right-hand side of :)
# $@ target file (left-hand side of :)
# $^ all prerequisites
# Manual: cc -Wall -Wextra -Werror -c *.c #only search in current directory
# Manual: cc -Wall -Wextra -Werror -I . -c $(find src -name '*.c)
# -c: Compile only, don’t link. Produce .o files instead of an executable.


lft:
	@make -C libft
	@mv libft/libft.a libftprintf.a

debug: re
	cc -g -gdwarf-4 main.c -L. -lftprintf -o test
# == cc -g main.c libftprintf.a -o test
# Manual: cc -I . -I libft main.c src/ft_putptr.c src/my_printf.c src/putstuff.c \
#	libft/libft.a -o test

clean:
	@printf "$(YELLOW)🧹 Cleaning printf o-files...$(NC)\n"
	@rm -rf $(OFILES) $(OBJ_DIR)
	@make -C libft clean
	@printf "$(GREEN)✓ Printf Cleaning complete!$(NC)\n"

fclean: clean
	@printf "$(RED)🗡️  Killing printf library...$(NC)\n"
	@rm -rf $(NAME)
	@make -C libft fclean
	@printf "$(GREEN)✓ Full printf cleaning complete!$(NC)\n"

re: fclean all

push:
	git add .
	git commit -m "printf finished ✨"
	git push github master
#	git push origin master

.PHONY: all clean fclean re lft debug push

