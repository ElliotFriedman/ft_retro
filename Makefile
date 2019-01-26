NAME = a.out

CLASSES = Game GameObject
MODULES = main

CXX = clang++
CPPFLAGS += -Wall -Wextra -Werror -Wpedantic -I ./

CLS_SRC = $(addsuffix .cpp, $(CLASSES))
SRC = $(CLS_SRC) $(addsuffix .cpp, $(MODULES))
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
