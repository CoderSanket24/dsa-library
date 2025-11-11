/*
 * Problem 11: Valid Parentheses & Expression Evaluation
 * 
 * Use stack to solve various parentheses and expression problems:
 * 1. Check if parentheses are balanced
 * 2. Convert infix to postfix notation
 * 3. Evaluate postfix expressions
 * 4. Find longest valid parentheses substring
 * 
 * Uses: Stack Library Functions
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/stack.h"

// Helper function to check if character is opening bracket
int isOpenBracket(char c) {
    return c == '(' || c == '[' || c == '{';
}

// Helper function to check if character is closing bracket
int isCloseBracket(char c) {
    return c == ')' || c == ']' || c == '}';
}

// Helper function to check if brackets match
int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

// Check if all types of brackets are balanced
int isBalancedBrackets(const char* expr) {
    CharStack stack;
    charstack_init(&stack, 100);
    
    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];
        
        if (isOpenBracket(c)) {
            charstack_push(&stack, c);
        } else if (isCloseBracket(c)) {
            if (charstack_is_empty(&stack)) {
                charstack_free(&stack);
                return 0;
            }
            char top = charstack_pop(&stack);
            if (!isMatchingPair(top, c)) {
                charstack_free(&stack);
                return 0;
            }
        }
    }
    
    int result = charstack_is_empty(&stack);
    charstack_free(&stack);
    return result;
}

// Find longest valid parentheses substring length
int longestValidParentheses(const char* s) {
    IntStack stack;
    intstack_init(&stack, 100);
    intstack_push(&stack, -1);
    
    int maxLen = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            intstack_push(&stack, i);
        } else {
            intstack_pop(&stack);
            if (intstack_is_empty(&stack)) {
                intstack_push(&stack, i);
            } else {
                int len = i - intstack_peek(&stack);
                if (len > maxLen) maxLen = len;
            }
        }
    }
    
    intstack_free(&stack);
    return maxLen;
}

// Remove invalid parentheses (minimum removals)
int minRemoveToMakeValid(const char* s) {
    CharStack stack;
    charstack_init(&stack, 100);
    
    int invalidCount = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            charstack_push(&stack, '(');
        } else if (s[i] == ')') {
            if (!charstack_is_empty(&stack)) {
                charstack_pop(&stack);
            } else {
                invalidCount++; // unmatched closing
            }
        }
    }
    
    // Remaining in stack are unmatched opening
    invalidCount += stack.top + 1;
    
    charstack_free(&stack);
    return invalidCount;
}

// Test 1: Basic parentheses validation
void test_basic_validation() {
    printf("=== Test 1: Basic Parentheses Validation ===\n\n");
    
    const char* testCases[] = {
        "()",
        "()[]{}",
        "(]",
        "([)]",
        "{[]}",
        "((()))",
        "((())",
        "())",
        ""
    };
    
    int numTests = sizeof(testCases) / sizeof(testCases[0]);
    
    for (int i = 0; i < numTests; i++) {
        int result = isBalancedBrackets(testCases[i]);
        printf("  \"%s\" -> %s\n", 
               testCases[i], 
               result ? "Valid ✓" : "Invalid ✗");
    }
    printf("\n");
}

// Test 2: Expression conversion and evaluation
void test_expression_conversion() {
    printf("=== Test 2: Infix to Postfix Conversion ===\n\n");
    
    const char* expressions[] = {
        "A+B",
        "A+B*C",
        "(A+B)*C",
        "A+B*C-D",
        "A*(B+C)/D"
    };
    
    int numExpr = sizeof(expressions) / sizeof(expressions[0]);
    
    for (int i = 0; i < numExpr; i++) {
        char* postfix = infix_to_postfix(expressions[i]);
        printf("  Infix:   %s\n", expressions[i]);
        printf("  Postfix: %s\n\n", postfix);
        free(postfix);
    }
}

// Test 3: Postfix evaluation
void test_postfix_evaluation() {
    printf("=== Test 3: Postfix Expression Evaluation ===\n\n");
    
    const char* postfixExpressions[] = {
        "23+",           // 2 + 3 = 5
        "23*54*+",       // 2*3 + 5*4 = 26
        "234*+",         // 2 + 3*4 = 14
        "53+82-*",       // (5+3) * (8-2) = 48
        "62/35*+",       // 6/2 + 3*5 = 18
    };
    
    const char* infixEquiv[] = {
        "2 + 3",
        "2*3 + 5*4",
        "2 + 3*4",
        "(5+3) * (8-2)",
        "6/2 + 3*5"
    };
    
    int numExpr = sizeof(postfixExpressions) / sizeof(postfixExpressions[0]);
    
    for (int i = 0; i < numExpr; i++) {
        long result = evaluate_postfix(postfixExpressions[i]);
        printf("  Postfix: %s\n", postfixExpressions[i]);
        printf("  Infix:   %s\n", infixEquiv[i]);
        printf("  Result:  %ld\n\n", result);
    }
}

// Test 4: Longest valid parentheses
void test_longest_valid() {
    printf("=== Test 4: Longest Valid Parentheses Substring ===\n\n");
    
    const char* testCases[] = {
        "(()",
        ")()())",
        "",
        "()(())",
        "()(()",
        "(()())"
    };
    
    int numTests = sizeof(testCases) / sizeof(testCases[0]);
    
    for (int i = 0; i < numTests; i++) {
        int len = longestValidParentheses(testCases[i]);
        printf("  String: \"%s\"\n", testCases[i]);
        printf("  Longest valid length: %d\n\n", len);
    }
}

// Test 5: Minimum removals to make valid
void test_min_removals() {
    printf("=== Test 5: Minimum Removals to Make Valid ===\n\n");
    
    const char* testCases[] = {
        "())",
        "(((",
        "()()())",
        "a)b(c)d",
        "))((",
        "(a(b(c)d)"
    };
    
    int numTests = sizeof(testCases) / sizeof(testCases[0]);
    
    for (int i = 0; i < numTests; i++) {
        int removals = minRemoveToMakeValid(testCases[i]);
        printf("  String: \"%s\"\n", testCases[i]);
        printf("  Minimum removals: %d\n\n", removals);
    }
}

// Test 6: Real-world application - Code validator
void test_code_validator() {
    printf("=== Test 6: Code Syntax Validator ===\n\n");
    
    const char* codeSnippets[] = {
        "if (x > 0) { return x; }",
        "array[index]",
        "func(a, b, c)",
        "if (x > 0 { return x; }",  // missing )
        "array[index]]",              // extra ]
        "{[()]}",
        "{[(])}"                      // mismatched
    };
    
    int numSnippets = sizeof(codeSnippets) / sizeof(codeSnippets[0]);
    
    printf("Checking code syntax (brackets only):\n\n");
    
    for (int i = 0; i < numSnippets; i++) {
        int valid = isBalancedBrackets(codeSnippets[i]);
        printf("  Code: %s\n", codeSnippets[i]);
        printf("  Status: %s\n\n", 
               valid ? "✓ Valid brackets" : "✗ Invalid brackets");
    }
}

int main() {
    printf("========================================\n");
    printf("  VALID PARENTHESES & EXPRESSIONS\n");
    printf("========================================\n\n");
    
    test_basic_validation();
    printf("========================================\n\n");
    
    test_expression_conversion();
    printf("========================================\n\n");
    
    test_postfix_evaluation();
    printf("========================================\n\n");
    
    test_longest_valid();
    printf("========================================\n\n");
    
    test_min_removals();
    printf("========================================\n\n");
    
    test_code_validator();
    printf("========================================\n");
    
    printf("\n✓ All stack-based problems demonstrated!\n");
    printf("\nStack Applications:\n");
    printf("  - Parentheses validation\n");
    printf("  - Expression conversion (infix to postfix)\n");
    printf("  - Expression evaluation\n");
    printf("  - Longest valid substring\n");
    printf("  - Code syntax validation\n");
    
    return 0;
}
