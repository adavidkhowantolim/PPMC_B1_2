#ifndef ASSIGNASISTEN_H
#define ASSIGNASISTEN_H
#include <stdio.h>
#include <string.h>

typedef struct {
	char kode_praktikum[10];
	char Rombongan[10];
	int count_asisten;
	char nama_asisten[3];
} jadwal_t;

typedef struct daftarAsisten{
	char nama[10];
	int praktikum[3];
	int count_praktikum;
	int hari_berhalangan[3];
	int count_hari_berhalangan;
} keterangan;

jadwal_t LAB1[12][5], LAB2[12][5], LAB3[12][5], LSS[12][5];

void assignAsisten(char *c);
void assignMinggu(int *m);
void assignRuang(char *r);
int konversiString(char *b);
void assignPrakHari(keterangan *a,char c);
char* konversiKode(int k);
int isEmptySchedule(jadwal_t (*ruang)[5],int m,int h);
int isTidakBerhalangan(keterangan* a,int hari);
int isSesuaiPraktikum(keterangan *a,int praktikum);
void validasi(jadwal_t (*arr)[5],int m,int h,keterangan infoAsisten,char c);
void fungsiMainAssignAsisten();
#endif