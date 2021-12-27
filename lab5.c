#include "stdio.h"
#include "interface/menu.h"
#include "interface/input.h"
#include "interface/output.h"
#include "update/update.h"


int main(){
    int** matrix = NULL; int columns = 0, rows = 0;
    while(1){
        printMenu();
        int n = validInput(1, 4);
        switch (n) {
            case 1:{
                printf("<------------------------------------------------>\n");
                matrix = input(matrix, &columns, &rows);
                printf("<------------------------------------------------>\n");
                break;
            }
            case 2:{
                printf("<------------------------------------------------>\n");
                output(matrix, columns, rows);
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
                return 0;
            }
            default:{
                printf("This point doesn't exist\n");
            }
        }
    }
}
