CC = gcc
INC_DIR = ./
DEPS = $INC_DIR/process.h
CFLAGS = -g -Wall -Werror -Wextra -I$(INC_DIR)
OBJ = main.o process.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o
