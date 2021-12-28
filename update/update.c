#include "update.h"

int** freeAll(int** matrix, int* columns, int* rows){
    for(int i = 0; i < *rows; i++){
        free(matrix[i]);
    }
    free(matrix);
    *rows = 0;
    *columns = 0;
    return NULL;
}

int** copyMatrix(int** dist, int** src, int columns, int rows){
	dist = (int**) malloc(rows * sizeof(int*));
	for(int i = 0; i < rows; i++){
		dist[i] = (int*) malloc(columns * sizeof(int));
		for(int j = 0; j < columns; j++){
			dist[i][j] = src[i][j];
		}
	}
	return dist;
}

int** insertColumn(int** matrix, int* columns, int rows, int index, const int* massive){
    for(int i = 0; i < rows; i++){
        matrix[i] = (int*) realloc(matrix[i], (*columns + 1) * sizeof(int));
        for(int j = *columns; j > index; j--){
            matrix[i][j] = matrix[i][j-1];
        }
        matrix[i][index] = massive[i];
    }
    *columns += 1;
    return matrix;
}

int** insertRow(int** matrix, int columns, int* rows, int index, const int* massive){
    matrix = (int**) realloc(matrix, (*rows + 1)* sizeof(int*));
    matrix[*rows] = (int*) malloc(columns * sizeof(int));
    for(int i = *rows; i > index; i--){
        for(int j = 0; j < columns; j++){
            matrix[i][j] = matrix[i-1][j];
        }
    }
    for(int i = 0; i < columns; i++){
        matrix[index][i] = massive[i];
    }
    *rows += 1;
    return matrix;
}

int** deleteColumn(int** matrix, int* columns, int rows, int index){
    for(int i = 0; i < rows; i++){
        for(int j = index; j < *columns - 1; j++){
            matrix[i][j] = matrix[i][j+1];
        }
    }
    *columns -= 1;
    for(int i = 0; i < rows; i++){
        matrix[i] = (int*) realloc(matrix[i], (*columns) * sizeof(int));
    }
    return matrix;
}

int** deleteRow(int** matrix, int columns, int* rows, int index){
   	for(int i = index; i < *rows - 1; i++){
   		for(int j = 0; j < columns; j++){
   			matrix[i][j] = matrix[i+1][j];
   		}
   	}
    free(matrix[*rows - 1]);
    *rows -= 1;
    matrix = (int**) realloc(matrix, (*rows)* sizeof(int*));
    return matrix;
}

void swapColumns(int** matrix, int rows, int a, int b){
    for(int i = 0; i < rows; i++){
        int t = matrix[i][a];
        matrix[i][a] = matrix[i][b];
        matrix[i][b] = t;
    }
}

int maxElementColumn(int** matrix, int rows, int index){
    int max = matrix[0][index];
    for(int i = 0; i < rows; i++){
        if(matrix[i][index] > max)
            max = matrix[i][index];
    }
    return max;
}

int** sort(int** matrix, int columns, int rows){
    double factor = 1.2473309;
    int step = columns - 1;
    while(step >= 1){
        for(int i = 0; i+step < columns; i++){
            if(maxElementColumn(matrix, rows, i) >
                maxElementColumn(matrix, rows, i + step)){
                swapColumns(matrix, rows, i, i + step);

            }
        }
        step = (int)(step/factor);
    }
    return matrix;
}

int** update(int** matrix, int* columns, int* rows){
    if(*columns == 0){
        printf("Matrix is empty\n");
        return matrix;
    }
    printUpdateMenu();
    int n = validInput(1, 6);
    switch (n) {
        case 1:{
            printf("Where do you want insert column?\n");
            int index = validInput(0, *columns);
            int* massive = (int*) malloc(*rows * sizeof(int));
            massive = consoleInputOne(massive, rows);
            matrix = insertColumn(matrix, columns, *rows, index, massive);
            free(massive);
            break;
        }
        case 2:{
            printf("Where do you want insert row?\n");
            int index = validInput(0, *rows);
            int* massive = (int*) malloc(*columns * sizeof(int));
            massive = consoleInputOne(massive, columns);
            matrix = insertRow(matrix, *columns, rows, index, massive);
            free(massive);
            break;
        }
        case 3:{
            printf("Where do you want delete column?\n");
            int index = validInput(0, *columns);
            matrix = deleteColumn(matrix, columns, *rows, index);
            break;
        }
        case 4:{
            printf("Where do you want delete row?\n");
            int index = validInput(0, *rows);
            matrix = deleteRow(matrix, *columns, rows, index);
            break;
        }
        case 5:{
            matrix = sort(matrix, *columns, *rows);
            break;
        }
        default:{
            return matrix;
        }
    }
    return matrix;
}
