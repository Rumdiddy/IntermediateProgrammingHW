#Samuel Jin
#sjin16

#Some variable definitions to save typing later on
CC = g++
CONSERVATIVE_FLAGS = -std=c++11 -Wall -Wextra -pedantic
DEBUGGING_FLAGS = -g -O0
CFLAGS = $(CONSERVATIVE_FLAGS) $(DEBUGGING_FLAGS)

# 'make all' will compile all programs
all: CTreeTest TTreeTest

# Creates the CTreeTest executable
CTreeTest: CTreeTest.o CTree.o
	$(CC) CTreeTest.o CTree.o -o CTreeTest

# Creates the TTreeTest executable
TTreeTest: TTreeTest.o CTree.o
	$(CC) TTreeTest.o CTree.o -o TTreeTest

# Compiles CTreeTest.cpp into an object file
CTreeTest.o: CTreeTest.cpp CTree.h
	$(CC) $(CFLAGS) -c CTreeTest.cpp

# Compiles TTreeTest.cpp into an object file
TTreeTest.o: TTreeTest.cpp CTree.h
	$(CC) $(CFLAGS) -c TTreeTest.cpp

# Compiles CTree.cpp into an object file
CTree.o: CTree.cpp CTree.h
	$(CC) $(CFLAGS) -c CTree.cpp

# 'make clean' will remove intermediate & executable files
clean:
	rm -f *.o CTreeTest TTreeTest
