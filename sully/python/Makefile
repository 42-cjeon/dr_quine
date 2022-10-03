PYTHON = python3

BASENAME = Sully
NAME = $(BASENAME).py

clean:
	rm -f out
	rm -f $(BASENAME)_*

run:
	$(PYTHON) ./$(NAME)
	diff ./$(NAME) ./$(BASENAME)_4.py; diff ./$(NAME) ./$(BASENAME)_3.py; diff ./$(NAME) ./$(BASENAME)_2.py; diff ./$(NAME) ./$(BASENAME)_1.py; diff ./$(NAME) ./$(BASENAME)_0.py

.PHONY: clean run