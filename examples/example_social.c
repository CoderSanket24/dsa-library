/*
 * PROBLEM: Social Network Connections
 * 
 * Real-world application: Facebook, LinkedIn, Twitter friend/follower systems
 * 
 * This program uses a GRAPH to represent social network connections.
 */

#include <stdio.h>
#include <string.h>
#include "graph.h"

typedef struct {
    int id;
    char name[30];
} User;

User users[10];

void initUsers() {
    strcpy(users[0].name, "Alice");
    strcpy(users[1].name, "Bob");
    strcpy(users[2].name, "Charlie");
    strcpy(users[3].name, "Diana");
    strcpy(users[4].name, "Eve");
    
    for (int i = 0; i < 5; i++) {
        users[i].id = i;
    }
}

void addFriendship(struct Graph* network, int user1, int user2) {
    addEdge(network, user1, user2);
    addEdge(network, user2, user1); // Bidirectional friendship
    printf("✓ %s and %s are now friends!\n", users[user1].name, users[user2].name);
}

void showNetwork(struct Graph* network) {
    printf("\n--- Social Network Connections ---\n");
    for (int i = 0; i < network->V; i++) {
        printf("%s's friends: ", users[i].name);
        struct Node* temp = network->array[i].head;
        if (temp == NULL) {
            printf("(no friends yet)");
        }
        while (temp) {
            printf("%s", users[temp->dest].name);
            if (temp->next) printf(", ");
            temp = temp->next;
        }
        printf("\n");
    }
}

int countFriends(struct Graph* network, int userId) {
    int count = 0;
    struct Node* temp = network->array[userId].head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

void findMutualFriends(struct Graph* network, int user1, int user2) {
    printf("\nMutual friends between %s and %s: ", 
           users[user1].name, users[user2].name);
    
    struct Node* friends1 = network->array[user1].head;
    int found = 0;
    
    while (friends1) {
        struct Node* friends2 = network->array[user2].head;
        while (friends2) {
            if (friends1->dest == friends2->dest) {
                if (found) printf(", ");
                printf("%s", users[friends1->dest].name);
                found = 1;
                break;
            }
            friends2 = friends2->next;
        }
        friends1 = friends1->next;
    }
    
    if (!found) printf("(none)");
    printf("\n");
}

int main() {
    printf("=== SOCIAL NETWORK SYSTEM ===\n");
    printf("Real-world use: Facebook, LinkedIn, Twitter connections\n\n");
    
    initUsers();
    struct Graph* network = createGraph(5);
    
    printf("--- Building Social Network ---\n");
    addFriendship(network, 0, 1); // Alice - Bob
    addFriendship(network, 0, 2); // Alice - Charlie
    addFriendship(network, 1, 2); // Bob - Charlie
    addFriendship(network, 1, 3); // Bob - Diana
    addFriendship(network, 2, 4); // Charlie - Eve
    addFriendship(network, 3, 4); // Diana - Eve
    
    showNetwork(network);
    
    printf("\n--- Friend Statistics ---\n");
    for (int i = 0; i < 5; i++) {
        printf("%s has %d friend(s)\n", users[i].name, countFriends(network, i));
    }
    
    printf("\n--- Finding Mutual Friends ---\n");
    findMutualFriends(network, 0, 1); // Alice and Bob
    findMutualFriends(network, 1, 3); // Bob and Diana
    findMutualFriends(network, 2, 4); // Charlie and Eve
    
    printf("\n✓ Graph structure efficiently represents social connections!\n");
    
    freeGraph(network);
    return 0;
}