CC=g++
CC_FLAGS=-c -Wall -std=c++11
BIN = account_manager
OBJS = account.o 

all: main.cpp account.o
	$(CC) main.cpp account.o -o account_manager

account.o: account.cpp account.h
	$(CC) $(CC_FLAGS) account.cpp

clean:
	-rm account.o account_manager
