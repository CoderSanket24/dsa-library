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

# DSA Problem programs
EXAMPLES = $(EXAMPLE_DIR)/problem1_level_order_tree \
           $(EXAMPLE_DIR)/problem2_sliding_window

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

# Build DSA problems
$(EXAMPLE_DIR)/problem1_level_order_tree: $(EXAMPLE_DIR)/problem1_level_order_tree.c $(LIB)
	$(CC) $(CFLAGS) $(EXAMPLE_DIR)/problem1_level_order_tree.c $(LDFLAGS) -o $(EXAMPLE_DIR)/problem1_level_order_tree

$(EXAMPLE_DIR)/problem2_sliding_window: $(EXAMPLE_DIR)/problem2_sliding_window.c $(LIB)
	$(CC) $(CFLAGS) $(EXAMPLE_DIR)/problem2_sliding_window.c $(LDFLAGS) -o $(EXAMPLE_DIR)/problem2_sliding_window

# Build all examples
examples: $(EXAMPLES)

# Run all problems
run_examples: examples
	@echo "=== Running DSA Problems ==="
	@echo ""
	@./$(EXAMPLE_DIR)/problem1_level_order_tree
	@echo "\n========================================"
	@./$(EXAMPLE_DIR)/problem2_sliding_window

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
	@echo "  make examples     - Build DSA problem solutions"
	@echo "  make run_examples - Run all DSA problems"
	@echo "  make clean        - Remove build artifacts"
	@echo "  make help         - Show this help message"
	@echo ""
	@echo "Individual problem targets:"
	@echo "  make examples/problem1_level_order_tree"
	@echo "  make examples/problem2_sliding_window"

.PHONY: all examples run_examples clean distclean help