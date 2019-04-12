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
1. Louis - 13217072 : create the progaram Test and debugging
2. Elizabeth K. Dhea  P.- 13217068 : create the program
*/
//***********************************************************//
#ifndef LOAD1_H
#define LOAD1_H
#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
#include "schedulemanual.h"

void load(char* filename,jadwal_t (*LAB1)[5], jadwal_t (*LAB2)[5], jadwal_t (*LAB3)[5], jadwal_t (*LSS)[5]);

#endif