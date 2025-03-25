NAME = Harl

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++11

SOURCE = main.cpp Harl.cpp
OBJECT = $(SOURCE:.cpp=.o)
HEADERS = Harl.hpp

all: $(NAME)

$(NAME) : $(OBJECT) 
	$(CPP) $(FLAGS) $(OBJECT) -o $(NAME)

%.o : %.cpp $(HEADERS)
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJECT)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
