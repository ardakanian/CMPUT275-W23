CC = g++
CC_FLAGS = -std=c++11 -Wall -g

all: r1 w1 r2 w2

r1: reader.cpp
	$(CC) $(CC_FLAGS) reader.cpp -o r1

w1: writer.cpp
	$(CC) $(CC_FLAGS) writer.cpp -o w1

r2: multiline_reader.cpp
	$(CC) $(CC_FLAGS) multiline_reader.cpp -o r2

w2: multiline_writer.cpp
	$(CC) $(CC_FLAGS) multiline_writer.cpp -o w2

reset:
	-rm -f pipe*

clean: reset
	-rm -f r1 w1 r2 w2
	-rm -f *.o
