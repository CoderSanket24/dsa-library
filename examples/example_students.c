/*
 * PROBLEM: Student Database Management
 * 
 * Real-world application: School management systems, employee databases
 * 
 * This program uses a BST for efficient student record searching by ID.
 * Also demonstrates SORTING for ranking students by grades.
 */

#include <stdio.h>
#include <string.h>
#include "bst.h"
#include "sorting.h"

typedef struct {
    int id;
    char name[30];
    int grade;
} Student;

Student students[100];
int studentCount = 0;

void addStudent(BST* database, int id, const char* name, int grade) {
    students[studentCount].id = id;
    strncpy(students[studentCount].name, name, 29);
    students[studentCount].name[29] = '\0';
    students[studentCount].grade = grade;
    
    insertBST(database, id);
    printf("✓ Added: ID=%d, Name=%s, Grade=%d\n", id, name, grade);
    studentCount++;
}

Student* findStudent(int id) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            return &students[i];
        }
    }
    return NULL;
}

void searchStudent(BST* database, int id) {
    if (searchBST(database, id)) {
        Student* s = findStudent(id);
        if (s) {
            printf("✓ Found: ID=%d, Name=%s, Grade=%d\n", 
                   s->id, s->name, s->grade);
        }
    } else {
        printf("✗ Student with ID %d not found\n", id);
    }
}

void rankStudents() {
    printf("\n--- Student Rankings (by Grade) ---\n");
    
    // Create array of grades with indices
    int grades[100];
    int indices[100];
    
    for (int i = 0; i < studentCount; i++) {
        grades[i] = students[i].grade;
        indices[i] = i;
    }
    
    // Sort using bubble sort (simple for demonstration)
    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = 0; j < studentCount - i - 1; j++) {
            if (grades[j] < grades[j + 1]) { // Descending order
                // Swap grades
                int temp = grades[j];
                grades[j] = grades[j + 1];
                grades[j + 1] = temp;
                
                // Swap indices
                temp = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = temp;
            }
        }
    }
    
    printf("Rank | ID   | Name              | Grade\n");
    printf("-----|------|-------------------|------\n");
    for (int i = 0; i < studentCount; i++) {
        Student* s = &students[indices[i]];
        printf("%-4d | %-4d | %-17s | %d\n", 
               i + 1, s->id, s->name, s->grade);
    }
}

int main() {
    printf("=== STUDENT DATABASE MANAGEMENT ===\n");
    printf("Real-world use: School systems, employee databases, record management\n\n");
    
    BST database;
    initBST(&database);
    
    printf("--- Adding Students ---\n");
    addStudent(&database, 1001, "Alice Johnson", 95);
    addStudent(&database, 1005, "Bob Smith", 87);
    addStudent(&database, 1003, "Charlie Brown", 92);
    addStudent(&database, 1007, "Diana Prince", 88);
    addStudent(&database, 1002, "Eve Wilson", 91);
    addStudent(&database, 1006, "Frank Miller", 85);
    addStudent(&database, 1004, "Grace Lee", 94);
    
    printf("\n--- Searching Students (using BST) ---\n");
    searchStudent(&database, 1003);
    searchStudent(&database, 1007);
    searchStudent(&database, 9999);
    
    printf("\n--- All Students (In-order by ID) ---\n");
    printf("Student IDs in BST: ");
    inorderTraversal(&database);
    
    rankStudents();
    
    printf("\n✓ BST enables O(log n) search, Sorting enables ranking!\n");
    
    freeBST(&database);
    return 0;
}