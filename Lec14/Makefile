CC= g++
CFLAGS= -Wall -g -std=c++11
PROGS= digraph_test dijkstra
OBJS= digraph.o digraph_test.o dijkstra.o

# executable targets
all: digraph_test dijkstra

dijkstra: dijkstra.o digraph.o
	$(CC) dijkstra.o digraph.o -o dijkstra

digraph_test: digraph_test.o digraph.o
	$(CC) digraph_test.o digraph.o -o digraph_test

# object targets
dijkstra.o: dijkstra.cpp digraph.h wdigraph.h
	$(CC) -c dijkstra.cpp -o dijkstra.o $(CFLAGS)

digraph_test.o: digraph_test.cpp digraph.h wdigraph.h
	$(CC) -c digraph_test.cpp -o digraph_test.o $(CFLAGS)

digraph.o: digraph.cpp digraph.h
	$(CC) -c digraph.cpp -o digraph.o $(CFLAGS)

clean:
	-rm -f $(OBJS) $(PROGS)
