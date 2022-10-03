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
	rm -f Grace_kid.c

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

run: all
	./$(NAME)
	diff ./$(SRC) Grace_kid.c

.PHONY: all clean fclean re run