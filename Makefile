# DSA Library Makefile - Single Build File
CC = gcc
AR = ar
CFLAGS = -Wall -Iinclude
LDFLAGS = -Lbuild -ldsa

# Directories
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
EXAMPLE_DIR = examples

# Source files
SOURCES = $(SRC_DIR)/queue.c $(SRC_DIR)/circular_queue.c \
          $(SRC_DIR)/priority_queue.c $(SRC_DIR)/deque.c $(SRC_DIR)/stack.c \
          $(SRC_DIR)/singly_linked_list.c $(SRC_DIR)/doubly_linked_list.c $(SRC_DIR)/circular_linked_list.c \
          $(SRC_DIR)/bst.c $(SRC_DIR)/graph.c $(SRC_DIR)/dsa.c \
          $(SRC_DIR)/searching.c $(SRC_DIR)/sorting.c

# Object files
OBJECTS = $(BUILD_DIR)/queue.o $(BUILD_DIR)/circular_queue.o \
          $(BUILD_DIR)/priority_queue.o $(BUILD_DIR)/deque.o $(BUILD_DIR)/stack.o \
          $(BUILD_DIR)/singly_linked_list.o $(BUILD_DIR)/doubly_linked_list.o $(BUILD_DIR)/circular_linked_list.o \
          $(BUILD_DIR)/bst.o $(BUILD_DIR)/graph.o $(BUILD_DIR)/dsa.o \
          $(BUILD_DIR)/searching.o $(BUILD_DIR)/sorting.o

# Library
LIB = $(BUILD_DIR)/libdsa.a

# Example programs
EXAMPLES = $(EXAMPLE_DIR)/example_expression $(EXAMPLE_DIR)/example_scheduler \
           $(EXAMPLE_DIR)/example_social $(EXAMPLE_DIR)/example_students \
           $(EXAMPLE_DIR)/example_palindrome $(EXAMPLE_DIR)/example_topk \
           $(EXAMPLE_DIR)/example_undo

# Default target
all: $(LIB) main

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Build object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create static library
$(LIB): $(OBJECTS)
	$(AR) rcs $(LIB) $(OBJECTS)

# Build main program
main: main.c $(LIB)
	$(CC) $(CFLAGS) main.c $(LDFLAGS) -o main

# Build individual examples
$(EXAMPLE_DIR)/example_expression: $(EXAMPLE_DIR)/example_expression.c $(LIB)
	$(CC) $(CFLAGS) $(EXAMPLE_DIR)/example_expression.c $(LDFLAGS) -o $(EXAMPLE_DIR)/example_expression

$(EXAMPLE_DIR)/example_scheduler: $(EXAMPLE_DIR)/example_scheduler.c $(LIB)
	$(CC) $(CFLAGS) $(EXAMPLE_DIR)/example_scheduler.c $(LDFLAGS) -o $(EXAMPLE_DIR)/example_scheduler

$(EXAMPLE_DIR)/example_social: $(EXAMPLE_DIR)/example_social.c $(LIB)
	$(CC) $(CFLAGS) $(EXAMPLE_DIR)/example_social.c $(LDFLAGS) -o $(EXAMPLE_DIR)/example_social

$(EXAMPLE_DIR)/example_students: $(EXAMPLE_DIR)/example_students.c $(LIB)
	$(CC) $(CFLAGS) $(EXAMPLE_DIR)/example_students.c $(LDFLAGS) -o $(EXAMPLE_DIR)/example_students

$(EXAMPLE_DIR)/example_palindrome: $(EXAMPLE_DIR)/example_palindrome.c $(LIB)
	$(CC) $(CFLAGS) $(EXAMPLE_DIR)/example_palindrome.c $(LDFLAGS) -o $(EXAMPLE_DIR)/example_palindrome

$(EXAMPLE_DIR)/example_topk: $(EXAMPLE_DIR)/example_topk.c $(LIB)
	$(CC) $(CFLAGS) $(EXAMPLE_DIR)/example_topk.c $(LDFLAGS) -o $(EXAMPLE_DIR)/example_topk

$(EXAMPLE_DIR)/example_undo: $(EXAMPLE_DIR)/example_undo.c $(LIB)
	$(CC) $(CFLAGS) $(EXAMPLE_DIR)/example_undo.c $(LDFLAGS) -o $(EXAMPLE_DIR)/example_undo

# Build all examples
examples: $(EXAMPLES)

# Run all examples
run_examples: examples
	@echo "=== Running All Examples ==="
	@echo ""
	@./$(EXAMPLE_DIR)/example_expression
	@echo "\n========================================"
	@./$(EXAMPLE_DIR)/example_scheduler
	@echo "\n========================================"
	@./$(EXAMPLE_DIR)/example_social
	@echo "\n========================================"
	@./$(EXAMPLE_DIR)/example_students
	@echo "\n========================================"
	@./$(EXAMPLE_DIR)/example_palindrome
	@echo "\n========================================"
	@./$(EXAMPLE_DIR)/example_topk
	@echo "\n========================================"
	@./$(EXAMPLE_DIR)/example_undo

# Clean
clean:
	rm -rf $(BUILD_DIR)/*.o $(BUILD_DIR)/*.a
	rm -f main
	rm -f $(EXAMPLES)

# Clean everything including build directory
distclean: clean
	rm -rf $(BUILD_DIR)

# Help
help:
	@echo "DSA Library - Available targets:"
	@echo "  make              - Build library and main program"
	@echo "  make examples     - Build all examples"
	@echo "  make run_examples - Run all examples"
	@echo "  make clean        - Remove build artifacts"
	@echo "  make help         - Show this help message"
	@echo ""
	@echo "Individual example targets:"
	@echo "  make examples/example_expression"
	@echo "  make examples/example_scheduler"
	@echo "  make examples/example_social"
	@echo "  make examples/example_students"
	@echo "  make examples/example_palindrome"
	@echo "  make examples/example_topk"
	@echo "  make examples/example_undo"

.PHONY: all examples run_examples clean distclean help