//***********************************************************//
// [ Source Code ]
//
// Institution : Institut Teknologi Bandung
// Name : David Khowanto
// File Name : schedulemanual.c
// Dependency : schedulemanual.h
//
// 
/* Description:
Semua Prosedur dan Fungsi dalam file schedulemanual.c hanya digunakan untuk
prosedur [MODE SCHEDULE] atau pengisian schedule secara manual oleh user.
Validasi dan syarat-syarat sesuai dengan yang tertera pada Tugas_Besar_versi_final.pdf
-Tidak ada asumsi yang diambil sendiri oleh programmer
-Tidak ada syarat dari soal yang di skip programmer

Status:
1. David Khowanto - 13217056 : Create the file, fix all bug,
							   and test all possibilities according
							   to description in the pdf file
*/
//***********************************************************//
#include "schedulemanual.h"

//pengecekan apakah rombongan dengan kode praktikum tersebut sudah terdaftar pada minggu tersebut
int isJadwal_exist(char kode[7], jadwal_t (*R1)[5], jadwal_t (*R2)[5], jadwal_t (*R3)[5], jadwal_t (*R4)[5], char *romb, int minggu){
	char *p,*q,*r,*s;
	char *a,*b,*c,*d;
	int exist1, exist2, exist3, exist4;
	for (int hari = 1; hari < 6; ++hari) {
		p=R1[minggu-3][hari-1].kode_praktikum;
		q=R2[minggu-3][hari-1].kode_praktikum;
		r=R3[minggu-3][hari-1].kode_praktikum;
		s=R4[minggu-3][hari-1].kode_praktikum;
		a=R1[minggu-3][hari-1].rombongan;
		b=R2[minggu-3][hari-1].rombongan;
		c=R3[minggu-3][hari-1].rombongan;
		d=R4[minggu-3][hari-1].rombongan;
		exist1 = abs(strcmp(p,kode))+abs(strcmp(a,romb)); // jika p = kode dan a = romb, exist1 = 0 sehingga return 1 
		exist2 = abs(strcmp(q,kode))+abs(strcmp(b,romb)); // sehingga menandakan rombongan dengan kode praktikum tersebut sudah
		exist3 = abs(strcmp(r,kode))+abs(strcmp(c,romb)); // terdaftar pada minggu tersebut
		exist4 = abs(strcmp(s,kode))+abs(strcmp(d,romb));
		if (exist1==0 || exist2==0 || exist3==0 || exist4==0) {
			return 1;
		} else if (hari==5){
			return 0;
		}
	}
}

//konversi hari dari string menjadi integer
int strToInt_hari(char hari[7]){
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

//validasi apakah terdapat tiga atau dua ruang kosong di hari itu tergantung kode praktikum
int is3Ruang_kosong(jadwal_t (*R1)[5], jadwal_t (*R2)[5], jadwal_t (*R3)[5], jadwal_t (*R4)[5],char *kode, int minggu, int hari){
	int kode1 = strcmp(R1[minggu-3][hari-1].kode_praktikum,""); //LAB1
	int kode2 = strcmp(R2[minggu-3][hari-1].kode_praktikum,""); //LAB2
	int kode3 = strcmp(R3[minggu-3][hari-1].kode_praktikum,"");	//LAB3
	int kode4 = strcmp(R4[minggu-3][hari-1].kode_praktikum,""); //LSS
	int count=0;
	// setiap kali ada ruang kosong, count bertambah, 
	// jika ada 2 atau lebih ruang yang terpakai, maka ruang kosong tidak cukup
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
	if (count>1){ 
		return 1; // jumlah ruang kosong >= 3 buah untuk EL2208 dan >= 2 buah untuk EL2205
	} else {
		return 0; // ruang kosong kurang dari 3 buah untuk EL2208 dan 2 buah untuk EL2205
	}
}

//validasi apakah terdapat satu ruang kosong di hari itu 
int isRuang_kosong(jadwal_t (*R1)[5], jadwal_t (*R2)[5], jadwal_t (*R3)[5], jadwal_t (*R4)[5],char *kode, int minggu, int hari){
	int kode1 = strcmp(R1[minggu-3][hari-1].kode_praktikum,""); //LAB1
	int kode2 = strcmp(R2[minggu-3][hari-1].kode_praktikum,""); //LAB2
	int kode3 = strcmp(R3[minggu-3][hari-1].kode_praktikum,""); //LAB3
	int kode4 = strcmp(R4[minggu-3][hari-1].kode_praktikum,""); //LSS
	// berlaku hanya untuk EL2208
	if (strcmp(kode,"EL2208")==0){ 
		// kode1=kode2=kode3=kode4 == 0 ketika semua ruang pada minggu dan hari tersebut tidak tersimpan kode praktikum 
		// 		(tidak ada jadwal praktikum)
		if (kode1 == 0 || kode2 == 0 || kode3 ==0 || kode4 == 0){
			return 1;
		} else {
			return 0;
		}
	// berlaku untuk EB2200 dan EL2205
	} else if (strcmp(kode,"EB2200")==0 || (strcmp(kode,"EL2205")==0)){
		// EL2205 dan EB2200 hanya dapat menggunakan LAB1,LAB2,LAB3
		if (kode1 == 0 || kode2 == 0 || kode3 ==0){ 
			return 1;
		} else {
			return 0;
		}
	}
}

// mengecek ruang yang dimasukkan apakah kosong atau terpakai
void ruang_kosong(jadwal_t (*R1)[5], jadwal_t (*R2)[5], jadwal_t (*R3)[5], jadwal_t (*R4)[5],char *kode, char *ruang, int minggu, int hari){
	int kode1 = strcmp(R1[minggu-3][hari-1].kode_praktikum,""); //LAB1
	int kode2 = strcmp(R2[minggu-3][hari-1].kode_praktikum,""); //LAB2
	int kode3 = strcmp(R3[minggu-3][hari-1].kode_praktikum,""); //LAB3
	int kode4 = strcmp(R4[minggu-3][hari-1].kode_praktikum,""); //LSS
	//pemberitahuan kpd user apakah ruang yang akan diisi sudah terisi atau belum
	//Prosedur strcpy(ruang,"") 
	//	digunakan untuk ereset nilai dari ruang agar program meminta user 
	//	untuk meminta input baru pada prosedur lain yang memanggil prosedur ini
	if (strcmp(ruang,"LAB1")==0 && kode1!=0){
		printf("LAB1 sudah terpakai.\n");
		strcpy(ruang,"");
	}
	if (strcmp(ruang,"LAB2")==0 && kode2!=0){
		printf("LAB2 sudah terpakai.\n");
		strcpy(ruang,"");
	}
	if (strcmp(ruang,"LAB3")==0 && kode3!=0){
		printf("LAB3 sudah terpakai.\n");
		strcpy(ruang,"");
	}
	if (strcmp(ruang,"LSS")==0 && kode4!=0 && strcmp(kode,"EL2208")==0){
		printf("LSS sudah terpakai.\n");
		strcpy(ruang,"");
	}
	// pemberitahuan user LAB apa saja yang kosong
	if (strcmp(ruang,"LAB1")!=0 && strcmp(ruang,"LAB2")!=0 && strcmp(ruang,"LAB3")!=0 && strcmp(ruang,"LSS")!=0){
		printf("Ruangan yang masih kosong: ");
		if (kode1 == 0) {
			printf("LAB1 ");
		}
		if (kode2 == 0) {
			printf("LAB2 ");
		}
		if (kode3 == 0) {
			printf("LAB3 ");
		}
		if (kode4 == 0 && strcmp(kode,"EL2208")==0) {
			printf("LSS");
		}
		printf("\n");
	}
}

//pengisian jadwal eb2200
void jadwal_eb2200(jadwal_t (*R1)[5], jadwal_t (*R2)[5], jadwal_t (*R3)[5], jadwal_t (*R4)[5], char *romb,char *ruang,int *minggu, int*hari){
	char kode[7]="EB2200";
	char day[7]="";
	//INPUT ROMBONGAN
	do {
		printf("Rombongan (A atau B): ");	
		scanf(" %s",romb);
		if (strcmp(romb,"A")!=0 && strcmp(romb,"B")!=0){
			printf("ERROR!! EB2200 hanya terdiri atas rombongan A dan B\n");
		}
	} while (strcmp(romb,"A")!=0 && strcmp(romb,"B")!=0);
	//INPUT MINGGU
	do {
		printf("Minggu ke: ");	
		scanf("%d",minggu);
		if (*minggu<3 || *minggu>12){
			printf("ERROR!! Praktikum hanya boleh dilaksanakan pada minggu 3-12\n");
		} 
		if (isJadwal_exist(kode,R1,R2,R3,R4,romb,*minggu)==1){
			printf("ERROR!! Terdapat Rombongan yang sama pada minggu %d\n",*minggu);
			return;
		}
	} while ((*minggu<3 || *minggu>12) || isJadwal_exist(kode,R1,R2,R3,R4,romb,*minggu)==1);
	//INPUT HARI
	do {
		printf("Hari: ");
		scanf("%s",day);
		if (strcmp(day,"Selasa")!=0 && strcmp(day,"Kamis")!=0){
			printf("ERROR!! Praktikum hanya boleh dilaksanakan pada hari 'Selasa' dan 'Kamis'\n");
		} else {
			//mengonversi hari dari string ke integer
			*hari = strToInt_hari(day);
		}
	} while (strcmp(day,"Selasa")!=0 && strcmp(day,"Kamis")!=0);
	
	//VALIDASI apakah hari tersebut terdapat ruang kosong
	if (isRuang_kosong(R1,R2,R3,R4,kode,*minggu,*hari)==0){ // tidak ada ruang kosong
		printf("Semua ruangan pada minggu %d hari %s penuh.\n", *minggu, intToStr_hari(*hari));
		return; // kembali mengisi kode_praktikum dari awal
	}

	//INPUT RUANGAN
	do{
		printf("Ruangan: ");
		scanf("%s",ruang);
		//memanggil fungsi untuk mengecek input ruang apakah sesuai dengan persyaratan
		ruang_kosong(R1,R2,R3,R4,kode,ruang,*minggu,*hari);
	} while (strcmp(ruang,"LAB1")!=0 && strcmp(ruang,"LAB2")!=0 && strcmp(ruang,"LAB3")!=0);
}

//pengisian jadwal el2208
void jadwal_el2208(jadwal_t (*R1)[5], jadwal_t (*R2)[5], jadwal_t (*R3)[5], jadwal_t (*R4)[5], char *romb,char ruang3[][5], char *ruang,int *minggu, int *hari){
	char kode[7]="EL2208";
	char day[7]="";
	//INPUT ROMBONGAN
	do {
		printf("Rombongan (A1, A2, A3, B1, B2, B3, atau C): ");	
		scanf("%s",romb);
		if (strcmp(romb,"A")!=0 && strcmp(romb,"B")!=0 && strcmp(romb,"C")!=0 && strcmp(romb,"A1")!=0 && strcmp(romb,"A2")!=0 && strcmp(romb,"A3")!=0 && strcmp(romb,"B1")!=0 && strcmp(romb,"B2")!=0 && strcmp(romb,"B3")!=0){
			printf("ERROR!! EL2208 hanya terdiri atas rombongan (A1, A2, A3, B1, B2, B3, dan C).\n");
		}
	} while (strcmp(romb,"A")!=0 && strcmp(romb,"B")!=0 && strcmp(romb,"C")!=0 && strcmp(romb,"A1")!=0 && strcmp(romb,"A2")!=0 && strcmp(romb,"A3")!=0 && strcmp(romb,"B1")!=0 && strcmp(romb,"B2")!=0 && strcmp(romb,"B3")!=0);
	//INPUT MINGGU
	do {
		printf("Minggu ke: ");	
		scanf("%d",minggu);
		if (*minggu<3 || *minggu>12){
			printf("ERROR!! Praktikum hanya boleh dilaksanakan pada minggu 3-12\n");
		} else {
			 // pengecekan untuk pengisian rombongan yang lebih dari 1 (romb==A atau romb==B)
			if (strcmp(romb,"A")==0){
				if (isJadwal_exist(kode,R1,R2,R3,R4,"A1",*minggu)==1 || isJadwal_exist(kode,R1,R2,R3,R4,"A2",*minggu)==1 || isJadwal_exist(kode,R1,R2,R3,R4,"A3",*minggu)==1){
					printf("ERROR!! Terdapat Rombongan yang sama pada minggu %d\n",*minggu);
					return;
				}
			}else if (strcmp(romb,"B")==0){
				if (isJadwal_exist(kode,R1,R2,R3,R4,"B1",*minggu)==1 || isJadwal_exist(kode,R1,R2,R3,R4,"B2",*minggu)==1 || isJadwal_exist(kode,R1,R2,R3,R4,"B3",*minggu)==1){
					printf("ERROR!! Terdapat Rombongan yang sama pada minggu %d\n",*minggu);
					return;
				}
			// pengecekan untuk pengisian rombongan yang hanya berjumlah 1
			}else { 
				if (isJadwal_exist(kode,R1,R2,R3,R4,romb,*minggu)==1){
					printf("ERROR!! Terdapat Rombongan yang sama pada minggu %d\n",*minggu);
					return;
				}
			}
		}
	} while ((*minggu<3 || *minggu>12) || (isJadwal_exist(kode,R1,R2,R3,R4,"B1",*minggu)==1 && isJadwal_exist(kode,R1,R2,R3,R4,"B2",*minggu)==1 && isJadwal_exist(kode,R1,R2,R3,R4,"B3",*minggu)==1 && isJadwal_exist(kode,R1,R2,R3,R4,"A1",*minggu)==1 && isJadwal_exist(kode,R1,R2,R3,R4,"A2",*minggu)==1 && isJadwal_exist(kode,R1,R2,R3,R4,"A3",*minggu)==1 && isJadwal_exist(kode,R1,R2,R3,R4,romb,*minggu)==1));
	//INPUT HARI
	do {
		printf("Hari: ");
		scanf("%s",day);
		if (strcmp(day,"Senin")!=0 && strcmp(day,"Selasa")!=0 && strcmp(day,"Rabu")!=0 && strcmp(day,"Kamis")!=0 && strcmp(day,"Jumat")!=0){
			printf("ERROR!! Praktikum hanya boleh dilaksanakan pada hari 'Senin', 'Selasa', 'Rabu', 'Kamis', dan 'Jumat'\n");
		} else {
			// mengonversi hari dari string menjadi integer
			*hari = strToInt_hari(day);
		}
	} while (strcmp(day,"Senin")!=0 && strcmp(day,"Selasa")!=0 && strcmp(day,"Rabu")!=0 && strcmp(day,"Kamis")!=0 && strcmp(day,"Jumat")!=0);
	
	//VALIDASI apakah ada EL2205 pada hari itu untuk rombongan A dan B EL2208
	if ((strcmp(romb,"C")!=0 && strcmp(R1[(*minggu)-3][(*hari)-1].kode_praktikum,"EL2205")==0)||(strcmp(romb,"C")!=0 && strcmp(R2[(*minggu)-3][(*hari)-1].kode_praktikum,"EL2205")==0)||(strcmp(romb,"C")!=0 && strcmp(R3[(*minggu)-3][(*hari)-1].kode_praktikum,"EL2205")==0)){
		printf("Praktikum EL2205(Rombongan A,B,C) tidak boleh dilaksanakan pada hari yang sama dengan EL2208(Rombongan A,B)!\n");
		return;
	}
	//VALIDASI ruangan kosong apakah mencapai 3 buah untuk input rombongan 'A' atau 'B'
	if (strcmp(romb,"A")==0 || strcmp(romb,"B")==0){
		if (is3Ruang_kosong(R1,R2,R3,R4,kode,*minggu,*hari)==0){
			printf("Terdapat kurang dari 3 ruang kosong pada minggu %d hari %s.\n", *minggu, intToStr_hari(*hari));
			return;
		}
	} else {
		//VALIDASI apakah hari tersebut terdapat satu ruang kosong
		if (isRuang_kosong(R1,R2,R3,R4,kode,*minggu,*hari)==0){ // tidak ada ruang kosong
			printf("Semua ruangan pada minggu %d hari %s penuh.\n", *minggu, intToStr_hari(*hari));
			return; // kembali mengisi kode_praktikum dari awal
		}
	}

	//INPUT RUANGAN
	// Input 3 ruangan
	char room[5]="";
	if (strcmp(romb,"A")==0 || strcmp(romb,"B")==0){
		for (int i = 0; i < 3; ++i) {
			do {
				do{
					//variabel disimpan dalam variabel sementara room
					// agar proses pengecekan input dapat dilaksanakan
					printf("Ruangan %d: ",i+1);
					scanf("%s",room);
					// validasi untuk input room yang tidak boleh sama dengan rombongan lainnya
					if (strcmp(ruang3[0],room)==0 || strcmp(ruang3[1],room)==0 || strcmp(ruang3[2],room)==0){
						printf("Ruangan yang diinput tidak boleh sama dengan sebelumnya\n");
					}
					//operasi validasi, bila salah room diassign "" dan iterasi diulangi lagi
					ruang_kosong(R1,R2,R3,R4,kode,room,*minggu,*hari);
				} while (strcmp(ruang3[0],room)==0 || strcmp(ruang3[1],room)==0 || strcmp(ruang3[2],room)==0);
				//memindahkan nilai room kedalam array sebagai ruangan inputan
				strcpy(ruang3[i],room);
			} while (strcmp(ruang3[i],"LAB1")!=0 && strcmp(ruang3[i],"LAB2")!=0 && strcmp(ruang3[i],"LAB3")!=0 && strcmp(ruang3[i],"LSS")!=0);
		}
	// Input 1 ruangan
	} else if (strcmp(romb,"C")==0 || strcmp(romb,"A1")==0 || strcmp(romb,"A2")==0 || strcmp(romb,"A3")==0 || strcmp(romb,"B1")==0 || strcmp(romb,"B2")==0 || strcmp(romb,"B3")==0){
		do {
			printf("Ruangan: ");
			scanf("%s",ruang);
			ruang_kosong(R1,R2,R3,R4,kode,ruang,*minggu,*hari);
		} while (strcmp(ruang,"LAB1")!=0 && strcmp(ruang,"LAB2")!=0 && strcmp(ruang,"LAB3")!=0 && strcmp(ruang,"LSS")!=0);
	}
}

//pengisian jadwal el2205
void jadwal_el2205(jadwal_t (*R1)[5], jadwal_t (*R2)[5], jadwal_t (*R3)[5], jadwal_t (*R4)[5], char *romb,char ruang2[][5],char *ruang,int *minggu, int*hari){
	char kode[7]="EL2205";
	char day[7]="";
	//INPUT ROMBONGAN
	do {
		printf("Rombongan (A1, A2, B1, B2, C1, atau C2): ");	
		scanf("%s",romb);
		if (strcmp(romb,"A")!=0 && strcmp(romb,"B")!=0 && strcmp(romb,"C")!=0 && strcmp(romb,"A1")!=0 && strcmp(romb,"A2")!=0 && strcmp(romb,"B1")!=0 && strcmp(romb,"B2")!=0 && strcmp(romb,"C1")!=0 && strcmp(romb,"C2")!=0){
			printf("ERROR!! EL2205 hanya terdiri atas rombongan (A1, A2, B1, B2, C1, atau C2).\n");
		}
	} while (strcmp(romb,"C1")!=0 && strcmp(romb,"C2")!=0 && strcmp(romb,"A1")!=0 && strcmp(romb,"A2")!=0 && strcmp(romb,"B1")!=0 && strcmp(romb,"B2")!=0 && strcmp(romb,"A")!=0 && strcmp(romb,"B")!=0 && strcmp(romb,"C")!=0);
	//INPUT MINGGU
	do {
		printf("Minggu ke: ");	
		scanf("%d",minggu);
		if (*minggu<3 || *minggu>12){
			printf("ERROR!! Praktikum hanya boleh dilaksanakan pada minggu 3-12\n");
		} else {
			// pengecekan untuk pengisian rombongan yang lebih dari 1 (romb==A/B/C)
			if (strcmp(romb,"A")==0){ 
				if (isJadwal_exist(kode,R1,R2,R3,R4,"A1",*minggu)==1 || isJadwal_exist(kode,R1,R2,R3,R4,"A2",*minggu)==1 ){
					printf("ERROR!! Terdapat Rombongan yang sama pada minggu %d\n",*minggu);
					return;
				}
			}else if (strcmp(romb,"B")==0){
				if (isJadwal_exist(kode,R1,R2,R3,R4,"B1",*minggu)==1 || isJadwal_exist(kode,R1,R2,R3,R4,"B2",*minggu)==1){
					printf("ERROR!! Terdapat Rombongan yang sama pada minggu %d\n",*minggu);
					return;
				}
			}else if (strcmp(romb,"C")==0){
				if (isJadwal_exist(kode,R1,R2,R3,R4,"C1",*minggu)==1 || isJadwal_exist(kode,R1,R2,R3,R4,"C2",*minggu)==1){
					printf("ERROR!! Terdapat Rombongan yang sama pada minggu %d\n",*minggu);
					return;
				}
			//pengecekan untuk pengisian rombongan yang berjumlah 1
			}else { 
				if (isJadwal_exist(kode,R1,R2,R3,R4,romb,*minggu)==1){
					printf("ERROR!! Terdapat Rombongan yang sama pada minggu %d\n",*minggu);
					return;
				}
			}
		}
	} while ((*minggu<3 || *minggu>12) || (isJadwal_exist(kode,R1,R2,R3,R4,"A1",*minggu)==1 && isJadwal_exist(kode,R1,R2,R3,R4,"A2",*minggu)==1 && isJadwal_exist(kode,R1,R2,R3,R4,"B1",*minggu)==1 && isJadwal_exist(kode,R1,R2,R3,R4,"B2",*minggu)==1 && isJadwal_exist(kode,R1,R2,R3,R4,"C1",*minggu)==1 && isJadwal_exist(kode,R1,R2,R3,R4,"C2",*minggu)==1 && isJadwal_exist(kode,R1,R2,R3,R4,romb,*minggu)==1));
	//INPUT HARI
	do {
		printf("Hari: ");
		scanf("%s",day);
		if (strcmp(day,"Senin")!=0 && strcmp(day,"Selasa")!=0 && strcmp(day,"Rabu")!=0 && strcmp(day,"Kamis")!=0 && strcmp(day,"Jumat")!=0){
			printf("ERROR!! Praktikum hanya boleh dilaksanakan pada hari 'Senin', 'Selasa', 'Rabu', 'Kamis', dan 'Jumat'\n");
		} else {
			*hari = strToInt_hari(day);
		}
	} while (strcmp(day,"Senin")!=0 && strcmp(day,"Selasa")!=0 && strcmp(day,"Rabu")!=0 && strcmp(day,"Kamis")!=0 && strcmp(day,"Jumat")!=0);
	
	//VALIDASI apakah ada EL2208(selain romb C) pada hari itu (strcmp rombongan lain dengan "C" menghasilkan nilai !=0)
	if ((strcmp(R1[(*minggu)-3][(*hari)-1].rombongan,"C")!=0 && strcmp(R1[(*minggu)-3][(*hari)-1].kode_praktikum,"EL2208")==0)||(strcmp(R2[(*minggu)-3][(*hari)-1].rombongan,"C")!=0 && strcmp(R2[(*minggu)-3][(*hari)-1].kode_praktikum,"EL2208")==0)||(strcmp(R3[(*minggu)-3][(*hari)-1].rombongan,"C")!=0 && strcmp(R3[(*minggu)-3][(*hari)-1].kode_praktikum,"EL2208")==0) || (strcmp(R4[(*minggu)-3][(*hari)-1].rombongan,"C")!=0 && strcmp(R4[(*minggu)-3][(*hari)-1].kode_praktikum,"EL2208")==0)){
		printf("Praktikum EL2205(Rombongan A,B,C) tidak boleh dilaksanakan pada hari yang sama dengan EL2208(Rombongan A,B)\n");
		return;
	}
	//VALIDASI ruangan kosong apakah mencapai 2 buah untuk input rombongan 'A' atau 'B'
	if (strcmp(romb,"A")==0 || strcmp(romb,"B")==0){
		if (is3Ruang_kosong(R1,R2,R3,R4,kode,*minggu,*hari)==0){	
			printf("Terdapat kurang dari 2 ruang kosong pada minggu %d hari %s.\n", *minggu, intToStr_hari(*hari));
			return;
		}
	} else {
		//Validasi apakah hari tersebut terdapat satu ruang kosong
		if (isRuang_kosong(R1,R2,R3,R4,kode,*minggu,*hari)==0){ // tidak ada ruang kosong
			printf("Semua ruangan pada minggu %d hari %s penuh.\n", *minggu, intToStr_hari(*hari));
			return;
		}
	}

	//INPUT RUANGAN
	// Input 2 ruangan
	char room[5]="";
	if (strcmp(romb,"A")==0 || strcmp(romb,"B")==0 || strcmp(romb,"C")==0){
		for (int i = 0; i < 2; ++i) {
			do {
				do{ 
					printf("Ruangan %d: ",i+1);
					scanf("%s",room);
					// validasi untuk input room yang tidak boleh sama dengan rombongan lainnya
					if (strcmp(ruang2[0],room)==0 || strcmp(ruang2[1],room)==0){
						printf("Ruangan yang diinput tidak boleh sama dengan sebelumnya\n");
					}
					//operasi validasi, bila salah room diassign "" dan iterasi diulangi lagi
					ruang_kosong(R1,R2,R3,R4,kode,room,*minggu,*hari);
				} while (strcmp(ruang2[0],room)==0 || strcmp(ruang2[1],room)==0);
				strcpy(ruang2[i],room);
			} while (strcmp(ruang2[i],"LAB1")!=0 && strcmp(ruang2[i],"LAB2")!=0 && strcmp(ruang2[i],"LAB3")!=0);
		}
	// Input 1 ruangan
	} else if (strcmp(romb,"A1")==0 || strcmp(romb,"A2")==0 || strcmp(romb,"B1")==0 || strcmp(romb,"B2")==0 || strcmp(romb,"C1")==0 || strcmp(romb,"C2")==0){
		do {
			printf("Ruangan: ");
			scanf("%s",ruang);
			ruang_kosong(R1,R2,R3,R4,kode,ruang,*minggu,*hari);
		} while (strcmp(ruang,"LAB1")!=0 && strcmp(ruang,"LAB2")!=0 && strcmp(ruang,"LAB3")!=0);
	}
}

// PROSEDUR PENGISIAN ARRAY
void save_array(jadwal_t (*LAB1)[5], jadwal_t (*LAB2)[5], jadwal_t (*LAB3)[5], jadwal_t (*LSS)[5], char *kode_temp,char *romb_temp,char ruang3_temp[][5],char *ruang_temp,int minggu_temp, int hari_temp){
	//Data disimpan hanya apabila semua variabel sementara terisi
	if (strcmp(romb_temp,"")!=0 || strcmp(ruang_temp,"")!=0 || strcmp(ruang3_temp[0],"")!=0 || strcmp(ruang3_temp[1],"")!=0 || strcmp(ruang3_temp[2],"")!=0 || minggu_temp!=0 || hari_temp!=0){
		//penyimpanan data untuk input rombongan > 1
		if ((strcmp(kode_temp,"EL2208")==0 && (strcmp(romb_temp,"A")==0 || strcmp(romb_temp,"B")==0)) || (strcmp(kode_temp,"EL2205")==0 && (strcmp(romb_temp,"A")==0 || strcmp(romb_temp,"B")==0 || strcmp(romb_temp,"C")==0))){
			// simpan data untuk kode praktikum EL2208
			if (strcmp(kode_temp,"EL2208")==0) {
				//iterasi 3 kali sebab terdapat 3 rombongan untuk diinput
				for (int i = 0; i < 3; ++i) {
					//Iterasi penyimpanan data untuk ruang LAB1
					if (strcmp(ruang3_temp[i],"LAB1")==0) {
						strcpy(LAB1[minggu_temp-3][hari_temp-1].kode_praktikum,kode_temp);
						if (i==0 && strcmp(romb_temp,"A")==0){
							strcpy(LAB1[minggu_temp-3][hari_temp-1].rombongan,"A1");
						} else if (i==1 && strcmp(romb_temp,"A")==0){
							strcpy(LAB1[minggu_temp-3][hari_temp-1].rombongan,"A2");
						} else if (i==2 && strcmp(romb_temp,"A")==0){
							strcpy(LAB1[minggu_temp-3][hari_temp-1].rombongan,"A3");
						} else if (i==0 && strcmp(romb_temp,"B")==0){
							strcpy(LAB1[minggu_temp-3][hari_temp-1].rombongan,"B1");
						} else if (i==1 && strcmp(romb_temp,"B")==0){
							strcpy(LAB1[minggu_temp-3][hari_temp-1].rombongan,"B2");
						} else if (i==2 && strcmp(romb_temp,"B")==0){
							strcpy(LAB1[minggu_temp-3][hari_temp-1].rombongan,"B3");
						}
					//Iterasi penyimpanan data untuk ruang LAB2
					} else if (strcmp(ruang3_temp[i],"LAB2")==0) {
						strcpy(LAB2[minggu_temp-3][hari_temp-1].kode_praktikum,kode_temp);
						if (i==0 && strcmp(romb_temp,"A")==0){
							strcpy(LAB2[minggu_temp-3][hari_temp-1].rombongan,"A1");
						} else if (i==1 && strcmp(romb_temp,"A")==0){
							strcpy(LAB2[minggu_temp-3][hari_temp-1].rombongan,"A2");
						} else if (i==2 && strcmp(romb_temp,"A")==0){
							strcpy(LAB2[minggu_temp-3][hari_temp-1].rombongan,"A3");
						} else if (i==0 && strcmp(romb_temp,"B")==0){
							strcpy(LAB2[minggu_temp-3][hari_temp-1].rombongan,"B1");
						} else if (i==1 && strcmp(romb_temp,"B")==0){
							strcpy(LAB2[minggu_temp-3][hari_temp-1].rombongan,"B2");
						} else if (i==2 && strcmp(romb_temp,"B")==0){
							strcpy(LAB2[minggu_temp-3][hari_temp-1].rombongan,"B3");
						}
					//Iterasi penyimpanan data untuk ruang LAB3
					} else if (strcmp(ruang3_temp[i],"LAB3")==0) {
						strcpy(LAB3[minggu_temp-3][hari_temp-1].kode_praktikum,kode_temp);
						if (i==0 && strcmp(romb_temp,"A")==0){
							strcpy(LAB3[minggu_temp-3][hari_temp-1].rombongan,"A1");
						} else if (i==1 && strcmp(romb_temp,"A")==0){
							strcpy(LAB3[minggu_temp-3][hari_temp-1].rombongan,"A2");
						} else if (i==2 && strcmp(romb_temp,"A")==0){
							strcpy(LAB3[minggu_temp-3][hari_temp-1].rombongan,"A3");
						} else if (i==0 && strcmp(romb_temp,"B")==0){
							strcpy(LAB3[minggu_temp-3][hari_temp-1].rombongan,"B1");
						} else if (i==1 && strcmp(romb_temp,"B")==0){
							strcpy(LAB3[minggu_temp-3][hari_temp-1].rombongan,"B2");
						} else if (i==2 && strcmp(romb_temp,"B")==0){
							strcpy(LAB3[minggu_temp-3][hari_temp-1].rombongan,"B3");
						}
					//Iterasi penyimpanan data untuk ruang LSS						
					} else if (strcmp(ruang3_temp[i],"LSS")==0) {
						strcpy(LSS[minggu_temp-3][hari_temp-1].kode_praktikum,kode_temp);
						if (i==0 && strcmp(romb_temp,"A")==0){
							strcpy(LSS[minggu_temp-3][hari_temp-1].rombongan,"A1");
						} else if (i==1 && strcmp(romb_temp,"A")==0){
							strcpy(LSS[minggu_temp-3][hari_temp-1].rombongan,"A2");
						} else if (i==2 && strcmp(romb_temp,"A")==0){
							strcpy(LSS[minggu_temp-3][hari_temp-1].rombongan,"A3");
						} else if (i==0 && strcmp(romb_temp,"B")==0){
							strcpy(LSS[minggu_temp-3][hari_temp-1].rombongan,"B1");
						} else if (i==1 && strcmp(romb_temp,"B")==0){
							strcpy(LSS[minggu_temp-3][hari_temp-1].rombongan,"B2");
						} else if (i==2 && strcmp(romb_temp,"B")==0){
							strcpy(LSS[minggu_temp-3][hari_temp-1].rombongan,"B3");
						}
					}
				}
			// simpan data untuk kode praktikum EL2205
			} else if (strcmp(kode_temp,"EL2205")==0) {
				//iterasi 2 kali sebab terdapat 2 rombongan untuk diinput
				for (int i = 0; i < 2; ++i) {
					//Iterasi penyimpanan data untuk ruang LAB1
					if (strcmp(ruang3_temp[i],"LAB1")==0) {
						strcpy(LAB1[minggu_temp-3][hari_temp-1].kode_praktikum,kode_temp);
						if (i==0 && strcmp(romb_temp,"A")==0){
							strcpy(LAB1[minggu_temp-3][hari_temp-1].rombongan,"A1");
						} else if (i==1 && strcmp(romb_temp,"A")==0){
							strcpy(LAB1[minggu_temp-3][hari_temp-1].rombongan,"A2");
						} else if (i==0 && strcmp(romb_temp,"B")==0){
							strcpy(LAB1[minggu_temp-3][hari_temp-1].rombongan,"B1");
						} else if (i==1 && strcmp(romb_temp,"B")==0){
							strcpy(LAB1[minggu_temp-3][hari_temp-1].rombongan,"B2");
						} else if (i==0 && strcmp(romb_temp,"C")==0){
							strcpy(LAB1[minggu_temp-3][hari_temp-1].rombongan,"C1");
						} else if (i==1 && strcmp(romb_temp,"C")==0){
							strcpy(LAB1[minggu_temp-3][hari_temp-1].rombongan,"C2");
						}
					//Iterasi penyimpanan data untuk ruang LAB2
					} else if (strcmp(ruang3_temp[i],"LAB2")==0) {
						strcpy(LAB2[minggu_temp-3][hari_temp-1].kode_praktikum,kode_temp);
						if (i==0 && strcmp(romb_temp,"A")==0){
							strcpy(LAB2[minggu_temp-3][hari_temp-1].rombongan,"A1");
						} else if (i==1 && strcmp(romb_temp,"A")==0){
							strcpy(LAB2[minggu_temp-3][hari_temp-1].rombongan,"A2");
						} else if (i==0 && strcmp(romb_temp,"B")==0){
							strcpy(LAB2[minggu_temp-3][hari_temp-1].rombongan,"B1");
						} else if (i==1 && strcmp(romb_temp,"B")==0){
							strcpy(LAB2[minggu_temp-3][hari_temp-1].rombongan,"B2");
						} else if (i==0 && strcmp(romb_temp,"C")==0){
							strcpy(LAB2[minggu_temp-3][hari_temp-1].rombongan,"C1");
						} else if (i==1 && strcmp(romb_temp,"C")==0){
							strcpy(LAB2[minggu_temp-3][hari_temp-1].rombongan,"C2");
						}
					//Iterasi penyimpanan data untuk ruang LAB3
					} else if (strcmp(ruang3_temp[i],"LAB3")==0) {
						strcpy(LAB3[minggu_temp-3][hari_temp-1].kode_praktikum,kode_temp);
						if (i==0 && strcmp(romb_temp,"A")==0){
							strcpy(LAB3[minggu_temp-3][hari_temp-1].rombongan,"A1");
						} else if (i==1 && strcmp(romb_temp,"A")==0){
							strcpy(LAB3[minggu_temp-3][hari_temp-1].rombongan,"A2");
						} else if (i==0 && strcmp(romb_temp,"B")==0){
							strcpy(LAB3[minggu_temp-3][hari_temp-1].rombongan,"B1");
						} else if (i==1 && strcmp(romb_temp,"B")==0){
							strcpy(LAB3[minggu_temp-3][hari_temp-1].rombongan,"B2");
						} else if (i==0 && strcmp(romb_temp,"C")==0){
							strcpy(LAB3[minggu_temp-3][hari_temp-1].rombongan,"C1");
						} else if (i==1 && strcmp(romb_temp,"C")==0){
							strcpy(LAB3[minggu_temp-3][hari_temp-1].rombongan,"C2");
						}
					} 
				}
			}
		//penyimpanan data untuk 1 rombongan
		} else {
			if (strcmp(ruang_temp,"LAB1")==0) {
				strcpy(LAB1[minggu_temp-3][hari_temp-1].kode_praktikum,kode_temp);
				strcpy(LAB1[minggu_temp-3][hari_temp-1].rombongan,romb_temp);
			} else if (strcmp(ruang_temp,"LAB2")==0) {
				strcpy(LAB2[minggu_temp-3][hari_temp-1].kode_praktikum,kode_temp);
				strcpy(LAB2[minggu_temp-3][hari_temp-1].rombongan,romb_temp);
			} else if (strcmp(ruang_temp,"LAB3")==0) {
				strcpy(LAB3[minggu_temp-3][hari_temp-1].kode_praktikum,kode_temp);
				strcpy(LAB3[minggu_temp-3][hari_temp-1].rombongan,romb_temp);
			} else if (strcmp(ruang_temp,"LSS")==0) {
				strcpy(LSS[minggu_temp-3][hari_temp-1].kode_praktikum,kode_temp);
				strcpy(LSS[minggu_temp-3][hari_temp-1].rombongan,romb_temp);
			} 
		}
	}
}

// P R O S E D U R   U T A M A   U N T U K   M O D E   S C H E D U L E
void jadwal_prak(jadwal_t (*LAB1)[5], jadwal_t (*LAB2)[5], jadwal_t (*LAB3)[5], jadwal_t (*LSS)[5]) {
	//asumsi pada semua elemen [minggu][hari] LAB1, LAB2, LAB3, LSS sudah terinisialisasi "" pada main()
	char kode_temp[7]=""; //variabel sementara untuk menyimpan nilai kode praktikum yang diinput
	//semua variabel sementara akan dimasukkan kedalam array data setelah semuanya tervalidasi
	printf("[Mode Schedule]\n");
	printf("Isi `q` atau `Q` untuk kembali ke menu");
	do {
		char romb_temp[3]=""; 	// variabel sementara untuk menyimpan nilai rombongan yang diinput
		char ruang_temp[5]="";	// variabel sementara untuk menyimpan nilai ruangan yang diinput
		char ruang3_temp[3][5]; // array sementara untuk menyimpan ruangan dengan input ruangan lebih dari 1
		int minggu_temp=0; 		// variabel sementara untuk menyimpan nilai minggu yang diinput
		int hari_temp=0;		// variabel sementara untuk menyimpan nilai hari yang diinput
		// inisialisasi ruang3_temp sebagai "" agar mempermudah validasi pada prosedur jadwal_el2208 dan jadwal_el2205
		// validasi tersebut berperan ketika input ruangan dari user berjumlah lebih dari 3
		strcpy(ruang3_temp[0],""); strcpy(ruang3_temp[1],""),strcpy(ruang3_temp[2],"");
		printf("\nPilih Kode Praktikum (EL2205, EL2208, EB2200): ");
		scanf("%s",kode_temp);
		if (strcmp(kode_temp,"EB2200")==0) {
			//panggil fungsi eb2200
			jadwal_eb2200(LAB1,LAB2,LAB3,LSS,romb_temp,ruang_temp,&minggu_temp,&hari_temp);
		} else if (strcmp(kode_temp,"EL2208")==0) {
			//panggil fungsi el2208
			jadwal_el2208(LAB1,LAB2,LAB3,LSS,romb_temp,ruang3_temp,ruang_temp,&minggu_temp,&hari_temp);
		} else if (strcmp(kode_temp,"EL2205")==0) {
			//panggil fungsi el2205
			jadwal_el2205(LAB1,LAB2,LAB3,LSS,romb_temp,ruang3_temp,ruang_temp,&minggu_temp,&hari_temp);
		} else if (strcmp(kode_temp,"q")==0 || strcmp(kode_temp,"Q")==0) {
			//keluar dari prosedur jadwal_prak
			return;
		} else {
			printf("Kode praktikum yang dipilih tidak sesuai\n");
		}
		//MENGISI DATA KEDALAM PENNYIMPANAN (ARRAY)
		// menyimpan nilai dari variabel sementara ke dalam array data
		save_array(LAB1,LAB2,LAB3,LSS,kode_temp,romb_temp,ruang3_temp,ruang_temp,minggu_temp,hari_temp);
	} while ((strcmp(kode_temp,"q")!=0 || strcmp(kode_temp,"Q")!=0) || strcmp(kode_temp,"EB2200")==0 || strcmp(kode_temp,"EL2208")==0 || strcmp(kode_temp,"EL2205")==0);
}