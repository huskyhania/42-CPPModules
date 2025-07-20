# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/18 15:24:03 by hskrzypi          #+#    #+#              #
#    Updated: 2025/07/18 15:25:52 by hskrzypi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = bts
all: $(NAME)

CPP := c++
FLAGS := -Wall -Wextra -Werror -std=c++17

SOURCE :=  main.cpp
OBJ := $(SOURCE:.cpp=.o)
HEADERS := BitcoinExchange.hpp

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
