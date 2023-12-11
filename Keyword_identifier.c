#include <stdio.h>
#include <string.h>

// Define an array of keywords
char *keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default",
    "do", "double", "else", "enum", "extern", "float", "for", "goto",
    "if", "int", "long", "register", "return", "short", "signed",
    "sizeof", "static", "struct", "switch", "typedef", "union",
    "unsigned", "void", "volatile", "while"
};

// Function to check if a string is a keyword
int isKeyword(char *str) {
    int i;
    int totalKeywords = sizeof(keywords) / sizeof(keywords[0]);

    for (i = 0; i < totalKeywords; i++) {
        if (strcmp(keywords[i], str) == 0) {
            return 1; // It's a keyword
        }
    }

    return 0; // It's not a keyword
}

int main() {
    char input[100];
    printf("Enter a C program: \n");

    while (1) {
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        if (isKeyword(input)) {
            printf("%s is a keyword.\n", input);
        } else {
            printf("%s is an identifier.\n", input);
        }
    }

    return 0;
}
