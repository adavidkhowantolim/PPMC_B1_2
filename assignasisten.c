#include "assignasisten.h"
#include <stdio.h>
#include <string.h>

void assignAsisten(char *c){
	do{
		printf("Pilih Asisten (A-N): ");scanf(" %c",c);
		if (*c==113||*c==81){
			return;
		}
		if ((*c<65)||((*c>78)&&(*c<97))||(*c>110)){
			printf("Kode Asisten salah. Ulangi!\n");
		}
	} while ((*c<65)||((*c>78)&&(*c<97))||(*c>110));
}

void assignMinggu(int *m){
	do{
		printf("Minggu: ");scanf("%d",m);
		if ((*m<3)||(*m>12)){
			printf("Minggu harus berada pada rentang 3 hingga 12. Ulangi!\n");
		}
	} while ((*m<3)||(*m>12));
}

void assignHari(char *h){
	do{
		printf("Hari: ");scanf("%s",h);
		if (strcmp(h,"Senin")!=0&&strcmp(h,"Selasa")!=0&&strcmp(h,"Rabu")!=0&&strcmp(h,"Kamis")!=0&&strcmp(h,"Jumat")!=0){
			printf("Hari yang Anda masukkan harus pada hari kerja. Ulangi!\n");
		}
	} while (strcmp(h,"Senin")!=0&&strcmp(h,"Selasa")!=0&&strcmp(h,"Rabu")!=0&&strcmp(h,"Kamis")!=0&&strcmp(h,"Jumat")!=0);
}

void assignRuang(char *r){
	do{
		printf("Ruang: ");scanf("%s",r);
		if (strcmp(r,"LAB1")!=0&&strcmp(r,"LAB2")!=0&&strcmp(r,"LAB1")!=0&&strcmp(r,"LAB2")!=0){
			printf("Ruang yang Anda masukkan salah. Ulangi!\n");
		}
	} while(strcmp(r,"LAB1")!=0&&strcmp(r,"LAB2")!=0&&strcmp(r,"LAB1")!=0&&strcmp(r,"LAB2")!=0);
}

//konversi string menjadi integer
int konversiString(char* b){
	if (strcmp(b,"Senin")==0){
		return 1;
	} else
	if (strcmp(b,"Selasa")==0){
		return 2;
	} else
	if (strcmp(b,"Rabu")==0){
		return 3;
	} else
	if (strcmp(b,"Kamis")==0){
		return 4;
	} else
	if (strcmp(b,"Jumat")==0){
		return 5;
	} else
	if (strcmp(b,"EL2205")==0){
		return 1;
	} else
	if (strcmp(b,"EL2208")==0){
		return 2;
	} else
	if (strcmp(b,"EB2200")==0){
		return 3;
	} else
	{
		return 0;
	}
}

//assignment dari nilai praktikum dan hari yang berhalangan
void assignPrakHari(keterangan* a,char c){
	switch(c){
		case 'A' :
			strcpy(a->nama,"Amir");
			a->praktikum[0]=1;
			a->count_praktikum=1;
			a->hari_berhalangan[0]=3;
			a->count_hari_berhalangan=1;
			break;
		case 'B' :
			strcpy(a->nama,"Budi");
			a->praktikum[0]=1;
			a->count_praktikum=1;
			a->hari_berhalangan[0]=1;
			a->count_hari_berhalangan=1;
			break;
		case 'C' :
			strcpy(a->nama,"Cici");
			a->praktikum[0]=1;
			a->count_praktikum=1;
			a->hari_berhalangan[0]=2;
			a->hari_berhalangan[1]=3;
			a->count_hari_berhalangan=2;
			break;
		case 'D' :
			strcpy(a->nama,"Doni");
			a->praktikum[0]=1;
			a->count_praktikum=1;
			a->hari_berhalangan[0]=1;
			a->hari_berhalangan[1]=3;
			a->count_hari_berhalangan=2;
			break;
		case 'E' :
			strcpy(a->nama,"Endang");
			a->praktikum[0]=1;
			a->praktikum[1]=2;
			a->count_praktikum=2;
			a->hari_berhalangan[0]=0;
			a->count_hari_berhalangan=0;
			break;
		case 'F' :
			strcpy(a->nama,"Fadel");
			a->praktikum[0]=1;
			a->count_praktikum=2;
			a->hari_berhalangan[0]=2;
			a->count_hari_berhalangan=1;
			break;
		case 'G' :
			strcpy(a->nama,"Gilang");
			a->praktikum[0]=1;
			a->praktikum[1]=3;
			a->count_praktikum=2;
			a->hari_berhalangan[0]=4;
			a->count_hari_berhalangan=1;
			break;
		case 'H' :
			strcpy(a->nama,"Hero");
			a->praktikum[0]=3;
			a->count_praktikum=1;
			a->hari_berhalangan[0]=4;
			a->count_hari_berhalangan=1;
			break;
		case 'I' :
			strcpy(a->nama,"Intan");
			a->praktikum[0]=1;
			a->praktikum[1]=2;
			a->praktikum[2]=3;
			a->count_praktikum=3;
			a->hari_berhalangan[0]=3;
			a->count_hari_berhalangan=1;
			break;
		case 'J' :
			strcpy(a->nama,"Joko");
			a->praktikum[0]=3;
			a->count_praktikum=1;
			a->hari_berhalangan[0]=5;
			a->count_hari_berhalangan=1;
			break;
		case 'K' :
			strcpy(a->nama,"Kiki");
			a->praktikum[0]=2;
			a->praktikum[1]=3;
			a->count_praktikum=2;
			a->hari_berhalangan[0]=5;
			a->count_hari_berhalangan=1;
			break;
		case 'L' :
			strcpy(a->nama,"Luis");
			a->praktikum[0]=3;
			a->count_praktikum=1;
			a->hari_berhalangan[0]=0;
			a->count_hari_berhalangan=0;
			break;
		case 'M' :
			strcpy(a->nama,"Mini");
			a->praktikum[0]=3;
			a->count_praktikum=1;
			a->hari_berhalangan[0]=3;
			a->hari_berhalangan[1]=4;
			a->count_hari_berhalangan=2;
			break;
		case 'N' :
			strcpy(a->nama,"Nina");
			a->praktikum[0]=2;
			a->praktikum[1]=3;
			a->count_praktikum=2;
			a->hari_berhalangan[0]=2;
			a->count_hari_berhalangan=1;
			break;
	}
}

//konversi int ke kode praktikum
char* konversiKode(int k){
	if (k==1){
		return ("EL2205");
	} else 
	if (k==2){
		return ("EL2208");
	} else { //k==3
		return ("EB2200");
	}

}

int isEmptySchedule(jadwal_t (*ruang)[5],int m,int h){
	if (ruang[m-3][h-1].kode_praktikum==NULL){
		return(1);
	} else
	{
		return(0);
	}
}

//memvalidasi apakah asisten berhalangan untuk hadir di hari tsb
int isTidakBerhalangan(keterangan* a, int hari){
	int i;
	if (a->hari_berhalangan[0]==0){
		return 1;
	} else
	{
		for(i=0;i<(a->count_hari_berhalangan);i++){
			if(a->hari_berhalangan[i]==hari){ //jika hari tsb berhalangan
				return 0;
			}
		}
		//jika tidak ketemu hari yang berhalangan
		return 1;
	}
}

//memvalidasi apakah asisten tsb dapat melakukan praktikum tsb
int isSesuaiPraktikum(keterangan* a, int praktikum){
	int i;
	for(i=0;i<(a->count_praktikum);i++){
		if(a->praktikum[i]==praktikum){ //jika terdapat praktikum yang sesuai
			return 1;
		} 
	}
	//jika tidak sesuai dengan praktikum
	return 0;
}

void validasi(jadwal_t (*arr)[5],int m,int h,keterangan infoAsisten,char c){
	int found=0;
	/*validasi apakah pada hari minggu, hari dan lab yang diinput 
	ada pada array schedule terdapat praktikum*/
	if (!(isEmptySchedule(arr,m,h))){
	//if (!(isEmptySchedule(LAB1[m-1][konversiString(h)-1]))){
		//validasi apakah asisten praktikum dapat melakukan praktikum (tidak berhalangan)
		if(isTidakBerhalangan(&infoAsisten,h)){
			//validasi apakah asisten praktikum dapat melakukan praktikum (sesuai dengan praktikum yang dapat dilakukan)
			if(isSesuaiPraktikum(&infoAsisten,konversiString(arr[m-3][h-1].kode_praktikum))){
				//validasi apakah asisten praktikum sudah ada 2 di hari, minggu dan ruangan tsb
				if(arr[m-3][h-1].count_asisten==2){
					printf("Sudah terdapat 2 asisten.\n");
				} else {
					for(int j=0;j<(LAB1[m-3][h-1].count_asisten);j++){
						if (LAB1[m-3][h-1].nama_asisten[j]==c){
							found=1;
						}
					}
					for(int j=0;j<(LAB2[m-3][h-1].count_asisten);j++){
						if (LAB2[m-3][h-1].nama_asisten[j]==c){
							found=1;
						}
					}
					for(int j=0;j<(LAB3[m-3][h-1].count_asisten);j++){
						if (LAB3[m-3][h-1].nama_asisten[j]==c){
							found=1;
						}
					}
					for(int j=0;j<(LSS[m-3][h-1].count_asisten);j++){
						if (LSS[m-3][h-1].nama_asisten[j]==c){
							found=1;
						}
					}
					if(found==0){
					//save data ke dalam array
						if(arr[m-3][h-1].count_asisten==1){
							arr[m-3][h-1].nama_asisten[1]=',';
							arr[m-3][h-1].nama_asisten[2]=c;
						} else {
							arr[m-3][h-1].nama_asisten[0]=c;
						}
						arr[m-3][h-1].count_asisten++;
					} else { //found==1
						printf("Sudah terdapat asisten tersebut pada hari dan minggu tersebut.\n");
					}
				}
			} else {
				if (infoAsisten.count_praktikum==1){
					printf("Jadwal Asisten Praktikum %s tidak sesuai (tidak ada Rombongan %s)\n",infoAsisten.nama,konversiKode(infoAsisten.praktikum[0]));
				} else {
					//count_praktikum==2
					printf("Jadwal Asisten Praktikum %s tidak sesuai (tidak ada Rombongan %s dan %s)\n",infoAsisten.nama,konversiKode(infoAsisten.praktikum[0]),konversiKode(infoAsisten.praktikum[1]));	
				}
			}
		} else {
			printf("Asisten praktikum berhalangan hadir.\n");
		} 
	} else { 
		printf("Tidak ada jadwal praktikum.\n");
	}	
}

//fungsi utama assign asisten
void fungsiMainAssignAsisten(){
	char c;
	int m;
	keterangan infoAsisten;
	char h[10];
	char r[10];
	printf("[Mode Assign Asisten]\n");
	printf("Isi 'q' atau 'Q' untuk kembali ke menu\n");
	//input kode Asisten
	assignAsisten(&c);

	while (!(c=='q'||c=='Q')){
		//input minggu
		assignMinggu(&m);
		//input hari
		assignHari(h);
		//input ruang
		assignRuang(r);
		//assignment asisten praktikum
		assignPrakHari(&infoAsisten,c);

		jadwal_t temp;
		
		if (!(strcmp(r,"LAB1"))) {
			validasi(LAB1,m,konversiString(h),infoAsisten,c);
		} else if (!(strcmp(r,"LAB2"))){
			validasi(LAB2,m,konversiString(h),infoAsisten,c);
		} else if (!(strcmp(r,"LAB3"))){
			validasi(LAB3,m,konversiString(h),infoAsisten,c);
		} else if (!(strcmp(r,"LSS"))){
			validasi(LSS,m,konversiString(h),infoAsisten,c);
		}
		
		//input kode Asisten 
		assignAsisten(&c);
	}	
}
