# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/20 16:41:37 by hskrzypi          #+#    #+#              #
#    Updated: 2025/05/20 16:42:12 by hskrzypi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = buro
all: $(NAME)

CPP := c++
FLAGS := -Wall -Wextra -Werror -std=c++11

SOURCE := Bureaucrat.cpp \
			AForm.cpp \
			ShrubberyCreationForm.cpp \
			RobotomyRequestForm.cpp \
			PresidentialPardonForm.cpp \
			Intern.cpp \
			main.cpp
OBJ := $(SOURCE:.cpp=.o)
HEADERS := Bureaucrat.hpp \
			AForm.hpp \
			ShrubberyCreation.hpp \
			RobotomyRequestForm.hpp \
			PresidentialPardonForm.hpp \
			Intern.hpp

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
