CC = g++
C_FLAGS = -std=c++11 -Wall -g

ht: hashtest.cpp dynarray.h hash_table.h linked_list.h
	$(CC) $(C_FLAGS) hashtest.cpp -o ht

clean:
	-rm ht
	-rm *.o
