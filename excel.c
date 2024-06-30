#include <stdio.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 10
#define MAX_CELL_LENGTH 50

char data[MAX_ROWS][MAX_COLS][MAX_CELL_LENGTH];

int main() {
    int row, col;
    FILE *file;

    // Open the input file
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Input data automatically like Excel
    for (row = 0; row < MAX_ROWS; row++) {
        for (col = 0; col < MAX_COLS; col++) {
            fscanf(file, "%s", data[row][col]);
        }
    }

    // Close the input file
    fclose(file);

    // Print the input data
    for (row = 0; row < MAX_ROWS; row++) {
        for (col = 0; col < MAX_COLS; col++) {
            printf("%s\t", data[row][col]);
        }
        printf("\n");
    }

    return 0;
}