NAME = pointermagic

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++11

SOURCE = main.cpp
OBJECT = $(SOURCE:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJECT)
	$(CPP) $(FLAGS) $(OBJECT) -o $(NAME)

%.o : %.cpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJECT)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

