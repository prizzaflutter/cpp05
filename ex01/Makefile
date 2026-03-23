CC = c++
Flags = -Wall -Werror -Wextra -std=c++98

NAME = program

SRC = main.cpp Bureaucrat.cpp Form.cpp
OBJ = $(SRC:.cpp=.o)


all: $(NAME)

%.o: %.cpp Bureaucrat.hpp Form.hpp
	$(CC) $(Flags) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(Flags) $(OBJ) -o $(NAME)

clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -rf  $(NAME)

re: fclean all
