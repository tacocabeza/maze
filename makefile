CC = gcc
INC_DIR = ./
DEPS = $INC_DIR/process.h
CFLAGS = -g -Wall -Werror -Wextra -I$(INC_DIR)
OBJ = main.o process.o
BIN = main

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

all: clean $(BIN)

.PHONY: clean

clean:
	rm -f $(BIN) *.o
