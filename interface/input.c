#include "input.h"

int** input(int** matrix, int* columns, int* rows){
    if(*rows == 0){
        matrix = freeAll(matrix, columns, rows);
    }
    printInputMenu();
    int n = validInput(1, 4);
    switch (n) {
        case 1:{
            matrix = consoleInput(matrix, columns, rows);
            break;
        }
        case 2:{
            printFileField(1);
            FILE* fm = NULL;
            fm = validFile(fm);
            matrix = fileInput(fm, matrix, columns, rows);
            fclose(fm);
            break;
        }
        case 3:{
            matrix = generate(matrix, columns, rows);
            break;
        }
        default:{
            return matrix;
        }
    }
    return matrix;
}

int** consoleInput(int** matrix, int* columns, int* rows){
    printf("Enter count of rows: ");
    scanf("%d", rows);
    printf("Enter count of columns: ");
    scanf("%d", columns);

    matrix = (int**) malloc(*rows * sizeof(int*));
    for(int i = 0; i < *rows; i++){
        printf("Enter %d element(s) of rows %d through space\n", *columns, i);
        matrix[i] = (int*) malloc(*columns * sizeof(int));
        matrix[i] = consoleInputOne(matrix[i], columns);
    }
    return matrix;
}

int* consoleInputOne(int* massive, const int* len){
    printf("Enter %d elements of massive\n", *len);
    for(int j = 0; j < *len; j++){
        scanf("%d", &(massive[j]));
    }
    return massive;
}

int validInput(int min, int max){
    int n;
    while(1){
        printf("Your answer: ");
        scanf("%d", &n);
        if(n >= min && n <= max) return n;
        printf("You can enter from %d to %d\n", min, max);
    }
}

FILE* validFile(FILE* fm){
   	char* filename;
    while(1){
        printFileField(1);
        filename = readline("");
        if((fm = fopen(filename, "rb")) != NULL){
            free(filename);
            return fm;
        }
        printf("This file doesn't exist\n");
        free(filename);
    }
}

int** fileInput(FILE* fm, int** matrix, int* columns, int* rows){

    return matrix;
}
