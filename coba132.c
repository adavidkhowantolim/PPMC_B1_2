
//#include <stdio.h>
//#include <string.h>
#include "schedulemanual.h"
#include "assignasisten.h"
#include "load1.h"
#include "save.h"

#define MAXCHAR 1000

/*typedef struct {
	char kode_praktikum[7];
	char Rombongan[3];
	char nama_asisten[3];
} jadwal_t;*/

void scan_jadwal(jadwal_t *input);
void menu_utama(char *filename,jadwal_t (*LAB1)[5], jadwal_t (*LAB2)[5], jadwal_t (*LAB3)[5], jadwal_t (*LSS)[5]);

int main()
{
	int num;
	char filename[100];
	jadwal_t LAB1[10][5], LAB2[10][5], LAB3[10][5], LSS[10][5];

	/*for (int i=0; i<=10; i++){
		for (int j=0; j<=5; j++){
			strcpy(LAB1[i][j].kode_praktikum,"\0");strcpy(LAB1[i][j].Rombongan,"\0");strcpy(LAB1[i][j].nama_asisten,"\0");LAB1[i][j].count_asisten=0;
			strcpy(LAB2[i][j].kode_praktikum,"\0");strcpy(LAB2[i][j].Rombongan,"\0");strcpy(LAB2[i][j].nama_asisten,"\0");LAB2[i][j].count_asisten=0;
			strcpy(LAB3[i][j].kode_praktikum,"\0");strcpy(LAB3[i][j].Rombongan,"\0");strcpy(LAB3[i][j].nama_asisten,"\0");LAB3[i][j].count_asisten=0;
			strcpy(LSS[i][j].kode_praktikum,"\0");strcpy(LSS[i][j].Rombongan,"\0");strcpy(LSS[i][j].nama_asisten,"\0");LSS[i][j].count_asisten=0;
		}
	}*/

	do {
		for (int i=0; i<=10; i++){
			for (int j=0; j<=5; j++){
				strcpy(LAB1[i][j].kode_praktikum,"\0");strcpy(LAB1[i][j].Rombongan,"\0");strcpy(LAB1[i][j].nama_asisten,"\0");LAB1[i][j].count_asisten=0;
				strcpy(LAB2[i][j].kode_praktikum,"\0");strcpy(LAB2[i][j].Rombongan,"\0");strcpy(LAB2[i][j].nama_asisten,"\0");LAB2[i][j].count_asisten=0;
				strcpy(LAB3[i][j].kode_praktikum,"\0");strcpy(LAB3[i][j].Rombongan,"\0");strcpy(LAB3[i][j].nama_asisten,"\0");LAB3[i][j].count_asisten=0;
				strcpy(LSS[i][j].kode_praktikum,"\0");strcpy(LSS[i][j].Rombongan,"\0");strcpy(LSS[i][j].nama_asisten,"\0");LSS[i][j].count_asisten=0;
			}
		}
		printf ("Menu :\n");
		printf ("1.Buat Proyek Baru\t\n");
		printf ("2.Muat Proyek dari Berkas\t\n");
		printf ("3.Keluar\n");
		printf("Masukan: ");
		scanf ("%d",&num);
		if (num==1){
			printf("===== Membuat Proyek Baru =====\n");
			printf("Masukkan nama proyek: ");
			scanf("%s",filename);
			menu_utama(filename,LAB1,LAB2,LAB3,LSS);
		}
		else if (num==2){
			printf("Masukkan nama proyek: ");
			scanf("%s",filename);
			load(filename,LAB1,LAB2,LAB3,LSS);
			//Read contents from file
			menu_utama(filename,LAB1,LAB2,LAB3,LSS);
		}	
	} while(num!=3);
	return	0;
}

void menu_utama(char *filename,jadwal_t (*LAB1)[5], jadwal_t (*LAB2)[5], jadwal_t (*LAB3)[5], jadwal_t (*LSS)[5]) {
	int f=9;
	char rule[MAXCHAR];
	jadwal_t praktikum;
	char ruangan [10];
	int hari, minggu;
	while (f!=8){
		printf("{Menu Utama} \n");
		printf("Pilih Mode: \n");
		printf("    1. Tampilkan Schedule \n");
		printf("    2. Schedule Manual \n");
		printf("    3. Tampilkan Status Assignment Asisten \n");
		printf("    4. Assign Asisten Manual \n");
		printf("    5. Schedule Otomatis \n");
		printf("    6. Asisten Otomatis \n");
		printf("    7. Rule Chechker \n");
		printf("    8. Simpan Proyek dan Keluar \n");
		printf("Pilih Mode: ");
		
		scanf("%d", &f);
			
		
		if (f==1){
		
			printf("\n[Schedule Praktikum Sementara] \n");			
			printf("|---------------------------------------------------------------------------| \n");
			printf("|  Ruang Praktikum  |    LAB 1    |    LAB 2    |    LAB 3    |     LSS     | \n");
			printf("|-------------------|-------------|-------------|-------------|-------------| \n");
			printf("|  Minggu  |  Hari  |-------------|-------------|-------------|-------------| \n");
			
			for (int i=0; i<=9; i++){			
				printf("|----------|--------|-------------|-------------|-------------|-------------| \n");
	//print pada hari senin
				if (strcmp(LAB1[i][0].kode_praktikum,"")==0)
					printf("|    %2d    | Senin  |             |",i+3);
				else 
					printf("|    %2d    | Senin  | %6s - %2s |",i+3, LAB1[i][0].kode_praktikum, LAB1[i][0].Rombongan);
				if (strcmp(LAB2[i][0].kode_praktikum,"")==0)
					printf("             |");
				else
					printf(" %6s - %2s |",LAB2[i][0].kode_praktikum, LAB2[i][0].Rombongan);
				if (strcmp(LAB3[i][0].kode_praktikum,"")==0)
					printf("             |");
				else 
					printf(" %6s - %2s |",LAB3[i][0].kode_praktikum, LAB3[i][0].Rombongan);
				if (strcmp(LSS[i][0].kode_praktikum,"")==0)
					printf("             |\n");
				else
					printf(" %6s - %2s |\n",LSS[i][0].kode_praktikum, LSS[i][0].Rombongan);
	//Print pada hari selasa
				if (strcmp(LAB1[i][1].kode_praktikum,"")==0)
					printf("|    %2d    | Selasa |             |",i+3);
				else 
					printf("|    %2d    | Selasa | %6s - %2s |",i+3, LAB1[i][1].kode_praktikum, LAB1[i][1].Rombongan);
				if (strcmp(LAB2[i][1].kode_praktikum,"")==0)
					printf("             |");
				else
					printf(" %6s - %2s |",LAB2[i][1].kode_praktikum, LAB2[i][1].Rombongan);
				if (strcmp(LAB3[i][1].kode_praktikum,"")==0)
					printf("             |");
				else 
					printf(" %6s - %2s |",LAB3[i][1].kode_praktikum, LAB3[i][1].Rombongan);
				if (strcmp(LSS[i][1].kode_praktikum,"")==0)
					printf("             |\n");
				else
					printf(" %6s - %2s |\n",LSS[i][1].kode_praktikum, LSS[i][1].Rombongan);
	//print pada hari rabu
				if (strcmp(LAB1[i][2].kode_praktikum,"")==0)
					printf("|    %2d    | Rabu   |             |",i+3);
				else 
					printf("|    %2d    | Rabu   | %6s - %2s |",i+3, LAB1[i][2].kode_praktikum, LAB1[i][2].Rombongan);
				if (strcmp(LAB2[i][2].kode_praktikum,"")==0)
					printf("             |");
				else
					printf(" %6s - %2s |",LAB2[i][2].kode_praktikum, LAB2[i][2].Rombongan);
				if (strcmp(LAB3[i][2].kode_praktikum,"")==0)
					printf("             |");
				else 
					printf(" %6s - %2s |",LAB3[i][2].kode_praktikum, LAB3[i][2].Rombongan);
				if (strcmp(LSS[i][2].kode_praktikum,"")==0)
					printf("             |\n");
				else
					printf(" %6s - %2s |\n",LSS[i][2].kode_praktikum, LSS[i][2].Rombongan);
	//print pada hari kamis
				if (strcmp(LAB1[i][3].kode_praktikum,"")==0)
					printf("|    %2d    | Kamis  |             |",i+3);
				else 
					printf("|    %2d    | Kamis  | %6s - %2s |",i+3, LAB1[i][3].kode_praktikum, LAB1[i][3].Rombongan);
				if (strcmp(LAB2[i][3].kode_praktikum,"")==0)
					printf("             |");
				else
					printf(" %6s - %2s |",LAB2[i][3].kode_praktikum, LAB2[i][3].Rombongan);
				if (strcmp(LAB3[i][3].kode_praktikum,"")==0)
					printf("             |");
				else 
					printf(" %6s - %2s |",LAB3[i][3].kode_praktikum, LAB3[i][3].Rombongan);
				if (strcmp(LSS[i][3].kode_praktikum,"")==0)
					printf("             |\n");
				else
					printf(" %6s - %2s |\n",LSS[i][3].kode_praktikum, LSS[i][3].Rombongan);
	//print pada hari jumat
				if (strcmp(LAB1[i][4].kode_praktikum,"")==0)
					printf("|    %2d    | Jumat  |             |",i+3);
				else 
					printf("|    %2d    | Jumat  | %6s - %2s |",i+3, LAB1[i][4].kode_praktikum, LAB1[i][4].Rombongan);
				if (strcmp(LAB2[i][4].kode_praktikum,"")==0)
					printf("             |");
				else
					printf(" %6s - %2s |",LAB2[i][4].kode_praktikum, LAB2[i][4].Rombongan);
				if (strcmp(LAB3[i][4].kode_praktikum,"")==0)
					printf("             |");
				else 
					printf(" %6s - %2s |",LAB3[i][4].kode_praktikum, LAB3[i][4].Rombongan);
				if (strcmp(LSS[i][4].kode_praktikum,"")==0)
					printf("             |\n");
				else
					printf(" %6s - %2s |\n",LSS[i][4].kode_praktikum, LSS[i][4].Rombongan);
			}
			printf("|---------------------------------------------------------------------------| \n");
		}
		
		else if (f==2){	
			jadwal_prak (LAB1,LAB2,LAB3,LSS);
		}
			
		else if (f==3){
		
			printf("\n[Schedule Asisten Praktikum Sementara] \n");
			printf("|---------------------------------------------------------------------------| \n");
			printf("|  Ruang Praktikum  |    LAB 1    |    LAB 2    |    LAB 3    |     LSS     | \n");
			printf("|-------------------|-------------|-------------|-------------|-------------| \n");
			printf("|  Minggu  |  Hari  |-------------|-------------|-------------|-------------| \n");
			
			for (int i=0; i<=9; i++){			
				printf("|----------|--------|-------------|-------------|-------------|-------------| \n");		
			//print pada hari senin
				if (strcmp(LAB1[i][0].nama_asisten,"")==0)
					printf("|    %2d    | Senin  |             |",i+3);
				else 
					printf("|    %2d    | Senin  |     %3s     |",i+3, LAB1[i][0].nama_asisten);
				if (strcmp(LAB2[i][0].nama_asisten,"")==0)
					printf("             |");
				else
					printf("     %3s     |",LAB2[i][0].nama_asisten);
				if (strcmp(LAB3[i][0].nama_asisten,"")==0)
					printf("             |");
				else 
					printf("     %3s     |",LAB3[i][0].nama_asisten);
				if (strcmp(LSS[i][0].nama_asisten,"")==0)
					printf("             |\n");
				else
					printf("     %3s     |\n",LSS[i][0].nama_asisten);
			//print pada hari selasa
				if (strcmp(LAB1[i][1].nama_asisten,"")==0)
					printf("|    %2d    | Selasa |             |",i+3);
				else 
					printf("|    %2d    | Selasa |     %3s     |",i+3, LAB1[i][1].nama_asisten);
				if (strcmp(LAB2[i][1].nama_asisten,"")==0)
					printf("             |");
				else
					printf("     %3s     |",LAB2[i][1].nama_asisten);
				if (strcmp(LAB3[i][1].nama_asisten,"")==0)
					printf("             |");
				else 
					printf("     %3s     |",LAB3[i][1].nama_asisten);
				if (strcmp(LSS[i][1].nama_asisten,"")==0)
					printf("             |\n");
				else
					printf("     %3s     |\n",LSS[i][1].nama_asisten);
			//print pada hari Rabu
				if (strcmp(LAB1[i][2].nama_asisten,"")==0)
					printf("|    %2d    | Rabu   |             |",i+3);
				else 
					printf("|    %2d    | Rabu   |     %3s     |",i+3, LAB1[i][2].nama_asisten);
				if (strcmp(LAB2[i][2].nama_asisten,"")==0)
					printf("             |");
				else
					printf("     %3s     |",LAB2[i][2].nama_asisten);
				if (strcmp(LAB3[i][2].nama_asisten,"")==0)
					printf("             |");
				else 
					printf("     %3s     |",LAB3[i][2].nama_asisten);
				if (strcmp(LSS[i][2].nama_asisten,"")==0)
					printf("             |\n");
				else
					printf("     %3s     |\n",LSS[i][2].nama_asisten);
			//print pada hari Kamis
				if (strcmp(LAB1[i][3].nama_asisten,"")==0)
					printf("|    %2d    | Kamis  |             |",i+3);
				else 
					printf("|    %2d    | Kamis  |     %3s     |",i+3, LAB1[i][3].nama_asisten);
				if (strcmp(LAB2[i][3].nama_asisten,"")==0)
					printf("             |");
				else
					printf("     %3s     |",LAB2[i][3].nama_asisten);
				if (strcmp(LAB3[i][3].nama_asisten,"")==0)
					printf("             |");
				else 
					printf("     %3s     |",LAB3[i][3].nama_asisten);
				if (strcmp(LSS[i][3].nama_asisten,"")==0)
					printf("             |\n");
				else
					printf("     %3s     |\n",LSS[i][3].nama_asisten);
			//print pada hari Jumat
				if (strcmp(LAB1[i][4].nama_asisten,"")==0)
					printf("|    %2d    | Jumat  |             |",i+3);
				else 
					printf("|    %2d    | Jumat  |     %3s     |",i+3, LAB1[i][4].nama_asisten);
				if (strcmp(LAB2[i][4].nama_asisten,"")==0)
					printf("             |");
				else
					printf("     %3s     |",LAB2[i][4].nama_asisten);
				if (strcmp(LAB3[i][4].nama_asisten,"")==0)
					printf("             |");
				else 
					printf("     %3s     |",LAB3[i][4].nama_asisten);
				if (strcmp(LSS[i][4].nama_asisten,"")==0)
					printf("             |\n");
				else
					printf("     %3s     |\n",LSS[i][4].nama_asisten);	
			}
			printf("|---------------------------------------------------------------------------| \n");
		}
		else if (f==4){
				fungsiMainAssignAsisten(LAB1,LAB2,LAB3,LSS);
		}
		
		else if (f==5||f==6){
					printf("Maaf mode belum tersedia\n");
		}
		
		else if (f==7){
			printf("Mas1ukkan File DRC (dalam format .txt): ");
			scanf("%s", rule);
	
			FILE *checker;
				checker = fopen(rule, "r");
					
			if(checker == NULL){
				printf("File tidak tersedia! \n");
			}
			int count=0;
			while (fgets(rule, MAXCHAR, checker) != NULL)
				if (rule[0] =='['){
					if (rule[1]>48 && rule[1]<58)
						minggu = rule[1] - 51;
					if (rule[4]>48 && rule[4]<54){
						hari = rule[4] - 48;
						if (strcmp(LAB1[minggu][hari].kode_praktikum,"")==0 && strcmp(LAB2[minggu][hari].kode_praktikum,"")==0 && strcmp(LAB3[minggu][hari].kode_praktikum,"")==0 &&strcmp(LSS[minggu][hari].kode_praktikum,"")==0)
							count++;
						else {
							if (hari ==1)
								printf("Pada Minggu ke-%d, Hari Senin ada Libur Nasional\n",minggu+3);
							if (hari ==2)
								printf("Pada Minggu ke-%d, Hari Selasa ada Libur Nasional\n",minggu+3);
							if (hari ==3)
								printf("Pada Minggu ke-%d, Hari Rabu ada Libur Nasional\n",minggu+3);
							if (hari ==4)
								printf("Pada Minggu ke-%d, Hari Kamis ada Libur Nasional\n",minggu+3);
							if (hari ==5)
								printf("Pada Minggu ke-%d, Hari Jumat ada Libur Nasional\n",minggu+3);
						}
					}
					if (rule[4]=='h'){
						if (strcmp(LAB1[minggu][1].kode_praktikum,"")==0 && strcmp(LAB2[minggu][1].kode_praktikum,"")==0 && strcmp(LAB3[minggu][1].kode_praktikum,"")==0 &&strcmp(LSS[minggu][1].kode_praktikum,"")==0
						 && strcmp(LAB1[minggu][2].kode_praktikum,"")==0 && strcmp(LAB2[minggu][2].kode_praktikum,"")==0 && strcmp(LAB3[minggu][2].kode_praktikum,"")==0 &&strcmp(LSS[minggu][2].kode_praktikum,"")==0
						 && strcmp(LAB1[minggu][3].kode_praktikum,"")==0 && strcmp(LAB2[minggu][3].kode_praktikum,"")==0 && strcmp(LAB3[minggu][3].kode_praktikum,"")==0 &&strcmp(LSS[minggu][3].kode_praktikum,"")==0
						 && strcmp(LAB1[minggu][4].kode_praktikum,"")==0 && strcmp(LAB2[minggu][4].kode_praktikum,"")==0 && strcmp(LAB3[minggu][4].kode_praktikum,"")==0 &&strcmp(LSS[minggu][4].kode_praktikum,"")==0
						 && strcmp(LAB1[minggu][5].kode_praktikum,"")==0 && strcmp(LAB2[minggu][5].kode_praktikum,"")==0 && strcmp(LAB3[minggu][5].kode_praktikum,"")==0 &&strcmp(LSS[minggu][5].kode_praktikum,"")==0)
							count++;
						else
							printf("Pada Minggu ke-%d, Akan dilaksanakan UTS\n", minggu+3);
						}
				}
				printf("\n%d/3 Rule is Checked \n", count);
		}	
		printf("\n");
	}
	Simpan (filename,LAB1,LAB2,LAB3,LSS);
	printf("Rombongan disimpan dalam berkas %s\n",filename);
	printf("Asisten disimpan dalam berkas %s\n",filename);
	return;
}

void scan_jadwal(jadwal_t *input) {
	printf("Pilih Kode Praktikum (EL2205, EL2208, EB.2200): ");
	scanf("%s",input->kode_praktikum);
	printf("Rombongan: ");
	scanf("%s",input->Rombongan);
	printf("Asisten: ");
	scanf("%s",input->nama_asisten);
	  	
	}

