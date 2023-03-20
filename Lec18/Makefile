CC = g++
CC_FLAGS = -std=c++11 -Wall -g

BINS = shp rhp

all: reset shp rhp

reset:
	-rm -f sharedch

shp: sender-hp.cpp
	$(CC) $(CC_FLAGS) sender-hp.cpp -o shp

rhp: receiver-hp.cpp
	$(CC) $(CC_FLAGS) receiver-hp.cpp -o rhp

clean: reset
	-rm $(BINS)
