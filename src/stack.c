#define _POSIX_C_SOURCE 200809L
#define _DEFAULT_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"


void intstack_init(IntStack *s, int capacity) {
    if (capacity < 1) capacity = 4;
    s->arr = (int*)malloc(capacity * sizeof(int));
    s->top = -1;
    s->capacity = capacity;
}

int intstack_is_empty(const IntStack *s) {
    return s->top == -1;
}

int intstack_is_full(const IntStack *s) {
    return s->top == s->capacity - 1;
}

void intstack_resize(IntStack *s) {
    int newcap = s->capacity * 2;
    if (newcap < 1) newcap = 4;
    int *tmp = (int*)realloc(s->arr, newcap * sizeof(int));
    if (!tmp) {
        fprintf(stderr, "intstack_resize: realloc failed\n");
        return;
    }
    s->arr = tmp;
    s->capacity = newcap;
}

void intstack_push(IntStack *s, int value) {
    if (intstack_is_full(s)) intstack_resize(s);
    s->arr[++(s->top)] = value;
}

int intstack_pop(IntStack *s) {
    if (intstack_is_empty(s)) {
        fprintf(stderr, "intstack_pop: underflow\n");
        return 0;
    }
    return s->arr[(s->top)--];
}

int intstack_peek(const IntStack *s) {
    if (intstack_is_empty(s)) {
        fprintf(stderr, "intstack_peek: empty\n");
        return 0;
    }
    return s->arr[s->top];
}

int intstack_size(const IntStack *s) {
    return s->top + 1;
}

void intstack_clear(IntStack *s) {
    s->top = -1;
}

void intstack_free(IntStack *s) {
    if (s->arr) free(s->arr);
    s->arr = NULL;
    s->top = -1;
    s->capacity = 0;
}

int intstack_bottom(const IntStack *s) {
    if (intstack_is_empty(s)) {
        fprintf(stderr, "intstack_bottom: empty\n");
        return 0;
    }
    return s->arr[0];
}

int intstack_search(const IntStack *s, int value) {
    for (int i = s->top; i >= 0; i--) {
        if (s->arr[i] == value) {
            return s->top - i + 1; 
        }
    }
    return -1;
}

int intstack_sum(const IntStack *s) {
    int sum = 0;
    for (int i = 0; i <= s->top; i++) sum += s->arr[i];
    return sum;
}


void charstack_init(CharStack *s, int capacity) {
    if (capacity < 1) capacity = 8;
    s->arr = (char*)malloc(capacity * sizeof(char));
    s->top = -1;
    s->capacity = capacity;
}

int charstack_is_empty(const CharStack *s) {
    return s->top == -1;
}

void charstack_push(CharStack *s, char c) {
    if (s->top == s->capacity - 1) {
        int newcap = s->capacity * 2;
        char *tmp = (char*)realloc(s->arr, newcap);
        if (!tmp) {
            fprintf(stderr, "charstack_push: realloc failed\n");
            return;
        }
        s->arr = tmp;
        s->capacity = newcap;
    }
    s->arr[++(s->top)] = c;
}

char charstack_pop(CharStack *s) {
    if (charstack_is_empty(s)) {
        return '\0';
    }
    return s->arr[(s->top)--];
}

char charstack_peek(const CharStack *s) {
    if (charstack_is_empty(s)) return '\0';
    return s->arr[s->top];
}

void charstack_free(CharStack *s) {
    if (s->arr) free(s->arr);
    s->arr = NULL;
    s->top = -1;
    s->capacity = 0;
}


int precedence(char op) {
    switch (op) {
        case '+': case '-': return 1;
        case '*': case '/': case '%': return 2;
        case '^': return 3;
    }
    return 0;
}

int is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%';
}

int is_balanced_parentheses(const char *expr) {
    CharStack s;
    charstack_init(&s, 16);
    for (size_t i = 0; expr && expr[i]; i++) {
        char c = expr[i];
        if (c == '(' || c == '{' || c == '[') charstack_push(&s, c);
        else if (c == ')' || c == '}' || c == ']') {
            if (charstack_is_empty(&s)) { charstack_free(&s); return 0; }
            char top = charstack_pop(&s);
            if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) {
                charstack_free(&s);
                return 0;
            }
        }
    }
    int empty = charstack_is_empty(&s);
    charstack_free(&s);
    return empty;
}

char *infix_to_postfix(const char *infix) {
    if (!infix) return NULL;
    int n = strlen(infix);
    char *postfix = (char*)malloc(n + 1);
    if (!postfix) return NULL;

    CharStack s;
    charstack_init(&s, 16);
    int i = 0, j = 0;
    char c;

    while ((c = infix[i++]) != '\0') {
        if (isalnum((unsigned char)c)) {
            // Operand: directly goes to output
            postfix[j++] = c;
        } else if (c == '(') {
            charstack_push(&s, c);
        } else if (c == ')') {
            // Pop until '('
            while (!charstack_is_empty(&s) && charstack_peek(&s) != '(') {
                postfix[j++] = charstack_pop(&s);
            }
            if (!charstack_is_empty(&s) && charstack_peek(&s) == '(') {
                charstack_pop(&s); // Remove '('
            }
        } else if (is_operator(c)) {
            // Pop operators with higher or equal precedence (left-associative)
            while (!charstack_is_empty(&s) && precedence(charstack_peek(&s)) >= precedence(c)) {
                postfix[j++] = charstack_pop(&s);
            }
            charstack_push(&s, c);
        }
    }

    // Pop remaining operators
    while (!charstack_is_empty(&s)) {
        postfix[j++] = charstack_pop(&s);
    }

    postfix[j] = '\0'; // End of string
    charstack_free(&s);
    return postfix;
}

long evaluate_postfix(const char *postfix) {
    if (!postfix) return 0;
    IntStack s;
    intstack_init(&s, 16);
    int i = 0;
    char c;
    int val1, val2, res;

    while ((c = postfix[i++]) != '\0') {
        if (isdigit((unsigned char)c)) {
            // Operand: convert char to int and push
            intstack_push(&s, c - '0');
        } else if (is_operator(c)) {
            // Operator: pop two operands, apply operator, push result
            if (intstack_size(&s) < 2) {
                fprintf(stderr, "evaluate_postfix: insufficient operands\n");
                intstack_free(&s);
                return 0;
            }
            val2 = intstack_pop(&s);
            val1 = intstack_pop(&s);
            switch (c) {
                case '+': res = val1 + val2; break;
                case '-': res = val1 - val2; break;
                case '*': res = val1 * val2; break;
                case '/': res = (val2 != 0) ? (val1 / val2) : 0; break;
                case '%': res = (val2 != 0) ? (val1 % val2) : 0; break;
                case '^': {
                    // integer power: val1 ^ val2
                    long p = 1;
                    for (int j = 0; j < val2; j++) p *= val1;
                    res = (int)p;
                    break;
                }
                default: res = 0; break;
            }
            intstack_push(&s, res);
        }
    }

    int result = intstack_is_empty(&s) ? 0 : intstack_pop(&s);
    intstack_free(&s);
    return (long)result;
}

/* Infix to prefix (by reversing + swapping parens + using postfix conversion) */
static void str_reverse_inplace(char *s) {
    size_t i = 0, j = strlen(s);
    if (j==0) return;
    j--;
    while (i < j) {
        char t = s[i]; s[i] = s[j]; s[j] = t;
        ++i; --j;
    }
}

char *infix_to_prefix(const char *infix) {
    if (!infix) return NULL;
    
    // Step 1: Make a copy of infix string
    size_t len = strlen(infix);
    char *rev = (char*)malloc(len + 1);
    if (!rev) return NULL;
    strcpy(rev, infix);
    
    // Step 2: Reverse the copy
    str_reverse_inplace(rev);
    
    // Step 3: Swap parentheses ( with ) and ) with (
    for (size_t i = 0; rev[i]; ++i) {
        if (rev[i] == '(') rev[i] = ')';
        else if (rev[i] == ')') rev[i] = '(';
    }
    
    // Step 4: Convert to postfix
    char *post = infix_to_postfix(rev);
    free(rev);
    
    if (!post) return NULL;
    
    // Step 5: Reverse the postfix to get prefix
    str_reverse_inplace(post);
    
    return post;  // Caller must free this
}