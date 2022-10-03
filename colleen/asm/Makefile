CC = clang

ASM = nasm
ASMFLAGS = -f macho64 -w+all

NAME = Colleen

OBJ = Colleen.o

SRC = Colleen.s

%.o : %.s
	$(ASM) $(ASMFLAGS) -o $@ $^

$(NAME): $(OBJ)
	$(CC) -o $@ $^

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