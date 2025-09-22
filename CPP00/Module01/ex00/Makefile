# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/18 16:26:45 by xhamzall          #+#    #+#              #
#    Updated: 2025/09/22 16:45:30 by xhamzall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = log

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Zombie.cpp newZombie.cpp randomChump.cpp main.cpp
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
