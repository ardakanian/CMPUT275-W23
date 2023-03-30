CC=g++
LFLAGS=
CFLAGS=-Wall -std=c++11 -g
PROG=testcounter
OBJS=testcounter.o counter.o

$(PROG): $(OBJS)
	$(CC) $(OBJS) -o $(PROG) $(LFLAGS)

testcounter.o: testcounter.cpp counter.h
	$(CC) -c testcounter.cpp -o testcounter.o $(CFLAGS)

counter.o: counter.cpp counter.h
	$(CC) -c counter.cpp -o counter.o $(CFLAGS)

clean:
	@rm -f $(OBJS) $(PROG)
