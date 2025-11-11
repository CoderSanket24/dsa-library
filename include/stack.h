#define STACK_H

#include <stddef.h>

/* Integer stack (dynamic array) */
typedef struct {
    int *arr;
    int top;
    int capacity;
} IntStack;

/* Char stack (for expression conversions/parsing) */
typedef struct {
    char *arr;
    int top;
    int capacity;
} CharStack;

/* IntStack functions */
void intstack_init(IntStack *s, int capacity);
int intstack_is_empty(const IntStack *s);
int intstack_is_full(const IntStack *s);
void intstack_resize(IntStack *s);
void intstack_push(IntStack *s, int value);
int intstack_pop(IntStack *s);
int intstack_peek(const IntStack *s);
int intstack_size(const IntStack *s);
void intstack_clear(IntStack *s);
void intstack_free(IntStack *s);
int intstack_bottom(const IntStack *s);
int intstack_search(const IntStack *s, int value); /* returns position from top (1-based) or -1 */
int intstack_sum(const IntStack *s);

/* CharStack functions */
void charstack_init(CharStack *s, int capacity);
int charstack_is_empty(const CharStack *s);
void charstack_push(CharStack *s, char c);
char charstack_pop(CharStack *s);
char charstack_peek(const CharStack *s);
void charstack_free(CharStack *s);

/* Expression / stack utilities */
int is_balanced_parentheses(const char *expr);
char *infix_to_postfix(const char *infix);   /* returns malloc'd string (caller must free) */
char *infix_to_prefix(const char *infix);    /* returns malloc'd string */
long evaluate_postfix(const char *postfix);  /* evaluate numeric postfix (integers & single-token numbers) */
int precedence(char op);
int is_operator(char c);