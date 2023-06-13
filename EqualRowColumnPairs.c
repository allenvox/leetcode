#include <stdio.h>
#include <stdlib.h>

int equalPairs(int **grid, int gridSize, int *gridColSize) {
    int result = 0;
    for(int i = 0; i < gridSize; i++) { // all rows
        for(int j = 0; j < gridSize; j++) { // all cols
            int areEqual = 1;
            for(int k = 0; k < gridSize; k++) {
                if(grid[i][k] != grid[k][j]) {
                    areEqual = 0;
                }
            }
            if(areEqual) result += 1;
        }
    }
    return result;
}

void output(int **grid, int gridSize) {
    printf("There are %d equal row & column pairs in this matrix:\n", equalPairs(grid, gridSize, NULL));
    for(int i = 0; i < gridSize; i++) {
        for(int j = 0; j < gridSize; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int size = 3;
    int **x3 = malloc(sizeof(int*) * size);
    for(int i = 0; i < size; i++) {
        x3[i] = malloc(sizeof(int*) * size);
    }
    x3[0][0] = 3; x3[0][1] = 2; x3[0][2] = 1; x3[1][0] = 1; x3[1][1] = 7; x3[1][2] = 6; x3[2][0] = 2; x3[2][1] = 7; x3[2][2] = 7;
    output(x3, size);
    printf("\n");
    size = 4;
    int **x4 = malloc(sizeof(int*) * size);
    for(int i = 0; i < size; i++) {
        x4[i] = malloc(sizeof(int*) * size);
    }
    x4[0][0] = 3; x4[0][1] = 1; x4[0][2] = 2; x4[0][3] = 2; x4[1][0] = 1; x4[1][1] = 4; x4[1][2] = 4; x4[1][3] = 5; x4[2][0] = 2; x4[2][1] = 4; x4[2][2] = 2; x4[2][3] = 2; x4[3][0] = 2; x4[3][1] = 4; x4[3][2] = 2; x4[3][3] = 2;
    output(x4, size);
    return 0;
}