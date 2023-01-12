# remember to include -g if you want to use gdb
CC = g++
CC_FLAGS = -std=c++11 -Wall -g

BINS = buggy array-test pointer-test reverse fib
OBJS = buggy.o array-test.o pointer-test.o reverse.o fib.o

all: $(BINS)

fib: fib.o
	$(CC) fib.o -o fib

buggy: buggy.o
	$(CC) buggy.o -o buggy

reverse: reverse.o
	$(CC) reverse.o -o reverse

array-test: array-test.o
	$(CC) array-test.o -o array-test

pointer-test: pointer-test.o
	$(CC) pointer-test.o -o pointer-test

fib.o: fib.cpp
	$(CC) $(CC_FLAGS) -c fib.cpp

buggy.o: buggy.cpp
	$(CC) $(CC_FLAGS) -c buggy.cpp

reverse.o: reverse.cpp
	$(CC) $(CC_FLAGS) -c reverse.cpp

array-test.o: array-test.cpp
	$(CC) $(CC_FLAGS) -c array-test.cpp

pointer-test.o: pointer-test.cpp
	$(CC) $(CC_FLAGS) -c pointer-test.cpp

clean:
	-rm -f $(BINS) $(OBJS)

push: clean
	git add .
	git commit -m "code for lecture3"
	git push
