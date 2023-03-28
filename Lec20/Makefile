CC = g++
CFLAGS = -std=c++11 -g -Wall

bsearch: bsearch.o
	$(CC) bsearch.o -o bsearch

bsearch.o: bsearch.cpp
	$(CC) -c bsearch.cpp $(CFLAGS)

clean:
	-rm -f bsearch.o bsearch
