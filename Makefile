TITLE = unflex-test
CC    = gcc

default:
	$(CC) -o $(TITLE) unflex.c
	./$(TITLE)
