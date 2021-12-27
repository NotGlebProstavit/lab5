#ifndef LAB5_UPDATE_H
#define LAB5_UPDATE_H

#include "../interface/input.h"

int** freeAll(int**, int*, int*);

int** insertColumn(int**, int*, int, int, const int*);
int** insertRow(int**, int, int*, int, const int*);

int** deleteColumn(int**, int*, int, int);
int** deleteRow(int**, int, int*, int);

void swapColumns(int**, int, int, int);
int** sort(int**, int, int);

int** update(int**, int*, int*);

#endif //LAB5_UPDATE_H
