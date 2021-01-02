CC=g++
CFLAGS=-I
DEPS = edit.hpp find.h dist.h cmp.h

%.o: %.c $(DEPS)
	$(CC) -cpp -o $@ $< $(CFLAGS)

simple: main.o edit.o find.o dist.o cmp.o
	$(CC) -o main main.o edit.o find.o dist.o cmp.o
