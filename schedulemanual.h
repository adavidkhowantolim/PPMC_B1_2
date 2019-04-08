#ifndef SCHEDULELIB_H
#define SCHEDULELIB_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
	char kode_praktikum[7];
	char rombongan[3];
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