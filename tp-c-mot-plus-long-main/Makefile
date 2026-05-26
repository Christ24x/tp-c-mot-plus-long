CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SOURCES = main.c save.c
HEADERS = save.h
EXECUTABLE = jeu

.PHONY: all clean run

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE)

run: $(EXECUTABLE)
	./$(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE) save.txt

.DEFAULT_GOAL := all
