# Compiler
CC = gcc
AR = ar
CFLAGS = -Wall -c
OBJS = queue.o stack.o linkedlist.o bst.o graph.o dsa.o
LIB = libdsa.a

# Default target
all: $(LIB) myprogram

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

# Create static library
$(LIB): $(OBJS)
	$(AR) rcs $(LIB) $(OBJS)

# Link and build main program
myprogram: main.c $(LIB)
	$(CC) main.c -L. -ldsa -o myprogram

# Clean command
clean:
	rm -f *.o *.a myprogram

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
