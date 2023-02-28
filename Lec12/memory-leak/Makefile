CC = g++
CC_FLAGS = -std=c++11 -Wall -g

BIN = leaks
OBJ = leaks.o

all: leaks memcheck

# to install valgrind, enter 
# "sudo apt install valgrind" in the terminal
memcheck: leaks
	valgrind --tool=memcheck --leak-check=full ./leaks

leaks: leaks.o
	$(CC) leaks.o -o leaks

leaks.o: leaks.cpp
	$(CC) $(CC_FLAGS) -c leaks.cpp

clean:
	-rm -f leaks.o leaks