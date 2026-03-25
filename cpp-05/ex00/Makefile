CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98

NAME = program

SRC = main.cpp Bureaucrat.cpp
OBJ = $(SRC:.cpp=.o)


all: $(NAME)

%.o: %.cpp Bureaucrat.hpp
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
