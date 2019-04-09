//#include "assignasisten.h"
#include "save.h"

typedef struct {
	char kode_praktikum[10];
	char Rombongan[10];
	int count_asisten;
	char nama_asisten[3];

}jadwal_t;

jadwal_t LAB1[12][5],LAB2[12][5],LAB3[12][5],LSS[12][5];


int mode,num;
char filename[100],tamp;
void Menu_uta(/*int A*/)
{
			mode=0;
			while(mode!=8){
			printf ("[Menu Utama]\n");
			printf (" 1.Tampilkan Schedule\n");
			printf (" 2.Schedule Manual\n");
			printf (" 3.Tampilkan Status Assignment Asisten\n");
			printf (" 4.Assign Asisten Manual\n");
			//printf (" 5.Schedule Otomatis\n");
			//printf (" 6.Assign Otomatis\n");
			printf (" 7.Rule Checker\n");
			printf (" 8.Simpan proyek dan keluar\n");
			scanf("%d",&mode);
			if (mode==1){
				printf("aku\n");
			}
			else if (mode==2){
				printf("suka\n");
			}
			else if (mode==3){
				printf("cinta\n");
			}
//			else if (mode==4){
//				fungsiMainAssignAsisten();
//			}
			else if (mode==5||mode==6){
				printf("Maaf mode belum tersedia\n");
			}
			else if(mode==7){
				printf("dia the best\n");
			}
			}
			Simpan (filename);
			printf("Rombongan disimpan dalam berkas %s",filename);
			printf("_schedule.csv\n");
			printf("Asisten disimpan dalam berkas %s",filename);
			printf("_asisten.csv\n");
			}

void Menu(){
		num = 0;
		while(num!=3){
		printf ("Menu :\n");
		printf ("1.Buat Proyek Baru\t\n");
		printf ("2.Muat Proyek dari Berkas\t\n");
		printf ("3.Keluar\n");
		printf("Masukan: ");
		scanf ("%d",&num);
		if (num==1){
			printf("===== Membuat Proyek Baru =====\n");
			printf("Masukkan nama proyek: ");scanf("%s",filename);
			Menu_uta(/*mode*/);
		}
		else if (num==2){
			printf("===== Memuat Proyek dari Berkas =====\n");
			printf("Masukkan nama proyek: ");scanf("%s",filename);
			FILE *ftpr =fopen(filename,"r+");
			if (ftpr == NULL){
				printf ("File belum masih kosong");
			}
			//Read contents from file
			while (tamp!=EOF)
			{
				printf("%c",tamp);
			tamp = fgetc(ftpr);
			}
			Menu_uta(/*mode*/);
			fclose(ftpr);
		}	
		}

}

int main ()
{
	Menu();	
	return 0;
}
