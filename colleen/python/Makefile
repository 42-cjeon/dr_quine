PYTHON = python3

NAME = Colleen.py

clean:
	rm -f out

run:
	$(PYTHON) ./$(NAME) > out
	diff ./$(NAME) out

.PHONY: clean run