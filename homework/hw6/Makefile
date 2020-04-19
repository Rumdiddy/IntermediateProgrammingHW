#Samuel Jin
#sjin16

#Some variable definitions to save typing later on
CC = g++
CONSERVATIVE_FLAGS = -std=c++11 -Wall -Wextra -pedantic
DEBUGGING_FLAGS = -g -O0
CFLAGS = $(CONSERVATIVE_FLAGS) $(DEBUGGING_FAGS)

# Creates the CTreeTest executable
cTreeTest: CTreeTest.o CTree.o
	$(CC) CTreeTest.o CTree.o -o cTreeTest -ggdb

# Compiles CTreeTest.cpp into an object file
CTreeTest.o: CTreeTest.cpp CTree.h
	$(CC) $(CFLAGS) -c CTreeTest.cpp -ggdb

# Compiles CTree.cpp into an object file
CTree.o: CTree.cpp CTree.h
	$(CC) $(CFLAGS) -c CTree.cpp -ggdb

# Creates the TTreeTest executable
tTreeTest: TTreeTest.o
	$(CC) TTreeTest.o -o tTreeTest -ggdb

TTreeTest.o: TTreeTest.cpp Tree.h Tree.inc
	$(CC) $(CFLAGS) -c TTreeTest.cpp -ggdb

# 'make clean' will remove intermediate & executable files
clean:
	rm -f *.o cTreeTest tTreeTest
