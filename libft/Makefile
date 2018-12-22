# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/27 20:55:57 by ifranc-r          #+#    #+#              #
#    Updated: 2016/01/30 18:07:21 by ifranc-r         ###   ########.fr        #
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

NAME = libft.a

SRC = ft_atoi.c\
	 ft_bzero.c\
	 ft_isalnum.c\
	 ft_isalpha.c\
	 ft_isascii.c\
	 ft_isdigit.c\
	 ft_isprint.c\
	 ft_itoa.c\
	 ft_memalloc.c\
	 ft_memccpy.c\
	 ft_memchr.c\
	 ft_memcmp.c\
	 ft_memcpy.c\
	 ft_memdel.c\
	 ft_memmove.c\
	 ft_memset.c\
	 ft_putchar.c\
	 ft_putchar_fd.c\
	 ft_putendl.c\
	 ft_putendl_fd.c\
	 ft_putnbr.c\
	 ft_putnbr_fd.c\
	 ft_putstr.c\
	 ft_putstr_fd.c\
	 ft_strcat.c\
	 ft_strchr.c\
	 ft_strclr.c\
	 ft_strcmp.c\
	 ft_strcpy.c\
	 ft_strdel.c\
	 ft_strdup.c\
	 ft_strequ.c\
	 ft_striter.c\
	 ft_striteri.c\
	 ft_strjoin.c\
	 ft_strlcat.c\
	 ft_strlen.c\
	 ft_strmap.c\
	 ft_strmapi.c\
	 ft_strncat.c\
	 ft_strncmp.c\
	 ft_strncpy.c\
	 ft_strnequ.c\
	 ft_strnew.c\
	 ft_strnstr.c\
	 ft_strrchr.c\
	 ft_strsplit.c\
	 ft_strstr.c\
	 ft_strtrim.c\
	 ft_strsub.c\
	 ft_tolower.c\
	 ft_toupper.c\
	 ft_lstnew.c\
	 ft_lstdelone.c\
	 ft_lstdel.c\
	 ft_lstadd.c\
	 ft_lstiter.c\
	 ft_lstmap.c\
	 get_next_line.c\
	 ft_freestrjoin.c\
	 ft_abs.c\
	 ft_strrealloc.c\
	 ft_power.c\
	 ft_ditoa.c\
	 ft_exp.c

OUTPUT = $(SRC:.c=.o)

.PHONY: all clean fclean

all: $(NAME)

$(NAME) : $(OUTPUT)
	@echo "  ${_CYAN}Start${_END} to compile -> ${_BLUE}${_IGREEN}LIBFT${_END} "
	@echo "   | "
	@echo "   \/ "
	@ar rc $(NAME) $(OUTPUT)
	@echo "  ${_GREEN}Success${_END} -> ${_BLUE}${_IGREEN}LIBFT${_END} has been compile"

%.o : %.c
	@gcc -I -Werror -Wall -Wextra -c $<

clean :
	@echo "  ${_BLUE}${_IGREEN}LIBFT${_END}: ${_PURPLE}Delete${_END}-> -.o-"
	@rm -rf $(OUTPUT)

fclean : clean
	@echo "  ${_BLUE}${_IGREEN}LIBFT${_END}: ${_PURPLE}Delete${_END}-> ${_BLUE}${_IGREEN}libft${_END}.a"
	@rm -rf $(NAME)

re : fclean all
