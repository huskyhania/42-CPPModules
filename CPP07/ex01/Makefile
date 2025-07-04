# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/08 14:07:22 by hskrzypi          #+#    #+#              #
#    Updated: 2025/06/08 14:07:25 by hskrzypi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tryme
all: $(NAME)

CPP := c++
FLAGS := -Wall -Wextra -Werror -std=c++17

SOURCE :=  main.cpp
OBJ := $(SOURCE:.cpp=.o)
HEADERS := iter.hpp

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
