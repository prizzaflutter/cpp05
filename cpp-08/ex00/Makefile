CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98

NAME = easyfind

SRC = main.cpp 

OBJ = $(SRC:.cpp=.o)


all: $(NAME)

%.o: %.cpp easyfind.hpp
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all