NAME = PmergeMe
all: $(NAME)

CPP := c++
FLAGS := -Wall -Wextra -Werror -std=c++17

SOURCE := main.cpp PmergeMe.cpp
OBJ := $(SOURCE:.cpp=.o)
HEADERS := PmergeMe.hpp

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
