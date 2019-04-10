//***********************************************************//
// [ Source Code ]
//
// Institution : Institut Teknologi Bandung
// Name : David Khowanto, Louis, Elizabeth Kahny Dhea P.
// File Name : load.c
// Dependency : schedulemanual.h, load.h
//
// 
/* Description:
Program untuk membaca data dari file csv dan memindahkan ke array data

Status:
1. David Khowanto - 13217056 : Test and debugging
2. Louis - 13217072 : Test and debugging
3. Elizabeth K. Dhea  P.- 13217068 : create the program
*/
//***********************************************************//
#include "load.h"
#include "schedulemanual.h"

int baca_opsi(){
    int opsi_i;
    char opsi_c;
    printf("Masukan: ");
    scanf(" %c", &opsi_c);
    opsi_i=opsi_c-'0';
    return opsi_i;
}

void format_prog(char (*str)[MAX_STRLEN], jadwal_t (*LAB1)[5], jadwal_t (*LAB2)[5], jadwal_t (*LAB3)[5], jadwal_t (*LSS)[5]){
    char c='"';
    memset(array, 0, sizeof array);
    memset(temp, 0, sizeof temp);
    for(n=1; n<MAX_SIZE; n++){
        i=0; j=0;
        while (str[n][i]!='\n') {
            if((i==0) && (str[n][i]==',')) {
                temp[n][++j] = '0';
                temp[n][++j] = str[n][i];
            }
            if (((str[n][i]==',') && (str[n][i+1]==',')) || (str[n][i+1]=='\0')){
                temp[n][++j] = '0';
            }
            ++i;
        }
    }
    i=1; j=1; k=0;
    for(n=1; n<MAX_SIZE; n++){
        while(temp[n][i]=='\0'){
            if(temp[n][i]==c){
                ++i;
                array[n][j][k]=temp[n][i];
                ++k;
                while(temp[n][i+1]!=c){
                    ++i;
                    array[n][j][k]=temp[n][i];
                    ++k;
                }
                i=i+2; k=0;
            } else {
                if(temp[n][i]!=','){
                    array[n][j][k]=temp[n][i];
                    ++i; ++k;
                } else {
                    ++i; ++j; k=0;
                }
            }
        }
        i=1; j=1; k=0;
    }
    for(i=3; i<MAX_SIZE; i++){
    	for(j=3; j<7; j++){
		    if(strcmp(array[1][j],"LAB1")==0){
		    	m=array[i][1][0]-'3';
		    	if(strcmp(array[i][2],"Senin")==0){
		    		n=0;
				} else if(strcmp(array[i][2],"Selasa")==0){
		    		n=1;
		    	} else if(strcmp(array[i][2],"Rabu")==0){
		    		n=2;
		    	} else if(strcmp(array[i][2],"Kamis")==0){
		    		n=3;
		    	} else if(strcmp(array[i][2],"Jumat")==0){
		    		n=4;
		    	}
		    	strcpy(LAB1[m][n].nama_asisten,array[i][j]);
		    	if (LAB1[m][n].nama_asisten[2]==','){
		    		LAB1[m][n].count_asisten=2;
		    	} else {
		    		LAB1[m][n].count_asisten=1;
		    	}
			} else if(strcmp(array[1][j],"LAB2")==0){
		    	m=array[i][1][0]-'3';
		    	if(strcmp(array[i][2],"Senin")==0){
		    		n=0;
				} else if(strcmp(array[i][2],"Selasa")==0){
		    		n=1;
		    	} else if(strcmp(array[i][2],"Rabu")==0){
		    		n=2;
		    	} else if(strcmp(array[i][2],"Kamis")==0){
		    		n=3;
		    	} else if(strcmp(array[i][2],"Jumat")==0){
		    		n=4;
		    	}
		    	strcpy(LAB2[m][n].nama_asisten,array[i][j]);
		    	if (LAB2[m][n].nama_asisten[2]==','){
		    		LAB2[m][n].count_asisten=2;
		    	} else {
		    		LAB2[m][n].count_asisten=1;
		    	}
			} else if(strcmp(array[1][j],"LAB3")==0){
		    	m=array[i][1][0]-'3';
		    	if(strcmp(array[i][2],"Senin")==0){
		    		n=0;
				} else if(strcmp(array[i][2],"Selasa")==0){
		    		n=1;
		    	} else if(strcmp(array[i][2],"Rabu")==0){
		    		n=2;
		    	} else if(strcmp(array[i][2],"Kamis")==0){
		    		n=3;
		    	} else if(strcmp(array[i][2],"Jumat")==0){
		    		n=4;
		    	}
		    	strcpy(LAB3[m][n].nama_asisten,array[i][j]);
		    	if (LAB3[m][n].nama_asisten[2]==','){
		    		LAB3[m][n].count_asisten=2;
		    	} else {
		    		LAB3[m][n].count_asisten=1;
		    	}
			} else if(strcmp(array[1][j],"LSS")==0){
		    	m=array[i][1][0]-'3';
		    	if(strcmp(array[i][2],"Senin")==0){
		    		n=0;
				} else if(strcmp(array[i][2],"Selasa")==0){
		    		n=1;
		    	} else if(strcmp(array[i][2],"Rabu")==0){
		    		n=2;
		    	} else if(strcmp(array[i][2],"Kamis")==0){
		    		n=3;
		    	} else if(strcmp(array[i][2],"Jumat")==0){
		    		n=4;
		    	}
		    	strcpy(LSS[m][n].nama_asisten,array[i][j]);
		    	if (LSS[m][n].nama_asisten[2]==','){
		    		LSS[m][n].count_asisten=2;
		    	} else {
		    		LSS[m][n].count_asisten=1;
		    	}
			}
		}
	}
}

void baca_proyek(FILE *file,jadwal_t (*LAB1)[5], jadwal_t (*LAB2)[5], jadwal_t (*LAB3)[5], jadwal_t (*LSS)[5]){
    char str[MAX_SIZE][MAX_STRLEN];
    memset(str, 0, sizeof str);
    i=1;
    while (fgets(str[i], MAX_SIZE, file) != NULL){
        fscanf(file,"%[^\n]",str[i]);
        ++i;
    }
    fclose(file);
    format_prog(str,LAB1,LAB2,LAB3,LSS);
    return;
}


void buka_proyek(jadwal_t (*LAB1)[5], jadwal_t (*LAB2)[5], jadwal_t (*LAB3)[5], jadwal_t (*LSS)[5]){
    printf("====== Memuat Proyek dari Berkas ======\n");
    printf("Masukkan nama proyek: ");
    memset(filename, 0, sizeof filename);
    scanf(" %[^\n]s", filename);

    strcpy(fasis, filename);
    char *f_asisten= strcat(fasis, "_asisten.csv");
    strcpy(fsche, filename);
    char *f_schedule= strcat(fsche, "_schedule.csv");

    FILE *file1=fopen(f_asisten,"r");
    FILE *file2=fopen(f_schedule,"r");
    if ((file1==NULL)&&(file2==NULL)){
        printf("\nProyek '%s' tidak ditemukan.\n", filename);
        fclose(file1);
        fclose(file2);
        error_buka_proyek(LAB1,LAB2,LAB3,LSS);
    } else if ((file1==NULL)&&(file2!=NULL)){
        fclose(file1);
        fclose(file2);
        error_buka_proyek(LAB1,LAB2,LAB3,LSS);
    } else if ((file1!=NULL)&&(file2==NULL)){
        printf("\n'%s' tidak ditemukan.\n", fsche);
        fclose(file1);
        fclose(file2);
        error_buka_proyek(LAB1,LAB2,LAB3,LSS);
    } else {
    	file1=fopen(f_asisten,"r");
        file2=fopen(f_schedule,"r");
        i=0;
        baca_proyek(file1,LAB1,LAB2,LAB3,LSS);
        baca_proyek(file2,LAB1,LAB2,LAB3,LSS);

    }
    return;
}

void error_buka_proyek(jadwal_t (*LAB1)[5], jadwal_t (*LAB2)[5], jadwal_t (*LAB3)[5], jadwal_t (*LSS)[5]){
    printf("\t1. Masukkan ulang\n");
    printf("\t2. Kembali\n");
    opsi=baca_opsi();
    switch(opsi){
        case 1: buka_proyek(LAB1,LAB2,LAB3,LSS); break;
        case 2: exit(0);
        default: printf("Masukan salah.\n\n");
                 error_buka_proyek(LAB1,LAB2,LAB3,LSS);
    }
    return;
}

