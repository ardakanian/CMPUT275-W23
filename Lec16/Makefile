CC = g++
LFLAGS =
CFLAGS = -std=c++11 -Wall -g
OBJS = bstmaptest.o
BINS = bstmaptest

bstmaptest: bstmaptest.o
	$(CC) bstmaptest.o -o bstmaptest $(LFLAGS)

bstmaptest.o: bstmaptest.cpp bstmap.h bstaux.h
	$(CC) -c bstmaptest.cpp -o bstmaptest.o $(CFLAGS)

clean:
	-rm -f $(OBJS) $(BINS)
