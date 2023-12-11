#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a symbol entry
struct SymbolEntry {
    char name[20];
    int value;
};

// Structure to represent the symbol table
struct SymbolTable {
    struct SymbolEntry entries[50];
    int count;
};

// Function prototypes
void insert(struct SymbolTable* symbolTable, char name[], int value);
void update(struct SymbolTable* symbolTable, char name[], int value);
void delete(struct SymbolTable* symbolTable, char name[]);
int search(struct SymbolTable* symbolTable, char name[]);
void display(struct SymbolTable* symbolTable);

int main() {
    struct SymbolTable symbolTable;
    symbolTable.count = 0;

    int choice;
    char name[20];
    int value;

    do {
        // Display menu
        printf("\nSymbol Table Menu:\n");
        printf("1. Insert\n");
        printf("2. Update\n");
        printf("3. Delete\n");
        printf("4. Search\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Insert
                printf("Enter symbol name: ");
                scanf("%s", name);
                printf("Enter symbol value: ");
                scanf("%d", &value);
                insert(&symbolTable, name, value);
                break;
            case 2:
                // Update
                printf("Enter symbol name: ");
                scanf("%s", name);
                printf("Enter new symbol value: ");
                scanf("%d", &value);
                update(&symbolTable, name, value);
                break;
            case 3:
                // Delete
                printf("Enter symbol name: ");
                scanf("%s", name);
                delete(&symbolTable, name);
                break;
            case 4:
                // Search
                printf("Enter symbol name: ");
                scanf("%s", name);
                if (search(&symbolTable, name) != -1) {
                    printf("Symbol found in the table.\n");
                } else {
                    printf("Symbol not found in the table.\n");
                }
                break;
            case 5:
                // Display
                display(&symbolTable);
                break;
            case 6:
                // Exit
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
        }

    } while (choice != 6);

    return 0;
}

// Function to insert a symbol into the symbol table
void insert(struct SymbolTable* symbolTable, char name[], int value) {
    // Check if the symbol already exists
    int index = search(symbolTable, name);

    if (index == -1) {
        // Symbol does not exist, insert a new entry
        strcpy(symbolTable->entries[symbolTable->count].name, name);
        symbolTable->entries[symbolTable->count].value = value;
        symbolTable->count++;
        printf("Symbol inserted into the table.\n");
    } else {
        // Symbol already exists, display an error message
        printf("Symbol with the same name already exists in the table.\n");
    }
}

// Function to update the value of a symbol in the symbol table
void update(struct SymbolTable* symbolTable, char name[], int value) {
    int index = search(symbolTable, name);

    if (index != -1) {
        // Symbol found, update its value
        symbolTable->entries[index].value = value;
        printf("Symbol updated in the table.\n");
    } else {
        // Symbol not found, display an error message
        printf("Symbol not found in the table.\n");
    }
}

// Function to delete a symbol from the symbol table
void delete(struct SymbolTable* symbolTable, char name[]) {
    int index = search(symbolTable, name);

    if (index != -1) {
        // Symbol found, delete its entry
        for (int i = index; i < symbolTable->count - 1; i++) {
            strcpy(symbolTable->entries[i].name, symbolTable->entries[i + 1].name);
            symbolTable->entries[i].value = symbolTable->entries[i + 1].value;
        }
        symbolTable->count--;
        printf("Symbol deleted from the table.\n");
    } else {
        // Symbol not found, display an error message
        printf("Symbol not found in the table.\n");
    }
}

// Function to search for a symbol in the symbol table
int search(struct SymbolTable* symbolTable, char name[]) {
    for (int i = 0; i < symbolTable->count; i++) {
        if (strcmp(symbolTable->entries[i].name, name) == 0) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

// Function to display the contents of the symbol table
void display(struct SymbolTable* symbolTable) {
    printf("\nSymbol Table:\n");
    printf("Name\tValue\n");
    for (int i = 0; i < symbolTable->count; i++) {
        printf("%s\t%d\n", symbolTable->entries[i].name, symbolTable->entries[i].value);
    }
}
