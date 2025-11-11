# DSA Library Makefile - Main Project Only
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
SOURCES = $(SRC_DIR)/queue.c $(SRC_DIR)/stack.c $(SRC_DIR)/linkedlist.c \
          $(SRC_DIR)/bst.c $(SRC_DIR)/graph.c $(SRC_DIR)/dsa.c \
          $(SRC_DIR)/searching.c $(SRC_DIR)/sorting.c

# Object files
OBJECTS = $(BUILD_DIR)/queue.o $(BUILD_DIR)/stack.o $(BUILD_DIR)/linkedlist.o \
          $(BUILD_DIR)/bst.o $(BUILD_DIR)/graph.o $(BUILD_DIR)/dsa.o \
          $(BUILD_DIR)/searching.o $(BUILD_DIR)/sorting.o

# Library
LIB = $(BUILD_DIR)/libdsa.a

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

# Build examples
examples: $(LIB)
	@cd $(EXAMPLE_DIR) && $(MAKE) all

# Run all examples
run_examples: examples
	@cd $(EXAMPLE_DIR) && $(MAKE) run

# Clean
clean:
	rm -rf $(BUILD_DIR)/*.o $(BUILD_DIR)/*.a
	rm -f main
	@cd $(EXAMPLE_DIR) && $(MAKE) clean 2>/dev/null || true

# Clean everything including build directory
distclean: clean
	rm -rf $(BUILD_DIR)

# Help
help:
	@echo "DSA Library - Available targets:"
	@echo "  make          - Build library and main program"
	@echo "  make examples - Build all examples"
	@echo "  make run_examples - Run all examples"
	@echo "  make clean    - Remove build artifacts"
	@echo "  make help     - Show this help message"

.PHONY: all examples run_examples clean distclean help