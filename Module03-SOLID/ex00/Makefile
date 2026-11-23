##------------------------------------##
NAME = srp

SRCS =	main.cpp \
		car.cpp \
		engine.cpp \
		transmission.cpp \
		steering.cpp \
		brakes.cpp #
OBJS = $(SRCS:.cpp=.o)

CC = c++
FLAGS = -Wall -Wextra -Werror -Wno-unknown-pragmas -std=c++98 -g
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