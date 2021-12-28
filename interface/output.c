#include "output.h"

void consoleOutput(int** matrix, int columns, int rows){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void fileOutput(FILE* fm, int** matrix, int columns, int rows){
	fwrite(&columns, sizeof(int), 1, fm);
	fwrite(&rows, sizeof(int), 1, fm);
	for(int i = 0; i < rows; i++){
		fwrite(matrix[i], sizeof(int), columns, fm);
	}
}

void output(int** matrix, int columns, int rows){
    if(matrix == NULL){
        printf("Array is empty\n");
        return;
    }
    printOutputMenu();
    int n = validInput(1, 3);
    switch (n) {
        case 1:{
            consoleOutput(matrix, columns, rows);
            break;
        }
        case 2:{
            printFileField(2);
            char* filename = readline("");
            FILE* fm = fopen(filename, "wb");
            fileOutput(fm, matrix, columns, rows);
            free(filename);
            fclose(fm);
            break;
        }
        default: return;
    }
}
