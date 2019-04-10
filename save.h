//***********************************************************//
// [ Source Code ]
//
// Institution : Institut Teknologi Bandung
// Name : David Khowanto, Louis,Elizabeth Kahny Dhea P.
// File Name : save.c
// Dependency : save.h
//
// 
/* Description:
Menyimpan array data ke dalam file CSV

Status:
1. David Khowanto - 13217056 : Test and debugging
2. Louis - 13217072 : create the program, Test and debugging
3. Elizabeth K. Dhea  P.- 13217068 : create the program
*/
//***********************************************************//
#ifndef SAVE_H
#define SAVE_H
#include <stdio.h>
#include <string.h>
#include "schedulemanual.h"

char* konv_string(int b);
void Simpan (char *filename,jadwal_t (*LAB1)[5], jadwal_t (*LAB2)[5], jadwal_t (*LAB3)[5], jadwal_t (*LSS)[5]);

#endif
