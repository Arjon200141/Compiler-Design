#include <stdio.h>
#include <string.h>

int main() {
    char identifier[50][50];
    int n, i, j;

    printf("Enter the number of identifiers: ");
    scanf("%d", &n);

    printf("Enter the identifiers:\n");
    for (i = 0; i < n; i++) {
        scanf("%s", identifier[i]);
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(identifier[i], identifier[j]) == 0) {
                printf("Error: Duplicate identifier '%s' found.\n", identifier[i]);
                return 1; // Exit with an error code
            }
        }
    }

    printf("No duplicate identifier declarations found.\n");
    return 0; // Exit successfully
}
