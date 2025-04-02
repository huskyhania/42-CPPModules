NAME = FragTrap
all: $(NAME)

CPP := c++
FLAGS := -Wall -Wextra -Werror -std=c++11

SOURCE := ClapTrap.cpp ScavTrap.cpp FragTrap.cpp main.cpp
OBJ := $(SOURCE:.cpp=.o)
HEADERS := ClapTrap.hpp ScavTrap.hpp FragTrap.hpp

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
