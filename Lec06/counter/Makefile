CC=g++
LFLAGS=
CFLAGS=-Wall -O2 -c
PROG=testcounter
OBJS=testcounter.o counter.o

$(PROG): $(OBJS)
	$(CC) $(OBJS) -o $(PROG) $(LFLAGS)

testcounter.o: testcounter.cpp counter.h
	$(CC) testcounter.cpp -o testcounter.o $(CFLAGS)

counter.o: counter.cpp counter.h
	$(CC) counter.cpp -o counter.o $(CFLAGS)

clean:
	@rm -f $(OBJS) $(PROG)
