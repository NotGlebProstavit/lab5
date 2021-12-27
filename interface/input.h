#ifndef LAB5_INPUT_H
#define LAB5_INPUT_H

#include "stdio.h"
#include "readline/readline.h"
#include "freadline/freadline.h"
#include "menu.h"
#include "../randomize/randomize.h"
#include "../update/update.h"

int** input(int**, int*, int*);

int** consoleInput(int**, int*, int*);
int* consoleInputOne(int*, const int*);

int** fileInput(FILE*, int**, int*, int*);

int validInput(int, int);
FILE* validFile(FILE*);

#endif //LAB5_INPUT_H
