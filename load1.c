#include "load1.h"
#include "schedulemanual.h"

void load(char* filename,jadwal_t (*LAB1)[5], jadwal_t (*LAB2)[5], jadwal_t (*LAB3)[5], jadwal_t (*LSS)[5]){
	char temp[1000];
	strcpy(temp,filename);
	FILE* fin = fopen(strcat(temp,"_schedule.csv"),"r");
	for(int i=0;i<3;i++){
		fscanf(fin,"%s",temp);	
	}
	fscanf(fin,"%s",temp);
	for(int i=0;i<10;i++){
		for(int j=0;j<5;j++){
			fscanf(fin,"%s",temp);
			for(int k=0;k<4;k++){
				fscanf(fin,"%s",temp);
				if (k==0){
					if (strcmp(temp,",")==0){
						strcpy(LAB1[i][j].kode_praktikum,"\0");
					} else {
						for(int l=0;l<6;l++){
							LAB1[i][j].kode_praktikum[l]=temp[l];
						}
						LAB1[i][j].kode_praktikum[6]='\0';
						if (temp[8] == ','){
							LAB1[i][j].Rombongan[0]=temp[7];
						} else {
							for(int l=7;l<9;l++){
								LAB1[i][j].Rombongan[l-7]=temp[l];
							}
							LAB1[i][j].Rombongan[2]='\0';
						}
					}
				}
				if (k==1){
					if (strcmp(temp,",")==0){
						strcpy(LAB2[i][j].kode_praktikum,"\0");
					} else {
						for(int l=0;l<6;l++){
							LAB2[i][j].kode_praktikum[l]=temp[l];
						}
						LAB2[i][j].kode_praktikum[6]='\0';
						if (temp[8] == ','){
							LAB2[i][j].Rombongan[0]=temp[7];
						} else {
							for(int l=7;l<9;l++){
								LAB2[i][j].Rombongan[l-7]=temp[l];
							}
							LAB2[i][j].Rombongan[2]='\0';
						}
					}
				}
				if (k==2){
					if (strcmp(temp,",")==0){
						strcpy(LAB3[i][j].kode_praktikum,"\0");
					} else {
						for(int l=0;l<6;l++){
							LAB3[i][j].kode_praktikum[l]=temp[l];
						}
						LAB3[i][j].kode_praktikum[6]='\0';
						if (temp[8] == ','){
							LAB3[i][j].Rombongan[0]=temp[7];
						} else {
							for(int l=7;l<9;l++){
								LAB3[i][j].Rombongan[l-7]=temp[l];
							}
							LAB3[i][j].Rombongan[2]='\0';
						}
					}
				}
				if (k==3){
					if (strcmp(temp,",")==0){
						strcpy(LSS[i][j].kode_praktikum,"\0");
					} else {
						for(int l=0;l<6;l++){
							LSS[i][j].kode_praktikum[l]=temp[l];
						}
						LSS[i][j].kode_praktikum[6]='\0';
						if (temp[8] == ','){
							LSS[i][j].Rombongan[0]=temp[7];
						} else {
							for(int l=7;l<9;l++){
								LSS[i][j].Rombongan[l-7]=temp[l];
							}
							LSS[i][j].Rombongan[2]='\0';
						}
					}
				}
			}
		}
	}
	fclose(fin);
	strcpy(temp,filename);
	FILE* finn = fopen(strcat(temp,"_asisten.csv"),"r");
	for(int i=0;i<3;i++){
		fscanf(finn,"%s",temp);	
	}
	fscanf(finn,"%s",temp);
	for(int i=0;i<10;i++){
		for(int j=0;j<5;j++){
			fscanf(finn,"%s",temp);
			for(int k=0;k<4;k++){
				fscanf(finn,"%s",temp);
				if (k==0){
					if (temp[0]==','&&temp[1]==','){
						strcpy(LAB1[i][j].nama_asisten,"\0");
					} else {
						if (temp[1]=='"'){
							for(int l=2;l<5;l++){
								LAB1[i][j].nama_asisten[l-2]=temp[l];
							}
							LAB1[i][j].count_asisten=2;
							LAB1[i][j].nama_asisten[3]='\0';
						} else {
							LAB1[i][j].nama_asisten[0]=temp[1];
							LAB1[i][j].nama_asisten[1]='\0';
							LAB1[i][j].count_asisten=1;
						}
					}
				}
				if (k==1){
					if (strcmp(temp,",")==0){
						strcpy(LAB2[i][j].nama_asisten,"\0");
					} else {
						if (temp[0]=='"'){
							for(int l=1;l<4;l++){
								LAB2[i][j].nama_asisten[l-1]=temp[l];
							}
							LAB2[i][j].count_asisten=2;
							LAB2[i][j].nama_asisten[3]='\0';
						} else {
							LAB2[i][j].nama_asisten[0]=temp[0];
							LAB2[i][j].nama_asisten[1]='\0';
							LAB2[i][j].count_asisten=1;
						}
					}
				}
				if (k==2){
					if (strcmp(temp,",")==0){
						strcpy(LAB3[i][j].nama_asisten,"\0");
					} else {
						if (temp[0]=='"'){
							for(int l=1;l<4;l++){
								LAB3[i][j].nama_asisten[l-1]=temp[l];
							}
							LAB3[i][j].count_asisten=2;
							LAB3[i][j].nama_asisten[3]='\0';
						} else {
							LAB3[i][j].nama_asisten[0]=temp[0];
							LAB3[i][j].nama_asisten[1]='\0';
							LAB3[i][j].count_asisten=1;
						}
					}
				}
				if (k==3){
					if (strcmp(temp,",")==0){
						strcpy(LSS[i][j].nama_asisten,"\0");
					} else {
						if (temp[0]=='"'){
							for(int l=1;l<4;l++){
								LSS[i][j].nama_asisten[l-1]=temp[l];
							}
							LSS[i][j].count_asisten=2;
							LSS[i][j].nama_asisten[3]='\0';
						} else {
							LSS[i][j].nama_asisten[0]=temp[0];
							LSS[i][j].nama_asisten[1]='\0';
							LSS[i][j].count_asisten=1;
						}
					}
				}
			}
		}
	}
	fclose(finn);

}