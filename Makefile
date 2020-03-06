CC = gcc
CFLAGS = -Wall -Werror -Wmissing-prototypes
TARGET = bc
OBJS = main.o stack.o operation.o bc.o utils.o

all: bc

bc: $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

stack.o: stack.c operation.h
	$(CC) $(CFLAGS) -c stack.c

operation.o: operation.c operation.h
	$(CC) $(CFLAGS) -c operation.c

bc.o: bc.c bc.h
	$(CC) $(CFLAGS) -c bc.c

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c

clean:
	rm -f *~ *.o bc

.PHONY: clean
