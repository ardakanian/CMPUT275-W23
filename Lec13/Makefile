CC = g++
CC_FLAGS = -std=c++11 -Wall -g

OBJS = digraph.o reachability.o bfs.o dfs.o
BINS = reachability bfs dfs

all: dfs bfs reachability

dfs: dfs.o digraph.o
	$(CC) dfs.o digraph.o -o dfs

bfs: bfs.o digraph.o
	$(CC) bfs.o digraph.o -o bfs

reachability: reachability.o digraph.o
	$(CC) reachability.o digraph.o -o reachability

dfs.o: dfs.cpp digraph.h
	$(CC) $(CC_FLAGS) -c dfs.cpp

bfs.o: bfs.cpp digraph.h
	$(CC) $(CC_FLAGS) -c bfs.cpp

reachability.o: reachability.cpp digraph.h
	$(CC) $(CC_FLAGS) -c reachability.cpp

digraph.o: digraph.cpp digraph.h
	$(CC) $(CC_FLAGS) -c digraph.cpp

clean:
	-rm -f $(BINS) $(OBJS)