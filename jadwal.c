#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char kode_praktikum[6];
	char rombongan[2];
} jadwal_t;

//pengecekan apakah rombongan dengan kode praktikum tersebut sudah terdaftar pada minggu tersebut
int isJadwal_exist(char kode[6], jadwal_t R1, jadwal_t R2, jadwal_t R3, jadwal_t R4, char romb, int minggu){
	char *p,*q,*r,*s;
	char *a,*b,*c,*d;
	int exist1=0,exist2=0;
	for (int hari = 1; hari < 6; ++hari) {
		p=R1[minggu-1][hari-1].kode_praktikum;
		q=R2[minggu-1][hari-1].kode_praktikum;
		r=R3[minggu-1][hari-1].kode_praktikum;
		s=R4[minggu-1][hari-1].kode_praktikum;
		a=R1[minggu-1][hari-1].rombongan;
		b=R2[minggu-1][hari-1].rombongan;
		c=R3[minggu-1][hari-1].rombongan;
		d=R4[minggu-1][hari-1].rombongan;
		exist1 = strcmp(p,kode)+strcmp(q,kode)+strcmp(r,kode)+strcmp(s,kode);
		exist2 = strcmp(a,romb)+strcmp(b,romb)+strcmp(c,romb)+strcmp(d,romb);
		if (exist2==0 && exist1==0) {
			return 1;
		} else if (hari==5) {
			return 0;
		}
	}
}

//validasi hari
int isHari_benar()

//validasi apakah terdapat ruang kosong di hari itu
int isRuang_kosong()

//validasi apakah ruangan tersebut sudah dipakai
int isRuang_terpakai()

//pengisian jadwal eb2200
void jadwal_eb2200(jadwal_t R1, jadwal_t R2, jadwal_t R3, jadwal_t R4, char *romb,char *ruang,int *minggu, int*hari){
	char kode[6]="EB2200";
	//INPUT ROMBONGAN
	while (strcmp(romb,"A")!=0 && strcmp(romb,"B")!=0){
		printf("Rombongan (A atau B): ");	
		scanf("%s",romb);
		if (strcmp(romb,"A")!=0 && strcmp(romb,"B")!=0){
			printf("ERROR!! EB2200 hanya terdiri atas rombongan A dan B\n");
		}
	}
	//INPUT MINGGU
	while (minggu<3 && minggu>12 && isJadwal_exist(kode, LAB1,LAB2,LAB3,LSS,romb,minggu)==0) {
		printf("Rombongan (A atau B): ");	
		scanf("%d",&minggu);
		if (minggu<3 && minggu>12){
			printf("ERROR!! Praktikum hanya boleh dilaksanakan pada minggu 3-12\n");
		} else if (isJadwal_exist(kode, LAB1,LAB2,LAB3,LSS,romb,minggu)==1){

		}
	}

}

//pengisian jadwal el2208
void jadwal_el2208(jadwal_t R1, jadwal_t R2, jadwal_t R3, jadwal_t R4, char *romb,char *ruang,int *minggu, int*hari){
	
}

//pengisian jadwal el2205
void jadwal_el2205(jadwal_t R1, jadwal_t R2, jadwal_t R3, jadwal_t R4, char *romb,char *ruang,int *minggu, int*hari){
	
}

void jadwal_prak(){
	jadwal_t LAB1[12][5];
	jadwal_t LAB2[12][5];
	jadwal_t LAB3[12][5];
	jadwal_t LSS[12][5];
	char kode_temp[6]="";
	char romb_temp[2]="";
	char ruang_temp[4]="";
	int minggu_temp=0;
	int hari_temp=0;

	while (1){
		printf("Isi `q` atau `Q` untuk kembali ke menu\n");
		while ((strcmp(kode_temp,"q")==0 || strcmp(kode_temp,"Q")==0) &&strcmp(kode_temp,"EB2200")==0 && strcmp(kode_temp,"EL2208")==0 && strcmp(kode_temp,"EL2205")==0)
			printf("Pilih Kode Praktikum (EL2205, EL2208, EB2200): ");
			scanf("%s",kode_temp);
			if (strcmp(kode_temp,"EB2200")==0) {
				//panggil fungsi eb2200
				//jadwal_eb2200(&LAB1,&LAB2,&LAB3,&LSS,&romb_temp,&ruang_temp,&minggu_temp,&hari_temp);
			} else if (strcmp(kode_temp,"EL2208")==0) {
				//panggil fungsi el2208
				//jadwal_el2208(&LAB1,&LAB2,&LAB3,&LSS,&romb_temp,&ruang_temp,&minggu_temp,&hari_temp);
			} else if (strcmp(kode_temp,"EL2205")==0) {
				//panggil fungsi el2205
				//jadwal_el2205(&LAB1,&LAB2,&LAB3,&LSS,&romb_temp,&ruang_temp,&minggu_temp,&hari_temp);
			} else if (strcmp(kode_temp,"q")==0 || strcmp(kode_temp,"Q")==0) {
				//keluar dari prosedur jadwal_prak
				return;
			} else {
				printf("Kode praktikum yang dipilih tidak sesuai\n");
			}
		}
	}

int main(){

}