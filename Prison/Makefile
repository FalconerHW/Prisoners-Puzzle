
CC = gcc
CFLAGS = -Wall -Werror -g

COMMON = boxes.o search.o helper.o

.PHONY: all
all: runPrison

runPrison: runPrison.o $(COMMON)
	$(CC) $(CFLAGS) -o runPrison runPrison.o $(COMMON) -lm

runPrison.o: runPrison.c

boxes.o: boxes.c
search.o: search.c
helper.o: helper.c

.PHONY: clean
clean:
	rm -f *.o runPrison
