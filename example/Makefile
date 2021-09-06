CC = gcc
CFLAGS = -Wall
LDFLAGS = -lm

all: usage_example_lib.out

usage_example_lib.out: usage_example_lib.o
	$(CC) $(CFLAGS) -o usage_example_lib.out usage_example_lib.o -lconfRead $(LDFLAGS)

usage_example_lib.o: usage_example_lib.c
	$(CC) $(CFLAGS) -o usage_example_lib.o -c usage_example_lib.c

clean:
	rm -f *.o *.out
