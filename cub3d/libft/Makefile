# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 10:21:31 by nakoriko          #+#    #+#              #
#    Updated: 2024/10/15 16:04:44 by nakoriko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_atoi.c ft_itoa.c ft_putnbr_fd.c ft_strlcpy.c ft_tolower.c \
	ft_bzero.c ft_memchr.c ft_putstr_fd.c ft_strlen.c ft_toupper.c \
	ft_calloc.c ft_memcmp.c ft_split.c ft_strmapi.c \
	ft_isalnum.c ft_memcpy.c ft_strchr.c ft_strncmp.c \
	ft_isalpha.c ft_memmove.c ft_strdup.c ft_strnstr.c \
	ft_isascii.c ft_memset.c ft_striteri.c ft_strrchr.c \
	ft_isdigit.c ft_putchar_fd.c ft_strjoin.c ft_strtrim.c \
	ft_isprint.c ft_putendl_fd.c ft_strlcat.c ft_substr.c \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c get_next_line.c \
	get_next_line.utils.c \
	
OBJ = $(SRCS:.c=.o)

CC = cc -g

CFLAG = -Wall -Werror -Wextra

NAME = libft.a

HEADER = libft.h
FT_HELLO = ft_printf

all: $(FT_HELLO) $(NAME)

$(FT_HELLO): 
	@$(MAKE) -C ft_printf

$(NAME) : $(OBJ) 
	@ar -rcs $@ $^

%.o:%.c  $(HEADER) 
	@$(CC) $(CFLAG) -c $< -o $@

clean:
	@rm -f $(OBJ) all_lib.a
	@$(MAKE) clean -C ft_printf/
	
fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C ft_printf/

re: fclean all

bonus: $(OBJ)
	ar -rcs $(NAME) $(OBJ)

.PHONY: clean fclean all re ft_printf
