# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/15 17:23:57 by hskrzypi          #+#    #+#              #
#    Updated: 2025/07/15 17:33:11 by hskrzypi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mutantstack
all: $(NAME)

CPP := c++
FLAGS := -Wall -Wextra -Werror -std=c++11

SOURCE :=  main.cpp
OBJ := $(SOURCE:.cpp=.o)
HEADERS := MutantStack.hpp

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

