##------------------------------------##
NAME = ocp

SRCS =	main.cpp #
OBJS = $(SRCS:.cpp=.o)

CC = c++
FLAGS = -Wall -Wextra -Werror -Wno-unknown-pragmas -g
##------------------------------------##

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re