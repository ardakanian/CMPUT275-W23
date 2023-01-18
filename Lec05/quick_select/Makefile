CC = g++
CFLAGS = -std=c++11 -Wall -O2 # use C++ 11 and include all warnings when compiling
PROJECT = quick_select
OBJS = quick_select_test.o quick_select.o

$(PROJECT): $(OBJS)
	$(CC) $(OBJS) -o $(PROJECT) 

quick_select.o: quick_select.cpp quick_select.h
	$(CC) quick_select.cpp -o quick_select.o -c $(CFLAGS)

quick_select_test.o: quick_select_test.cpp quick_select.h
	$(CC) quick_select_test.cpp -o quick_select_test.o -c $(CFLAGS)

clean:
	@rm -f $(OBJS) $(PROJECT)