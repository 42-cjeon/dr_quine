CC = clang

ASM = nasm
ASMFLAGS = -f macho64 -w+all

NAME = Grace

OBJ = Grace.o

SRC = Grace.s

%.o : %.s
	$(ASM) $(ASMFLAGS) -o $@ $^

$(NAME): $(OBJ)
	$(CC) -o $@ $^

all: $(NAME)

clean:
	rm -f $(OBJ)
	rm -f Grace_kid.s

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

run: all
	./$(NAME)
	diff ./$(SRC) Grace_kid.s

.PHONY: all clean fclean re run