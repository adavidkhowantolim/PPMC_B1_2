//***********************************************************//
// [ Source Code ]
//
// Institution : Institut Teknologi Bandung
// Name : Louis
// File Name : assignasisten.h
// Dependency : stdio.h, string.h
//
// 
/* Description:
Semua Prosedur dan Fungsi dalam file assignasisten.c hanya digunakan untuk
prosedur [MODE ASSIGN SCHEDULE] atau pengisian assign asisten secara manual oleh user.
Validasi dan syarat-syarat sesuai dengan yang tertera pada Tugas_Besar_versi_final.pdf
-Dengan asumsi: input 'q' atau 'Q' hanya dapat dibaca pada pemilihan asisten saja, 
 untuk validasi input asisten, hari, minggu, dan ruang dilakukan berulang hingga benar
 serta validasi syarat yang diberikan dari soal akan mengulang input dari awal
-Tidak ada syarat dari soal yang di skip programmer
Status:
1. Louis - 13217072 : Create the file, fix all bug,
and test all possibilities according to description in the pdf file
*/
//***********************************************************//
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
