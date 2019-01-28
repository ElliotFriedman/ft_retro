NAME = a.out

CLASSES = Game LivingObject main #GameObject
MODULES = #main

CXX = clang++
CPPFLAGS += -Wall -Wextra -Werror -I ./ -g -fsanitize=address

CLS_SRC = $(addsuffix .cpp, $(CLASSES))
SRC = $(CLS_SRC) $(addsuffix .cpp, $(MODULES))
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -lcurses -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
