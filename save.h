#ifndef SAVE_H
#define SAVE_H
#include <stdio.h>
#include <string.h>

typedef struct {
	char kode_praktikum[10];
	char Rombongan[10];
	int count_asisten;
	char nama_asisten[3];
} jadwal_t;

jadwal_t LAB1[12][5], LAB2[12][5], LAB3[12][5], LSS[12][5];

char* konversiString(int b);
void Simpan (char *filename);

#endif
