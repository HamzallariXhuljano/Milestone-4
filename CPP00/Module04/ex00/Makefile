# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/06 18:07:26 by xhamzall          #+#    #+#              #
#    Updated: 2025/10/24 15:56:30 by xhamzall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = animals

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Animal.cpp Cat.cpp Dog.cpp main.cpp WrongAnimal.cpp WrongCat.cpp
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
