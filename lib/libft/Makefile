# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvolovik <rvolovik@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/01 17:23:08 by rvolovik          #+#    #+#              #
#    Updated: 2017/06/01 20:18:50 by rvolovik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c \
ft_bzero.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_itoa.c \
ft_lstadd.c \
ft_lstdel.c \
ft_lstdelone.c \
ft_lstiter.c \
ft_lstmap.c \
ft_lstnew.c \
ft_memalloc.c \
ft_memccpy.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memdel.c \
ft_memmove.c \
ft_memset.c \
ft_putchar.c \
ft_putchar_fd.c \
ft_putendl.c \
ft_putendl_fd.c \
ft_putnbr.c \
ft_putnbr_fd.c \
ft_putstr.c \
ft_putstr_fd.c \
ft_strcat.c \
ft_strchr.c \
ft_strclr.c \
ft_strcmp.c \
ft_strcpy.c \
ft_strdel.c \
ft_strdup.c \
ft_strequ.c \
ft_striter.c \
ft_striteri.c \
ft_strjoin.c \
ft_strlcat.c \
ft_strlen.c \
ft_strmap.c \
ft_strmapi.c \
ft_strncat.c \
ft_strncmp.c \
ft_strncpy.c \
ft_strnequ.c \
ft_strnew.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strsplit.c \
ft_strstr.c \
ft_strsub.c \
ft_strtrim.c \
ft_tolower.c \
ft_toupper.c \
all_delims_split.c \
stack.c

INC = includes/libft.h

OBJ = $(SRC:.c=.o)

CFLAGS = -c -Wall -Wextra -Werror

all:  $(NAME)

$(NAME): $(OBJ)
	@echo "\t\x1b[01;32m[Objects created]\x1b[0m"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo  "\x1b[01;32m[Libft compiled]\x1b[0m"

%.o: %.c
	@echo "\033[01;32m|\c\x1b[0m"
	@gcc -I $(INC) $(CFLAGS) -o $@ $<

clean:
	@echo "\033[01;31m[Objects deleted]\x1b[0m"
	@rm -f $(OBJ)

fclean: clean
	@echo "\033[01;31m[Libtf deleted]\x1b[0m"
	@rm -f $(NAME)

re: fclean all
