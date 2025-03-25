NAME = fight
all: $(NAME)

CPP := c++
FLAGS := -Wall -Wextra -Werror -std=c++11

SOURCE := HumanA.cpp HumanB.cpp Weapon.cpp main.cpp
OBJ := $(SOURCE:.cpp=.o)
HEADERS := HumanA.hpp HumanB.hpp Weapon.hpp

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
