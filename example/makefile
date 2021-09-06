CC = gcc
CFLAGS = -Wall
LDFLAGS = -lm

all: test.out

test.out: test.o
	$(CC) $(CFLAGS) -o test.out -libconfRead $(LDFLAGS)

test.o: test.c
	$(CC) $(CFLAGS) -test.o -c test.c

clean:
	rm -f *.o *.out
