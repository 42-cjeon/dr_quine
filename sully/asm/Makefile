CC = clang

ASM = nasm
ASMFLAGS = -f macho64 -w+all

NAME = Sully

OBJ = Sully.o

SRC = Sully.s

%.o : %.s
	$(ASM) $(ASMFLAGS) -o $@ $^

$(NAME): $(OBJ)
	$(CC) -o $@ $^

all: $(NAME)

clean:
	rm -f $(OBJ)
	rm -f $(NAME)_*
	rm -f out

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

run: all
	./$(NAME)
	diff ./$(SRC) ./$(NAME)_5.s; diff ./$(SRC) ./$(NAME)_4.s; diff ./$(SRC) ./$(NAME)_3.s; diff ./$(SRC) ./$(NAME)_2.s; diff ./$(SRC) ./$(NAME)_1.s; diff ./$(SRC) ./$(NAME)_0.s

.PHONY: all clean fclean re run