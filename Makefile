# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/25 17:48:33 by ifranc-r          #+#    #+#              #
#    Updated: 2016/02/29 17:38:36 by ifranc-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# This is a minimal set of ANSI/VT100 color codes
_END=\x1b[0m
_BOLD=\x1b[1m  
_UNDER=\x1b[4m
_REV=\x1b[7m

# Colors
_GREY=\x1b[30m
_RED=\x1b[31m
_GREEN=\x1b[32m
_YELLOW=\x1b[33m
_BLUE=\x1b[34m
_PURPLE=\x1b[35m
_CYAN=\x1b[36m
_WHITE=\x1b[37m

# Inverted, i.e. colored backgrounds
_IGREY=\x1b[40m
_IRED=\x1b[41m
_IGREEN=\x1b[42m
_IYELLOW=\x1b[43m
_IBLUE=\x1b[44m
_IPURPLE=\x1b[45m
_ICYAN=\x1b[46m
_IWHITE=\x1b[47m


NAME = fract_ol

HEAD = includes/minilibx_macos/

LIB = -L ./libft/ -lft -L ./includes/minilibx_macos/ -lmlx -framework OpenGL\
	  -framework AppKit

SRC = ./srcs/main.c\
	  srcs/mlx/mlx.c\
	  srcs/key_hook/key_hook.c\
	  srcs/key_hook/funct_key.c\
	  srcs/key_hook/key_mov.c\
	  srcs/mandelbrot/mandelbrot.c\
	  srcs/julia/julia.c\
	  srcs/burningship/burningship.c\
	  srcs/yolo/yolo.c\
	  srcs/shiva/shiva.c\
	  srcs/hotblood/hotblood.c\
	  srcs/goldenratio/goldenratio.c\
	  srcs/tricorn/tricorn.c\


FLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)
OBJS = $(notdir $(OBJ))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@echo "${_CYAN}Start${_END} to compile-> ${_BLUE}${_IWHITE}FRACT_OL${_END}"
	@echo " | "
	@echo " \/ "
	@make -C libft/
	@gcc $(FLAGS) -c $(SRC) -I libft/ -I includes/ -I includes/minilibx_macos/
	@gcc -o $(NAME) $(OBJS) $(LIB)
	@echo " | "
	@echo " \/ "
	@echo "${_GREEN}Succes${_END}-> ${_BLUE}${_IWHITE}FRACT_OL${_END} has been compile"

nar:
	@gcc $(FLAGS) -c $(SRC) -I libft/ -I includes/ -I includes/minilibx_macos/
	@gcc -o $(NAME) $(OBJS) $(LIB)

clean:
	@rm -rf $(OBJS)
	@echo "${_BLUE}${_IWHITE}FRACT_OL${_END} : ${_PURPLE}Delete${_END}-> -files.o-"
	@make clean -C libft/

fclean:
	@rm -rf $(OBJS)
	@echo "${_BLUE}${_IWHITE}FRACT_OL${_END} : ${_PURPLE}Delete${_END}-> -files.o-"
	@make fclean -C libft/
	@rm -rf $(NAME)
	@echo "${_BLUE}${_IWHITE}FRACT_OL${_END}: ${_PURPLE}Delete${_END}-> ${_BLUE}${_IWHITE}$(NAME)${_END}"

re: fclean all
