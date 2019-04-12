//***********************************************************//
// [ Source Code ]
//
// Institution : Institut Teknologi Bandung
// Name : David Khowanto
// File Name : schedulemanual.h
// Dependency : stdio.h, stdlib.h, string.h
//
//
/* Description: 
Semua Prosedur dan Fungsi dalam file schedulemanual.c hanya digunakan untuk
prosedur [MODE SCHEDULE] atau pengisian schedule secara manual oleh user.
Validasi dan syarat-syarat sesuai dengan yang tertera pada Tugas_Besar_versi_final.pdf
-Tidak ada asumsi yang diambil sendiri oleh programmer
-Tidak ada syarat dari soal yang di skip programmer

file header schedulemanual.h digunakan untuk mempermudah integrasi antara 
main ( ) dan prosedur [Mode Schedule] manual,
Status:
1. David Khowanto - 13217056 : Create the file, fix all bug,
							   and test all possibilities according
							   to description in the pdf file
*/
//***********************************************************//
#ifndef SCHEDULELIB_H
#define SCHEDULELIB_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char kode_praktikum[7];
	char Rombongan[3];
	char nama_asisten[5];
	int count_asisten;
} jadwal_t; 

//pengecekan apakah rombongan dengan kode praktikum tersebut sudah terdaftar pada minggu tersebut
int isJadwal_exist(char kode[7], jadwal_t (*R1)[5], jadwal_t (*R2)[5], jadwal_t (*R3)[5], jadwal_t (*R4)[5], char *romb, int minggu);
//konversi hari dari string menjadi integer
int strToInt_hari(char hari[7]);
//konversi hari dari integer menjadi string
char *intToStr_hari(int hari);
//validasi apakah terdapat tiga atau dua ruang kosong di hari itu tergantung kode praktikum
int is3Ruang_kosong(jadwal_t (*R1)[5], jadwal_t (*R2)[5], jadwal_t (*R3)[5], jadwal_t (*R4)[5],char *kode, int minggu, int hari);
//validasi apakah terdapat satu ruang kosong di hari itu 
int isRuang_kosong(jadwal_t (*R1)[5], jadwal_t (*R2)[5], jadwal_t (*R3)[5], jadwal_t (*R4)[5],char *kode, int minggu, int hari);
// mengecek ruang yang dimasukkan apakah kosong atau terpakai
void ruang_kosong(jadwal_t (*R1)[5], jadwal_t (*R2)[5], jadwal_t (*R3)[5], jadwal_t (*R4)[5],char *kode, char *ruang, int minggu, int hari);
//pengisian jadwal eb2200
void jadwal_eb2200(jadwal_t (*R1)[5], jadwal_t (*R2)[5], jadwal_t (*R3)[5], jadwal_t (*R4)[5], char *romb,char *ruang,int *minggu, int*hari);
//pengisian jadwal el2208
void jadwal_el2208(jadwal_t (*R1)[5], jadwal_t (*R2)[5], jadwal_t (*R3)[5], jadwal_t (*R4)[5], char *romb,char ruang3[][5], char *ruang,int *minggu, int *hari);
//pengisian jadwal el2205
void jadwal_el2205(jadwal_t (*R1)[5], jadwal_t (*R2)[5], jadwal_t (*R3)[5], jadwal_t (*R4)[5], char *romb,char ruang2[][5],char *ruang,int *minggu, int*hari);
// PROSEDUR PENGISIAN ARRAY
void save_array(jadwal_t (*LAB1)[5], jadwal_t (*LAB2)[5], jadwal_t (*LAB3)[5], jadwal_t (*LSS)[5], char *kode_temp,char *romb_temp,char ruang3_temp[][5],char *ruang_temp,int minggu_temp, int hari_temp);
// P R O S E D U R   U T A M A   U N T U K   M O D E   S C H E D U L E
void jadwal_prak(jadwal_t (*LAB1)[5], jadwal_t (*LAB2)[5], jadwal_t (*LAB3)[5], jadwal_t (*LSS)[5]);

#endif