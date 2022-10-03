PYTHON = python3

NAME = Grace.py

clean:
	rm -f out

run:
	$(PYTHON) ./$(NAME) > out
	diff ./$(NAME) out

.PHONY: clean run