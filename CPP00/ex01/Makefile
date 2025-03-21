NAME = Phonebook
all: $(NAME)

CPP := c++
FLAGS := -Wall -Wextra -Werror -std=c++98

SOURCE := main.cpp Phonebook.cpp Contact.cpp
OBJ := $(SOURCE:.cpp=.o)

$(NAME) : $(OBJ)
	$(CPP) $(FLAGS) $(OBJ) -o $(NAME) 

%.o : %.cpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
