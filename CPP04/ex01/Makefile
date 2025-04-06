NAME = zoo
all: $(NAME)

CPP := c++
FLAGS := -Wall -Wextra -Werror -std=c++11

SOURCE := Animal.cpp Cat.cpp Dog.cpp main.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
OBJ := $(SOURCE:.cpp=.o)
HEADERS := Animal.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp Brain.hpp

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
