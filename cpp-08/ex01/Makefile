CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98

NAME = span

SRC = main.cpp Span.cpp

OBJ = $(SRC:.cpp=.o)


all: $(NAME)

%.o: %.cpp Span.hpp
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all