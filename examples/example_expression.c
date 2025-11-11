/*
 * PROBLEM: Expression Evaluation
 * 
 * Real-world application: Calculator apps, compilers, formula evaluation
 * 
 * This program uses a STACK to evaluate postfix (Reverse Polish Notation) expressions.
 * Example: "5 3 + 2 *" = (5 + 3) * 2 = 16
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"

int evaluatePostfix(char* expression) {
    Stack s;
    initStack(&s);
    
    char* token = strtok(expression, " ");
    
    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            // It's a number, push to stack
            push(&s, atoi(token));
        } else {
            // It's an operator, pop two operands
            int operand2, operand1;
            if (!pop(&s, &operand2) || !pop(&s, &operand1)) {
                printf("Error: Invalid expression\n");
                return 0;
            }
            
            int result;
            switch (token[0]) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': 
                    if (operand2 == 0) {
                        printf("Error: Division by zero\n");
                        return 0;
                    }
                    result = operand1 / operand2; 
                    break;
                default:
                    printf("Error: Unknown operator %s\n", token);
                    return 0;
            }
            push(&s, result);
        }
        token = strtok(NULL, " ");
    }
    
    int finalResult;
    if (!pop(&s, &finalResult)) {
        printf("Error: Invalid expression\n");
        return 0;
    }
    
    if (!isEmpty_stack(&s)) {
        printf("Error: Invalid expression (extra operands)\n");
        return 0;
    }
    
    return finalResult;
}

int main() {
    printf("=== EXPRESSION EVALUATOR ===\n");
    printf("Real-world use: Calculator apps, compilers, spreadsheet formulas\n\n");
    
    // Test cases
    char expr1[] = "5 3 + 2 *";
    char expr2[] = "10 5 - 3 *";
    char expr3[] = "15 7 1 1 + - / 3 * 2 1 1 + + -";
    char expr4[] = "100 50 + 2 /";
    
    printf("Expression: %s\n", expr1);
    printf("Result: %d\n", evaluatePostfix(expr1));
    printf("Explanation: (5 + 3) * 2 = 16\n\n");
    
    printf("Expression: %s\n", expr2);
    printf("Result: %d\n", evaluatePostfix(expr2));
    printf("Explanation: (10 - 5) * 3 = 15\n\n");
    
    printf("Expression: %s\n", expr3);
    printf("Result: %d\n", evaluatePostfix(expr3));
    printf("Explanation: Complex nested operations\n\n");
    
    printf("Expression: %s\n", expr4);
    printf("Result: %d\n", evaluatePostfix(expr4));
    printf("Explanation: (100 + 50) / 2 = 75\n\n");
    
    printf("✓ Stack data structure enables efficient expression evaluation!\n");
    return 0;
}