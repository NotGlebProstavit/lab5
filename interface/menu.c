#include "menu.h"

void printMenu(){
    printf("Enter number of menu point\n");
    printf("  1) Input data\n");
    printf("  2) Output data\n");
    printf("  3) Update data\n");
    printf("  4) Exit\n");
}

void printInputMenu(){
    printf("Enter number of input-menu point\n");
    printf("  1) Console\n");
    printf("  2) File\n");
    printf("  3) Random\n");
    printf("  4) Back\n");
}

void printOutputMenu(){
    printf("Enter number of output-menu point\n");
    printf("  1) Console\n");
    printf("  2) File\n");
    printf("  3) Back\n");
}

void printUpdateMenu(){
    printf("Enter number of update-menu\n");
    printf("  1) Insert column by index\n");
    printf("  2) Insert rows by index\n");
    printf("  3) Delete column by index\n");
    printf("  4) Delete rows by index\n");
    printf("  5) Sorted by max elements in columns\n");
    printf("  6) Back\n");
}

void printFileField(int mod){
    switch (mod) {
        case 1:{
            printf("!!!WARNING!!!\n");
            printf("  1) Input binary file must be near source file\n");
            break;
        }
        case 2:{
            printf("!!!WARNING!!!\n");
            printf("  1) If binary file doesn't exist it will be create\n");
            break;
        }
    }
    printf("Enter file name: ");
}
