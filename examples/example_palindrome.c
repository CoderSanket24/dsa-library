/*
 * PROBLEM: Palindrome Checker
 * 
 * Real-world application: Data validation, text processing, DNA sequence analysis
 * 
 * This program uses a STACK to check if a string is a palindrome.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"

int isPalindrome(const char* str) {
    Stack s;
    initStack(&s);
    
    int len = strlen(str);
    
    // Push first half onto stack
    for (int i = 0; i < len / 2; i++) {
        push(&s, tolower(str[i]));
    }
    
    // Start comparing from middle
    int start = (len % 2 == 0) ? len / 2 : len / 2 + 1;
    
    for (int i = start; i < len; i++) {
        int ch;
        if (!pop(&s, &ch)) return 0;
        if (ch != tolower(str[i])) return 0;
    }
    
    return isEmpty_stack(&s);
}

void checkPalindrome(const char* str) {
    printf("String: \"%s\"\n", str);
    if (isPalindrome(str)) {
        printf("✓ This is a PALINDROME!\n");
    } else {
        printf("✗ This is NOT a palindrome.\n");
    }
    printf("\n");
}

int main() {
    printf("=== PALINDROME CHECKER ===\n");
    printf("Real-world use: Data validation, text processing, DNA analysis\n\n");
    
    printf("--- Testing Various Strings ---\n\n");
    
    checkPalindrome("racecar");
    checkPalindrome("hello");
    checkPalindrome("madam");
    checkPalindrome("noon");
    checkPalindrome("world");
    checkPalindrome("level");
    checkPalindrome("abcba");
    checkPalindrome("abccba");
    checkPalindrome("programming");
    
    printf("--- DNA Sequence Analysis ---\n");
    printf("(Checking if DNA sequences are palindromic)\n\n");
    
    checkPalindrome("GAATTC");  // EcoRI restriction site (palindromic)
    checkPalindrome("AAGCTT");  // HindIII restriction site (palindromic)
    checkPalindrome("ATCGAT");  // Not palindromic
    
    printf("✓ Stack enables efficient palindrome checking!\n");
    printf("  Time Complexity: O(n), Space Complexity: O(n/2)\n");
    
    return 0;
}