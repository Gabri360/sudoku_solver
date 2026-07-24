#ifndef SUDOKU_LIB
#define SUDOKU_LIB
#include <stdio.h>

typedef struct
{
    int val;
    double pr;
    int trial;
    double tent;
}sit;

void title();

void parser(int sdk[9][9], char filename[]);

void init_sdk(sit m[9][9][9]);

int check(int sdk[9][9]);

void copy(int a[9][9], int b[9][9]);

int check_error(sit m[9][9][9]);

void copy_sit(sit a[9][9][9], sit b[9][9][9]);

void stp_sdk(int m[9][9]);

#endif