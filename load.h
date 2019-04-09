#ifndef LIB_H
#define LIB_H
#define MAX_STRLEN 100
#define MAX_CELL_SIZE 50
#define MAX_SIZE 41
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char routing [MAX_SIZE][MAX_SIZE][MAX_CELL_SIZE],
         layout [MAX_SIZE][MAX_SIZE][MAX_CELL_SIZE];
} matrix;

typedef struct{
    char input[MAX_STRLEN],
         layout[MAX_STRLEN],
         routing[MAX_STRLEN];
}name;

typedef struct{
    FILE *layout,
         *routing;
} external_file;

typedef struct{
    int N, M;
    name nama;
    external_file file;
    matrix tabel;
} project;
project proyek;

int baca_opsi(){
int opsi_i;
char opsi_c;
    printf("Masukan: ");
    scanf(" %c", &opsi_c);
    opsi_i=opsi_c-'0';
    return opsi_i;
}

void tab(){
    printf("   ");
    return;
}
#endif
