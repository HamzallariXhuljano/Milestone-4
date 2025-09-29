# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/26 18:22:45 by xhamzall          #+#    #+#              #
#    Updated: 2025/09/29 18:00:52 by xhamzall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fixed

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Fixed.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re
