#ifndef LAB4_UPDATE_H
#define LAB4_UPDATE_H

#include "../interface/input.h"

int** freeAll(int**, int*, int*);

int** insertColumn(int**, int*, int, int, const int*);
int** insertRow(int**, int, int*, int, const int*);

int** deleteColumn(int**, int*, int, int);
int** deleteRows(int**, int, int*, int);

void swapColumns(int**, int, int, int)
int** sort(int**, int, int);

int** update(int**, int*, int*);

#endif //LAB4_UPDATE_H
