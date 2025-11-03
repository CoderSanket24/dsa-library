# Compiler
CC = gcc
AR = ar
CFLAGS = -Wall -c
OBJS = queue.o stack.o linkedlist.o bst.o graph.o dsa.o searching.o sorting.o
LIB = libdsa.a

# Default target
all: $(LIB) main

# Build object files
queue.o: queue.c queue.h
	$(CC) $(CFLAGS) queue.c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) stack.c

linkedlist.o: linkedlist.c linkedlist.h
	$(CC) $(CFLAGS) linkedlist.c

bst.o: bst.c bst.h
	$(CC) $(CFLAGS) bst.c

graph.o: graph.c graph.h
	$(CC) $(CFLAGS) graph.c

dsa.o: dsa.c dsa.h
	$(CC) $(CFLAGS) dsa.c

searching.o: searching.c searching.h
	$(CC) $(CFLAGS) searching.c

sorting.o: sorting.c sorting.h
	$(CC) $(CFLAGS) sorting.c

# Create static library
$(LIB): $(OBJS)
	$(AR) rcs $(LIB) $(OBJS)

# Link and build main program
main: main.c $(LIB)
	$(CC) main.c -L. -ldsa -o main

# Clean command
clean:
	rm -f *.o *.a main

# Individual test programs
test_queue: test_queue.c $(LIB)
	$(CC) test_queue.c -L. -ldsa -o test_queue

test_stack: test_stack.c $(LIB)
	$(CC) test_stack.c -L. -ldsa -o test_stack

test_list: test_list.c $(LIB)
	$(CC) test_list.c -L. -ldsa -o test_list

test_bst: test_bst.c $(LIB)
	$(CC) test_bst.c -L. -ldsa -o test_bst

test_graph: test_graph.c $(LIB)
	$(CC) test_graph.c -L. -ldsa -o test_graph

test_searching: test_searching.c $(LIB)
	$(CC) test_searching.c -L. -ldsa -o test_searching

test_sorting: test_sorting.c $(LIB)
	$(CC) test_sorting.c -L. -ldsa -o test_sorting

test_algorithms: test_algorithms.c $(LIB)
	$(CC) test_algorithms.c -L. -ldsa -o test_algorithms
