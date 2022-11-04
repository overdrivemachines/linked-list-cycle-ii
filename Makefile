
# Variables to control Makefile operation

CC = g++
CFLAGS = -Wall -g

linked-list-cycle-ii: linked-list-cycle-ii.o
	$(CC) $(CFLAGS) -o linked-list-cycle-ii linked-list-cycle-ii.o

linked-list-cycle-ii.o: linked-list-cycle-ii.cpp
	$(CC) $(CFLAGS) -c linked-list-cycle-ii.cpp

clean:
	rm -rf linked-list-cycle-ii linked-list-cycle-ii.o
