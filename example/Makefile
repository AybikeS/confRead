CC = gcc
CFLAGS = -Wall
LDFLAGS = -lm

all: test.out

test.out: test.o
	$(CC) $(CFLAGS) -o test.out test.o -lconfRead $(LDFLAGS)

test.o: test.c
	$(CC) $(CFLAGS) -o test.o -c test.c

clean:
	rm -f *.o *.out
