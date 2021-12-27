#include "randomize.h"

int** generate(int** matrix, int* columns, int* rows){
    printf("Enter seed for generation: ");
    int seed;
    scanf("%d", &seed);
    srand(seed);
    *columns = rand() % 10 + 1;
    *rows = rand() % 10 + 1;
    matrix = (int**) malloc(*rows * sizeof(int*));
    for(int i = 0; i < *rows; i++){
        matrix[i] = (int*) malloc(*columns * sizeof(int));
        for(int j = 0; j < *columns; j++){
            matrix[i][j] = rand() % 10000;
        }
    }
    return matrix;
}