# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/27 16:43:15 by hskrzypi          #+#    #+#              #
#    Updated: 2025/07/27 16:46:23 by hskrzypi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RPN
all: $(NAME)

CPP := c++
FLAGS := -Wall -Wextra -Werror -std=c++17

SOURCE := main.cpp RPN.cpp
OBJ := $(SOURCE:.cpp=.o)
HEADERS := RPN.hpp

$(NAME) : $(OBJ)
	$(CPP) $(FLAGS) $(OBJ) -o $(NAME) 

%.o : %.cpp $(HEADERS)
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
