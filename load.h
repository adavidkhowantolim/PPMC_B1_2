//***********************************************************//
// [ Source Code ]
//
// Institution : Institut Teknologi Bandung
// Name : David Khowanto, Louis, Elizabeth Kahny Dhea P.
// File Name : load.c
// Dependency : schedulemanual.h, load.h
//
// 
/* Description:
Program untuk membaca data dari file csv dan memindahkan ke array data

Status:
1. David Khowanto - 13217056 : Test and debugging
2. Louis - 13217072 : Test and debugging
3. Elizabeth K. Dhea  P.- 13217068 : create the program
*/
//***********************************************************//
#ifndef LIB_H
#define LIB_H
#define MAX_STRLEN 50 // maksimum panjang string
#define MAX_CELL_SIZE 50 // jumlah karakter paling banyak dalam 1 cell
#define MAX_SIZE 53 // jumlah cell kebawah
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "schedulemanual.h"

int opsi,i,k,n,j,N,m;
char array[MAX_SIZE][MAX_SIZE][MAX_CELL_SIZE];
char temp[MAX_SIZE][MAX_STRLEN];
char filename[50],fasis[50],fsche[50];

//menerima input opsi pada menu utama 1/2/3
int baca_opsi();
//kalau ada koma dia ngebaca next cell
void format_prog(char (*str)[MAX_STRLEN],jadwal_t (*LAB1)[5], jadwal_t (*LAB2)[5], jadwal_t (*LAB3)[5], jadwal_t (*LSS)[5]);
//membaca proyek
void baca_proyek(FILE *file,jadwal_t (*LAB1)[5], jadwal_t (*LAB2)[5], jadwal_t (*LAB3)[5], jadwal_t (*LSS)[5]);
//memvalidasi file yang dibuka, kalau file tidak mencapai 2 buah maka tidak akan dibuka
void buka_proyek(jadwal_t (*LAB1)[5], jadwal_t (*LAB2)[5], jadwal_t (*LAB3)[5], jadwal_t (*LSS)[5]);
//sambungan fungsi sebelumnya
void error_buka_proyek(jadwal_t (*LAB1)[5], jadwal_t (*LAB2)[5], jadwal_t (*LAB3)[5], jadwal_t (*LSS)[5]);


#endif
