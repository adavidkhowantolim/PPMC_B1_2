#include "save.h"

char* konv_string(int b){
	switch (b){
		case 1:
			return("Senin");
			break;
		case 2:
			return("Selasa");
			break;
		case 3:
			return("Rabu");
			break;
		case 4:
			return("Kamis");
			break;
		case 5:
			return("Jumat");
			break;
	}
}

void Simpan (char *filename,jadwal_t (*LAB1)[5], jadwal_t (*LAB2)[5], jadwal_t (*LAB3)[5], jadwal_t (*LSS)[5]){	
	int i,j;
	char* c = strtok(filename,"_");
	char* d=filename;
	char* file1 = strcat(d,"_schedule.csv");

	FILE *fin=fopen(file1,"w");
	
	fprintf(fin,"Ruang Praktikum, ,LAB1,LAB2,LAB3,LSS\n");
	fprintf(fin,"Minggu,Hari\n");
	for(i=0;i<10;i++){
		for(j=0;j<5;j++){
			fprintf(fin,"%d,%s,",i+3,konv_string(j+1));
			if (strcmp(LAB1[i][j].kode_praktikum,"")!=0){
				fprintf(fin," %s-%s,",LAB1[i][j].kode_praktikum,LAB1[i][j].Rombongan);	
			} else {
				fprintf(fin," ,");
			}
			if (strcmp(LAB2[i][j].kode_praktikum,"")!=0){
				fprintf(fin," %s-%s,",LAB2[i][j].kode_praktikum,LAB2[i][j].Rombongan);	
			} else {
				fprintf(fin," ,");
			}			
			if (strcmp(LAB3[i][j].kode_praktikum,"")!=0){
				fprintf(fin," %s-%s,",LAB3[i][j].kode_praktikum,LAB3[i][j].Rombongan);	
			} else {
				fprintf(fin," ,");
			}
			if (strcmp(LSS[i][j].kode_praktikum,"")!=0){
				fprintf(fin," %s-%s,",LSS[i][j].kode_praktikum,LSS[i][j].Rombongan);	
			} else {
				fprintf(fin," ,");
			}
				fprintf(fin,"\n");
		}
		
	}
	fclose(fin);

	c = strtok(filename,"_");
	char* file2 = strcat(c,"_asisten.csv");
	FILE *finn=fopen(file2,"w");
	fprintf(finn,"Ruang Praktikum, ,LAB1,LAB2,LAB3,LSS\n");
	fprintf(finn,"Minggu,Hari\n");
	for (i=0;i<10;i++){
		for(j=0;j<5;j++){	
			fprintf(finn,"%d,%s ,",i+3,konv_string(j+1));
			if (LAB1[i][j].count_asisten==0){
				fprintf(finn,", ");
			} else if (LAB1[i][j].count_asisten==1){
				fprintf(finn,"%1s, ",LAB1[i][j].nama_asisten);
			} else if (LAB1[i][j].count_asisten==2){
				fprintf(finn,"\"%3s\", ",LAB1[i][j].nama_asisten);			
			}
			
			if (LAB2[i][j].count_asisten==0){
				fprintf(finn,", ");
			} else if (LAB2[i][j].count_asisten==1){
				fprintf(finn,"%1s, ",LAB2[i][j].nama_asisten);
			} else if (LAB2[i][j].count_asisten==2){
				fprintf(finn,"\"%3s\", ",LAB2[i][j].nama_asisten);			
			}
				
			if (LAB3[i][j].count_asisten==0){
				fprintf(finn,", ");
			} else if (LAB3[i][j].count_asisten==1){
				fprintf(finn,"%1s, ",LAB3[i][j].nama_asisten);
			} else if (LAB3[i][j].count_asisten==2){
				fprintf(finn,"\"%3s\", ",LAB3[i][j].nama_asisten);			
			}
		
			if (LSS[i][j].count_asisten==0){
				fprintf(finn,", ");
			} else if (LSS[i][j].count_asisten==1){
				fprintf(finn,"%1s, ",LSS[i][j].nama_asisten);
			} else if (LSS[i][j].count_asisten==2){
				fprintf(finn,"\"%3s\", ",LSS[i][j].nama_asisten);			
			}
		fprintf(finn,"\n");			
		}
	}	
	fclose(finn);
}



