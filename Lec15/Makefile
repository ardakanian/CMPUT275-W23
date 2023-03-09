CC = g++
CC_FLAGS = -g -Wall -std=c++11
OBJS = heap_test.o pqueue_test.o
BINS = heap_test pqueue_test

all: heap_test pqueue_test

heap_test: heap_test.o
	$(CC) heap_test.o -o heap_test

heap_test.o: heap_test.cpp heap.h
	$(CC) $(CC_FLAGS) -c heap_test.cpp

pqueue_test: pqueue_test.o
	$(CC) pqueue_test.o -o pqueue_test

pqueue_test.o: pqueue_test.cpp
	$(CC) $(CC_FLAGS) -c pqueue_test.cpp

clean:
	-rm -f $(BINS) $(OBJS)
