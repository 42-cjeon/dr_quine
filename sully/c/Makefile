CC = clang
CFLAGS = -Wall -Wextra -Werror

NAME = Sully

OBJ = Sully.o

SRC = Sully.c

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

all: $(NAME)

clean:
	rm -f $(OBJ)
	rm -f out
	rm -f $(NAME)_*

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

run: all
	./$(NAME)
	diff ./$(SRC) ./$(NAME)_5.c; diff ./$(SRC) ./$(NAME)_4.c; diff ./$(SRC) ./$(NAME)_3.c; diff ./$(SRC) ./$(NAME)_2.c; diff ./$(SRC) ./$(NAME)_1.c; diff ./$(SRC) ./$(NAME)_0.c

.PHONY: all clean fclean re run