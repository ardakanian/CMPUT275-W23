# Defining some variables
CC = g++
CC_FLAGS = -g -Wall -std=c++11

BINARIES = typecheck interactive
OBJS = typecheck.o interactive.o

all: $(BINARIES)

typecheck: typecheck.o
	$(CC) -o typecheck typecheck.o

interactive: interactive.o
	$(CC) -o interactive interactive.o

%.o: %.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@

clean:
	@echo "cleaning..."
	-rm -f $(BINARIES) $(OBJS) *.out
