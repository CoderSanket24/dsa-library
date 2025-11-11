# Examples Makefile
CC = gcc
CFLAGS = -Wall
LIB_PATH = ../build
INC_PATH = ../include
LIB = $(LIB_PATH)/libdsa.a
CFLAGS = -Wall -I$(INC_PATH)

# All example programs
EXAMPLES = example_expression example_scheduler example_social \
           example_students example_palindrome example_topk example_undo

# Default target - build all examples
all: $(EXAMPLES)

# Build individual examples
example_expression: example_expression.c $(LIB)
	$(CC) example_expression.c $(CFLAGS) -L$(LIB_PATH) -ldsa -o example_expression

example_scheduler: example_scheduler.c $(LIB)
	$(CC) example_scheduler.c $(CFLAGS) -L$(LIB_PATH) -ldsa -o example_scheduler

example_social: example_social.c $(LIB)
	$(CC) example_social.c $(CFLAGS) -L$(LIB_PATH) -ldsa -o example_social

example_students: example_students.c $(LIB)
	$(CC) example_students.c $(CFLAGS) -L$(LIB_PATH) -ldsa -o example_students

example_palindrome: example_palindrome.c $(LIB)
	$(CC) example_palindrome.c $(CFLAGS) -L$(LIB_PATH) -ldsa -o example_palindrome

example_topk: example_topk.c $(LIB)
	$(CC) example_topk.c $(CFLAGS) -L$(LIB_PATH) -ldsa -o example_topk

example_undo: example_undo.c $(LIB)
	$(CC) example_undo.c $(CFLAGS) -L$(LIB_PATH) -ldsa -o example_undo

# Run all examples
run: all
	@echo "=== Running All Examples ==="
	@echo ""
	@./example_expression
	@echo "\n========================================\n"
	@./example_scheduler
	@echo "\n========================================\n"
	@./example_social
	@echo "\n========================================\n"
	@./example_students
	@echo "\n========================================\n"
	@./example_palindrome
	@echo "\n========================================\n"
	@./example_topk
	@echo "\n========================================\n"
	@./example_undo

# Clean
clean:
	rm -f $(EXAMPLES)

.PHONY: all run clean