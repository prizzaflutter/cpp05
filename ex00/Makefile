# Change CXX back to c++ before your evaluation!
CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

NAME = program

SRC = main.cpp Bureaucrat.cpp
OBJ = $(SRC:.cpp=.o)


all: $(NAME)

%.o: %.cpp Bureaucrat.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean: 
	del /Q /F *.o

fclean: clean
	del /Q /F $(NAME).exe

re: fclean all

.PHONY: all clean fclean re