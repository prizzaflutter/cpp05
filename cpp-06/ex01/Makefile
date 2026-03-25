CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98

NAME = program

SRC = main.cpp Serializer.cpp

OBJ = $(SRC:.cpp=.o)


all: $(NAME)

%.o: %.cpp Serializer.hpp Data.hpp
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re