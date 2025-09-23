# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/23 13:23:46 by xhamzall          #+#    #+#              #
#    Updated: 2025/09/23 13:25:05 by xhamzall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = walkingdead

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Zombie.cpp zombieHorde.cpp main.cpp
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
