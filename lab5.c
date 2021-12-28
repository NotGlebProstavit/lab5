#include "stdio.h"
#include "interface/menu.h"
#include "interface/input.h"
#include "interface/output.h"
#include "update/update.h"

int main(){
    int** matrix = NULL; int columns = 0, rows = 0;
    int** c_matrix = NULL; int c_columns = 0, c_rows = 0;
    while(1){
        printMenu();
        int n = validInput(1, 4);
        switch (n) {
            case 1:{
                printf("<------------------------------------------------>\n");
                
                matrix = input(matrix, &columns, &rows);
       			if(c_matrix != NULL) c_matrix = freeAll(c_matrix, &c_columns, &c_rows);
       			c_matrix = copyMatrix(c_matrix, matrix, columns, rows);
       			c_columns = columns;
       			c_rows = rows;
                printf("<------------------------------------------------>\n");
                break;
            }
            case 2:{
                printf("<------------------------------------------------>\n");
             	printf("What do you want output: source(1) or changed(2) matrix?\n");
             	int type = validInput(1,2);
             	if(type == 1){
             		output(c_matrix, c_columns, c_rows);
             	} else {
             		output(matrix, columns, rows);
             	}
                printf("<------------------------------------------------>\n");
                break;
            }
            case 3:{
                printf("<------------------------------------------------>\n");
                matrix = update(matrix, &columns, &rows);
                printf("<------------------------------------------------>\n");
                break;
            }
            case 4:{
                freeAll(matrix, &columns, &rows);
                freeAll(c_matrix, &c_columns, &c_rows);
                return 0;
            }
            default:{
                printf("This point doesn't exist\n");
            }
        }
    }
}
