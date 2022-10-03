CC = clang
CFLAGS = -Wall -Wextra -Werror

NAME = Grace

OBJ = Grace.o

SRC = Grace.c

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

all: $(NAME)

clean:
	rm -f $(OBJ)
	rm -f out

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

run: all
	./$(NAME) > out
	diff ./$(SRC) out

.PHONY: all clean fclean re run