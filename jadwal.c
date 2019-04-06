#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char kode_praktikum[6];
	char rombongan[2];
} jadwal_t;

//pengecekan apakah rombongan dengan kode praktikum tersebut sudah terdaftar pada minggu tersebut
int isJadwal_exist(char kode[6], jadwal_t (*R1)[5], jadwal_t (*R2)[5], jadwal_t (*R3)[5], jadwal_t (*R4)[5], char *romb, int minggu){
	char *p,*q,*r,*s;
	char *a,*b,*c,*d;
	for (int hari = 1; hari < 6; ++hari) {
		p=R1[minggu-1][hari-1].kode_praktikum;
		q=R2[minggu-1][hari-1].kode_praktikum;
		r=R3[minggu-1][hari-1].kode_praktikum;
		s=R4[minggu-1][hari-1].kode_praktikum;
		a=R1[minggu-1][hari-1].rombongan;
		b=R2[minggu-1][hari-1].rombongan;
		c=R3[minggu-1][hari-1].rombongan;
		d=R4[minggu-1][hari-1].rombongan;
		int exist1 = abs(strcmp(p,kode))+abs(strcmp(a,romb));
		int exist2 = abs(strcmp(q,kode))+abs(strcmp(b,romb));
		int exist3 = abs(strcmp(r,kode))+abs(strcmp(c,romb));
		int exist4 = abs(strcmp(s,kode))+abs(strcmp(d,romb));

		if (exist1==0 && exist2==0 && exist3==0 && exist4==0) {
			return 1;
		} else if (hari==5) {
			return 0;
		}
	}
}

//konversi hari dari string menjadi integer
int strToInt_hari(char hari[6]){
	if (!strcmp(hari,"Senin")){
		return 1;
	} else if (!strcmp(hari,"Selasa")){
		return 2;
	} else if (!strcmp(hari,"Rabu")){
		return 3;
	} else if (!strcmp(hari,"Kamis")){
		return 4;
	} else if (!strcmp(hari,"Jumat")){
		return 5;
	}
}
//konversi hari dari integer menjadi string
char *intToStr_hari(int hari){
	if (hari==1){
		return "Senin";
	} else if (hari==2){
		return "Selasa";
	} else if (hari==3){
		return "Rabu";
	} else if (hari==4){
		return "Kamis";
	} else if (hari==5){
		return "Jumat";
	}
}

//validasi apakah terdapat tiga ruang kosong di hari itu 
int is3Ruang_kosong(jadwal_t (*R1)[5], jadwal_t (*R2)[5], jadwal_t (*R3)[5], jadwal_t (*R4)[5],char *kode, int minggu, int hari){
	int kode1 = strcmp(R1[minggu-1][hari-1].kode_praktikum,"");
	int kode2 = strcmp(R2[minggu-1][hari-1].kode_praktikum,"");
	int kode3 = strcmp(R3[minggu-1][hari-1].kode_praktikum,"");
	int kode4 = strcmp(R4[minggu-1][hari-1].kode_praktikum,""); //LSS
	int count=0;
	if (kode1==0){
		count++;
	}
	if (kode2==0){
		count++;
	}
	if (kode3==0){
		count++;
	}
	if (kode4==0 && strcmp(kode,"EL2208")==0){
		count++;
	}
	if ((count<3 && strcmp(kode,"EL2208")==0) || (count<2 && strcmp(kode,"EL2205"))){
		return 0; // ruang kosong kurang dari 3 buah untuk EL2208 dan 2 buah untuk EL2205
	} else {
		return 1; // ruang kosong lebih dari sama dengan 3 buah
	}
}

//validasi apakah terdapat satu ruang kosong di hari itu 
int isRuang_kosong(jadwal_t (*R1)[5], jadwal_t (*R2)[5], jadwal_t (*R3)[5], jadwal_t (*R4)[5],char *kode, int minggu, int hari){
	int kode1 = strcmp(R1[minggu-1][hari-1].kode_praktikum,"");
	int kode2 = strcmp(R2[minggu-1][hari-1].kode_praktikum,"");
	int kode3 = strcmp(R3[minggu-1][hari-1].kode_praktikum,"");
	int kode4 = strcmp(R4[minggu-1][hari-1].kode_praktikum,""); //LSS
	if (strcmp(kode,"EL2208")==0){
		if (kode1 == 0 || kode2 == 0 || kode3 ==0 || kode4 == 0){
			return 1;
		} else {
			return 0;
		}
	} else if (strcmp(kode,"EB2200")==0 || (strcmp(kode,"EL2205")==0)){
		if (kode1 == 0 || kode2 == 0 || kode3 ==0){
			return 1;
		} else {
			return 0;
		}
	}
// mengecek ruang yang dimasukkan apakah kosong atau terpakai
void ruang_kosong(jadwal_t (*R1)[5], jadwal_t (*R2)[5], jadwal_t (*R3)[5], jadwal_t (*R4)[5],char *kode, char *ruang, int minggu, int hari){
	int kode1 = strcmp(R1[minggu-1][hari-1].kode_praktikum,"");
	int kode2 = strcmp(R2[minggu-1][hari-1].kode_praktikum,"");
	int kode3 = strcmp(R3[minggu-1][hari-1].kode_praktikum,"");
	int kode4 = strcmp(R4[minggu-1][hari-1].kode_praktikum,""); //LSS
	// pemberitahuan kpd user apakah ruang yang diisi penuh atau tidak
	if (strcmp(ruang,"LAB1")==0 && kode1!=0){
		printf("LAB1 sudah terpakai.\n");
		//mereset nilai dari ruang agar program meminta user untuk meminta input baru
		strcpy(ruang,"");
	}
	if (strcmp(ruang,"LAB2")==0 && kode2!=0){
		printf("LAB2 sudah terpakai.\n");
		//mereset nilai dari ruang agar program meminta user untuk meminta input baru
		strcpy(ruang,"");
	}
	if (strcmp(ruang,"LAB3")==0 && kode3!=0){
		printf("LAB3 sudah terpakai.\n");
		//mereset nilai dari ruang agar program meminta user untuk meminta input baru
		strcpy(ruang,"");
	}
	if (strcmp(ruang,"LSS")==0 && kode4!=0 && strcmp(kode,"EL2208")==0){
		printf("LSS sudah terpakai.\n");
		//mereset nilai dari ruang agar program meminta user untuk meminta input baru
		strcpy(ruang,"");
	}
	// pemberitahuan user LAB apa saja yang kosong
	printf("Ruangan yang masih kosong: ");
	if (kode1 == 0) {
		printf("LAB1;");
	}
	if (kode2 == 0) {
		printf("LAB2;");
	}
	if (kode3 == 0) {
		printf("LAB3;");
	}
	if (kode4 == 0 && strcmp(kode,"EL2208")==0) {
		printf("LSS");
	}
	printf("\n");
}

//pengisian jadwal eb2200
void jadwal_eb2200(jadwal_t (*R1)[5], jadwal_t (*R2)[5], jadwal_t (*R3)[5], jadwal_t (*R4)[5], char *romb,char *ruang,int *minggu, int*hari){
	char kode[6]="EB2200";
	char day[6]="";
	//INPUT ROMBONGAN
	while (strcmp(romb,"A")!=0 && strcmp(romb,"B")!=0){
		printf("Rombongan (A atau B): ");	
		scanf("%s",romb);
		if (strcmp(romb,"A")!=0 && strcmp(romb,"B")!=0){
			printf("ERROR!! EB2200 hanya terdiri atas rombongan A dan B\n");
		}
	}
	//INPUT MINGGU
	while ((*minggu<3 && *minggu>12) || isJadwal_exist(kode,R1,R2,R3,R4,romb,*minggu)==1) {
		printf("Minggu ke: ");	
		scanf("%d",minggu);
		if (*minggu<3 && *minggu>12){
			printf("ERROR!! Praktikum hanya boleh dilaksanakan pada minggu 3-12\n");
		} else if (isJadwal_exist(kode,R1,R2,R3,R4,romb,*minggu)==1){
			printf("ERROR!! Terdapat Rombongan yang sama pada minggu %d\n",*minggu);
		}
	}
	//INPUT HARI
	while (strcmp(day,"Selasa")!=0 && strcmp(day,"Kamis")!=0){
		printf("Hari: ");
		scanf("%s",day);
		if (strcmp(day,"Selasa")!=0 && strcmp(day,"Kamis")!=0){
			printf("ERROR!! Praktikum hanya boleh dilaksanakan pada hari 'Selasa' dan 'Kamis'\n");
		} else {
			*hari = strToInt_hari(day);
		}
	}
	//Validasi apakah hari tersebut terdapat ruang kosong
	if (isRuang_kosong(R1,R2,R3,R4,kode,*minggu,*hari)==0){ // tidak ada ruang kosong
		printf("Semua ruangan pada minggu %d hari %s penuh.\n", minggu, intToStr_hari(*hari));
		return; // kembali mengisi kode_praktikum dari awal
	}
	//INPUT RUANGAN
	while (strcmp(ruang,"LAB1")!=0 && strcmp(ruang,"LAB2")!=0 && strcmp(ruang,"LAB3")!=0){
		printf("Ruangan: ");
		scanf("%s",ruang);
		ruang_kosong(R1,R2,R3,R4,kode,ruang,*minggu,*hari);
	}
}

//pengisian jadwal el2208
void jadwal_el2208(jadwal_t (*R1)[5], jadwal_t (*R2)[5], jadwal_t (*R3)[5], jadwal_t (*R4)[5], char *romb,char *ruang,int *minggu, int*hari){
	char kode[6]="EL2208";
	char day[6]="";
	//INPUT ROMBONGAN
	while (strcmp(romb,"A")!=0 && strcmp(romb,"B")!=0 && strcmp(romb,"C")!=0 && strcmp(romb,"A1")!=0 && strcmp(romb,"A2")!=0 && strcmp(romb,"A3")!=0 && strcmp(romb,"B1")!=0 && strcmp(romb,"B2")!=0 && strcmp(romb,"B3")!=0){
		printf("Rombongan (A1, A2, A3, B1, B2, B3, atau C): ");	
		scanf("%s",romb);
		if (strcmp(romb,"A")!=0 && strcmp(romb,"B")!=0 && strcmp(romb,"C")!=0 && strcmp(romb,"A1")!=0 && strcmp(romb,"A2")!=0 && strcmp(romb,"A3")!=0 && strcmp(romb,"B1")!=0 && strcmp(romb,"B2")!=0 && strcmp(romb,"B3")!=0){
			printf("ERROR!! EL2208 hanya terdiri atas rombongan (A1, A2, A3, B1, B2, B3, dan C).\n");
		}
	}
	//INPUT MINGGU
	while ((*minggu<3 && *minggu>12) || isJadwal_exist(kode,R1,R2,R3,R4,romb,*minggu)==1) {
		printf("Minggu ke: ");	
		scanf("%d",&minggu);
		if (*minggu<3 && *minggu>12){
			printf("ERROR!! Praktikum hanya boleh dilaksanakan pada minggu 3-12\n");
		} else if (isJadwal_exist(kode,R1,R2,R3,R4,romb,*minggu)==1){
			printf("ERROR!! Terdapat Rombongan yang sama pada minggu %d\n",minggu);
		}
	}
	//INPUT HARI
	while (strcmp(day,"Senin")!=0 && strcmp(day,"Selasa")!=0 && strcmp(day,"Rabu")!=0 && strcmp(day,"Kamis")!=0 && strcmp(day,"Jumat")!=0){
		printf("Hari: ");
		scanf("%s",day);
		if (strcmp(day,"Senin")!=0 && strcmp(day,"Selasa")!=0 && strcmp(day,"Rabu")!=0 && strcmp(day,"Kamis")!=0 && strcmp(day,"Jumat")!=0){
			printf("ERROR!! Praktikum hanya boleh dilaksanakan pada hari 'Senin', 'Selasa', 'Rabu', 'Kamis', dan 'Jumat'\n");
		} else {
			*hari = strToInt_hari(day);
		}
	}
	//Validasi apakah ada EL2205 pada hari itu untuk rombongan A dan B EL2208
	if (strcmp(romb,"A")==0 || strcmp(romb,"B")==0 || strcmp(romb,"A1")==0 || strcmp(romb,"A2")==0 || strcmp(romb,"A3")==0 || strcmp(romb,"B1")==0 || strcmp(romb,"B2")==0 || strcmp(romb,"B3")==0){
		if (strcmp(R1[(*minggu)-1][(*hari)-1].kode_praktikum,"EL2205")==0 || strcmp(R2[(*minggu)-1][(*hari)-1].kode_praktikum,"EL2205")==0 || strcmp(R3[(*minggu)-1][(*hari)-1].kode_praktikum,"EL2205")==0 || strcmp(R4[(*minggu)-1][(*hari)-1].kode_praktikum,"EL2205")==0){
			return;
		}
	}
	//Validasi apakah hari tersebut terdapat satu ruang kosong
	if (isRuang_kosong(R1,R2,R3,R4,kode,*minggu,*hari)==0){ // tidak ada ruang kosong
		printf("Semua ruangan pada minggu %d hari %s penuh.\n", *minggu, intToStr_hari(*hari));
		return; // kembali mengisi kode_praktikum dari awal
	}
	//Validasi ruangan kosong apakah mencapai 3 buah untuk input rombongan 'A' atau 'B'
	if (strcmp(romb,"A")==0 || strcmp(romb,"B")==0){
		if (is3Ruang_kosong(R1,R2,R3,R4,kode,*minggu,*hari)==0){
			printf("Terdapat kurang dari 3 ruang kosong pada minggu %d hari %s.\n", *minggu, intToStr_hari(*hari));
			return;
		}
	}
	//INPUT RUANGAN
	// Input 3 ruangan
	if (strcmp(romb,"A")==0 || strcmp(romb,"B")==0){
		for (int i = 0; i < 3; ++i) {
			while (strcmp(ruang,"LAB1")!=0 && strcmp(ruang,"LAB2")!=0 && strcmp(ruang,"LAB3")!=0 && strcmp(ruang,"LSS")!=0){
				printf("Ruangan: ");
				scanf("%s",ruang);
				ruang_kosong(R1,R2,R3,R4,kode,ruang,*minggu,*hari);
			}
		}
	// Input 1 ruangan
	} else if (strcmp(romb,"C")==0 || strcmp(romb,"A1")==0 || strcmp(romb,"A2")==0 || strcmp(romb,"A3")==0 || strcmp(romb,"B1")==0 || strcmp(romb,"B2")==0 || strcmp(romb,"B3")==0){
		while (strcmp(ruang,"LAB1")!=0 && strcmp(ruang,"LAB2")!=0 && strcmp(ruang,"LAB3")!=0 && strcmp(ruang,"LSS")!=0){
			printf("Ruangan: ");
			scanf("%s",ruang);
			ruang_kosong(R1,R2,R3,R4,kode,ruang,*minggu,*hari);
		}
	}
}

//pengisian jadwal el2205
void jadwal_el2205(jadwal_t (*R1)[5], jadwal_t (*R2)[5], jadwal_t (*R3)[5], jadwal_t (*R4)[5], char *romb,char *ruang,int *minggu, int*hari){
	char kode[6]="EL2205";
	char day[6]="";
	//INPUT ROMBONGAN
	while (strcmp(romb,"C1")!=0 && strcmp(romb,"C2")!=0 && strcmp(romb,"A1")!=0 && strcmp(romb,"A2")!=0 && strcmp(romb,"B1")!=0 && strcmp(romb,"B2")!=0 && strcmp(romb,"A")!=0 && strcmp(romb,"B")!=0 && strcmp(romb,"C")!=0){
		printf("Rombongan (A1, A2, B1, B2, C1, atau C2): ");	
		scanf("%s",romb);
		if (strcmp(romb,"A")!=0 && strcmp(romb,"B")!=0 && strcmp(romb,"C")!=0 && strcmp(romb,"A1")!=0 && strcmp(romb,"A2")!=0 && strcmp(romb,"B1")!=0 && strcmp(romb,"B2")!=0 && strcmp(romb,"C1")!=0 && strcmp(romb,"C2")!=0){
			printf("ERROR!! EL2205 hanya terdiri atas rombongan (A1, A2, B1, B2, C1, atau C2).\n");
		}
	}
	//INPUT MINGGU
	while ((*minggu<3 && *minggu>12) || isJadwal_exist(kode,R1,R2,R3,R4,romb,*minggu)==1) {
		printf("Minggu ke: ");	
		scanf("%d",&minggu);
		if (*minggu<3 && *minggu>12){
			printf("ERROR!! Praktikum hanya boleh dilaksanakan pada minggu 3-12\n");
		} else if (isJadwal_exist(kode,R1,R2,R3,R4,romb,*minggu)==1){
			printf("ERROR!! Terdapat Rombongan yang sama pada minggu %d\n",minggu);
		}
	}
	//INPUT HARI
	while (strcmp(day,"Senin")!=0 && strcmp(day,"Selasa")!=0 && strcmp(day,"Rabu")!=0 && strcmp(day,"Kamis")!=0 && strcmp(day,"Jumat")!=0){
		printf("Hari: ");
		scanf("%s",day);
		if (strcmp(day,"Senin")!=0 && strcmp(day,"Selasa")!=0 && strcmp(day,"Rabu")!=0 && strcmp(day,"Kamis")!=0 && strcmp(day,"Jumat")!=0){
			printf("ERROR!! Praktikum hanya boleh dilaksanakan pada hari 'Senin', 'Selasa', 'Rabu', 'Kamis', dan 'Jumat'\n");
		} else {
			*hari = strToInt_hari(day);
		}
	}
	//Validasi apakah ada EL2208(selain romb C) pada hari itu (strcmp rombongan lain dengan "C" menghasilkan nilai -1)
	if ((strcmp(R1[(*minggu)-1][(*hari)-1].rombongan,"C")==-1 && strcmp(R1[(*minggu)-1][(*hari)-1].kode_praktikum,"EL2208")==0)||(strcmp(R2[(*minggu)-1][(*hari)-1].rombongan,"C")==-1 && strcmp(R2[(*minggu)-1][(*hari)-1].kode_praktikum,"EL2208")==0)||(strcmp(R3[(*minggu)-1][(*hari)-1].rombongan,"C")==-1 && strcmp(R3[(*minggu)-1][(*hari)-1].kode_praktikum,"EL2208")==0)){
		return;
	}
	//Validasi apakah hari tersebut terdapat satu ruang kosong
	if (isRuang_kosong(R1,R2,R3,R4,kode,*minggu,*hari)==0){ // tidak ada ruang kosong
		printf("Semua ruangan pada minggu %d hari %s penuh.\n", *minggu, intToStr_hari(*hari));
		return; // kembali mengisi kode_praktikum dari awal
	}
	//Validasi ruangan kosong apakah mencapai 2 buah untuk input rombongan 'A' atau 'B'
	if (strcmp(romb,"A")==0 || strcmp(romb,"B")==0){
		if (is3Ruang_kosong(R1,R2,R3,R4,kode,*minggu,*hari)==0){
			printf("Terdapat kurang dari 2 ruang kosong pada minggu %d hari %s.\n", *minggu, intToStr_hari(*hari));
			return;
		}
	}
	//INPUT RUANGAN
	// Input 2 ruangan
	if (strcmp(romb,"A")==0 || strcmp(romb,"B")==0 || strcmp(romb,"C")==0){
		for (int i = 0; i < 2; ++i) {
			while (strcmp(ruang,"LAB1")!=0 && strcmp(ruang,"LAB2")!=0 && strcmp(ruang,"LAB3")!=0){
				printf("Ruangan: ");
				scanf("%s",ruang);
				ruang_kosong(R1,R2,R3,R4,kode,ruang,*minggu,*hari);
			}
		}
	// Input 1 ruangan
	} else if (strcmp(romb,"A1")==0 || strcmp(romb,"A2")==0 || strcmp(romb,"B1")==0 || strcmp(romb,"B2")==0 || strcmp(romb,"C1")==0 || strcmp(romb,"C2")==0){
		while (strcmp(ruang,"LAB1")!=0 && strcmp(ruang,"LAB2")!=0 && strcmp(ruang,"LAB3")!=0){
			printf("Ruangan: ");
			scanf("%s",ruang);
			ruang_kosong(R1,R2,R3,R4,kode,ruang,*minggu,*hari);
		}
	}
}

void jadwal_prak(jadwal_t (*LAB1)[5], jadwal_t (*LAB2)[5], jadwal_t (*LAB3)[5], jadwal_t (*LSS)[5]){
	//asumsi pada semua elemen [minggu][hari] LAB1, LAB2, LAB3, LSS sudah terinisialisasi ""
	char kode_temp[6]="";
	char romb_temp[2]="";
	char ruang_temp[4]="";
	int minggu_temp=0;
	int hari_temp=0;

	printf("Isi `q` atau `Q` untuk kembali ke menu\n");
	while ((strcmp(kode_temp,"q")!=0 || strcmp(kode_temp,"Q")!=0) && strcmp(kode_temp,"EB2200")==0 && strcmp(kode_temp,"EL2208")==0 && strcmp(kode_temp,"EL2205")==0)
		printf("Pilih Kode Praktikum (EL2205, EL2208, EB2200): ");
		scanf("%s",kode_temp);
		if (strcmp(kode_temp,"EB2200")==0) {
			//panggil fungsi eb2200
			jadwal_eb2200(LAB1,LAB2,LAB3,LSS,romb_temp,ruang_temp,&minggu_temp,&hari_temp);
		} else if (strcmp(kode_temp,"EL2208")==0) {
			//panggil fungsi el2208
			jadwal_el2208(LAB1,LAB2,LAB3,LSS,romb_temp,ruang_temp,&minggu_temp,&hari_temp);
		} else if (strcmp(kode_temp,"EL2205")==0) {
			//panggil fungsi el2205
			jadwal_el2205(LAB1,LAB2,LAB3,LSS,romb_temp,ruang_temp,&minggu_temp,&hari_temp);
		} else if (strcmp(kode_temp,"q")==0 || strcmp(kode_temp,"Q")==0) {
			//keluar dari prosedur jadwal_prak
			return;
		} else {
			printf("Kode praktikum yang dipilih tidak sesuai\n");
		}
		//MENGISI DATA KEDALAM PENNYIMPANAN (ARRAY)
		if (strcmp(ruang_temp,"LAB1")==0) {
			strcpy(LAB1[minggu_temp-1][hari_temp-1].kode_praktikum,kode_temp);
			strcpy(LAB1[minggu_temp-1][hari_temp-1].rombongan,romb_temp);
		} else if (strcmp(ruang_temp,"LAB2")==0) {
			strcpy(LAB2[minggu_temp-1][hari_temp-1].kode_praktikum,kode_temp);
			strcpy(LAB2[minggu_temp-1][hari_temp-1].rombongan,romb_temp);
		} else if (strcmp(ruang_temp,"LAB3")==0) {
			strcpy(LAB3[minggu_temp-1][hari_temp-1].kode_praktikum,kode_temp);
			strcpy(LAB3[minggu_temp-1][hari_temp-1].rombongan,romb_temp);
		} else if (strcmp(ruang_temp,"LSS")==0) {
			strcpy(LSS[minggu_temp-1][hari_temp-1].kode_praktikum,kode_temp);
			strcpy(LSS[minggu_temp-1][hari_temp-1].rombongan,romb_temp);
		} 
	}
}

int main(){
	return 0;
}