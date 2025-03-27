NAME = push_swap.a
HEADER = push_swap.h
FLAGS = -Wall -Wextra -Werror
SRC = 

OBJ = $(SRC: .c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	cc $(FLAGS) -I . -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean	
	rm -f $(NAME)

re: fclean all

.PHONY. all clean fclean re