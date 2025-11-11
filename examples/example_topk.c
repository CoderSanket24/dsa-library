/*
 * PROBLEM: Find Top K Elements
 * 
 * Real-world application: Leaderboards, trending topics, top products
 * 
 * This program uses SORTING to find top K highest/lowest elements.
 */

#include <stdio.h>
#include <string.h>
#include "sorting.h"

typedef struct {
    char name[30];
    int score;
} Player;

Player players[100];

void findTopK(int scores[], int n, int k, const char* title) {
    printf("\n--- %s ---\n", title);
    
    // Create a copy to sort
    int sorted[100];
    for (int i = 0; i < n; i++) {
        sorted[i] = scores[i];
    }
    
    // Sort in descending order using quickSort
    quickSort(sorted, 0, n - 1);
    
    // Reverse for descending order
    for (int i = 0; i < n / 2; i++) {
        int temp = sorted[i];
        sorted[i] = sorted[n - 1 - i];
        sorted[n - 1 - i] = temp;
    }
    
    printf("Top %d scores: ", k);
    for (int i = 0; i < k && i < n; i++) {
        printf("%d", sorted[i]);
        if (i < k - 1 && i < n - 1) printf(", ");
    }
    printf("\n");
}

void findTopKPlayers(Player players[], int n, int k) {
    printf("\n--- Top %d Players ---\n", k);
    
    // Create arrays for sorting
    int scores[100];
    int indices[100];
    
    for (int i = 0; i < n; i++) {
        scores[i] = players[i].score;
        indices[i] = i;
    }
    
    // Bubble sort with index tracking (descending)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (scores[j] < scores[j + 1]) {
                // Swap scores
                int temp = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = temp;
                
                // Swap indices
                temp = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = temp;
            }
        }
    }
    
    printf("Rank | Player Name       | Score\n");
    printf("-----|-------------------|-------\n");
    for (int i = 0; i < k && i < n; i++) {
        printf("%-4d | %-17s | %d\n", 
               i + 1, 
               players[indices[i]].name, 
               players[indices[i]].score);
    }
}

int main() {
    printf("=== TOP K ELEMENTS FINDER ===\n");
    printf("Real-world use: Leaderboards, trending topics, recommendations\n\n");
    
    // Example 1: Simple scores
    int scores[] = {85, 92, 78, 95, 88, 91, 76, 89, 94, 87};
    int n = sizeof(scores) / sizeof(scores[0]);
    
    printf("All scores: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", scores[i]);
    }
    printf("\n");
    
    findTopK(scores, n, 3, "Top 3 Scores");
    findTopK(scores, n, 5, "Top 5 Scores");
    
    // Example 2: Gaming leaderboard
    printf("\n\n=== GAMING LEADERBOARD ===\n");
    
    strcpy(players[0].name, "DragonSlayer"); players[0].score = 15420;
    strcpy(players[1].name, "NinjaWarrior"); players[1].score = 18750;
    strcpy(players[2].name, "MysticMage"); players[2].score = 12300;
    strcpy(players[3].name, "ShadowHunter"); players[3].score = 19200;
    strcpy(players[4].name, "ThunderBolt"); players[4].score = 16800;
    strcpy(players[5].name, "IceQueen"); players[5].score = 14500;
    strcpy(players[6].name, "FireStorm"); players[6].score = 17600;
    strcpy(players[7].name, "StealthKnight"); players[7].score = 13900;
    
    findTopKPlayers(players, 8, 3);
    
    // Example 3: E-commerce top products
    printf("\n\n=== TOP SELLING PRODUCTS ===\n");
    int sales[] = {450, 890, 320, 1200, 670, 980, 540, 1100, 760, 850};
    int numProducts = sizeof(sales) / sizeof(sales[0]);
    
    printf("Product sales: ");
    for (int i = 0; i < numProducts; i++) {
        printf("%d ", sales[i]);
    }
    printf("\n");
    
    findTopK(sales, numProducts, 3, "Top 3 Best Sellers");
    
    printf("\n✓ Sorting algorithms enable efficient Top-K finding!\n");
    printf("  Time Complexity: O(n log n) for sorting-based approach\n");
    
    return 0;
}