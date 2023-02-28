CC= g++
CC_FLAGS= -Wall -g -std=c++11

BINS= digraph_test digraph_builder
OBJS= digraph.o digraph_test.o digraph_builder.o

# executable targets
all: digraph_test digraph_builder buildedmontongraph

digraph_builder: digraph_builder.o digraph.o
	$(CC) digraph_builder.o digraph.o -o digraph_builder

digraph_test: digraph_test.o digraph.o
	$(CC) digraph_test.o digraph.o -o digraph_test

# object targets
digraph_builder.o: digraph_builder.cpp digraph.h
	$(CC) -c digraph_builder.cpp $(CC_FLAGS)

digraph_test.o: digraph_test.cpp digraph.h
	$(CC) -c digraph_test.cpp $(CC_FLAGS)

digraph.o: digraph.cpp digraph.h
	$(CC) -c digraph.cpp $(CC_FLAGS)

clean:
	-rm -f $(OBJS) $(BINS)
