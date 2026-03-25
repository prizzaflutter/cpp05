CC = c++
Flags = -Wall -Werror -Wextra -std=c++98

NAME = program

SRC = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
OBJ = $(SRC:.cpp=.o)


all: $(NAME)

%.o: %.cpp Bureaucrat.hpp Form.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp ShrubberyCreationForm.hpp
	$(CC) $(Flags) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(Flags) $(OBJ) -o $(NAME)

clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -rf  $(NAME)
