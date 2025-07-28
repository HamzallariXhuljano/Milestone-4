# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nakoriko <nakoriko@student.42firenze.it    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 10:21:31 by nakoriko          #+#    #+#              #
#    Updated: 2024/08/25 17:30:21 by nakoriko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_hexa.c ft_num.c ft_char.c
	
OBJ = $(SRCS:.c=.o)

CC = cc

CFLAG = -Wall -Werror -Wextra

NAME = libftft_printf.a

HEADER = ft_printf.h

all: $(NAME)

$(NAME) : $(OBJ)
	@ar -rcs $@ $^

%.o:%.c $(HEADER)
	@$(CC) $(CFLAG) -c $< -o $@

clean:
	@rm -f $(OBJ)
	
fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
