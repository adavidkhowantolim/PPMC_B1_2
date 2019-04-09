#include "lib.h"

int opsi,i,k,n,j,N,m;
char array[MAX_SIZE][MAX_SIZE][MAX_CELL_SIZE];
char str[MAX_SIZE][MAX_STRLEN], temp[MAX_SIZE][MAX_STRLEN];
char c='"';
char filename[100],fasis[20],fsche[20];

typedef struct {
	char kode_praktikum[10];
	char Rombongan[10];
	int count_asisten;
	char nama_asisten[3];

} jadwal_t;
jadwal_t LAB1[12][5], LAB2[12][5], LAB3[12][5], LSS[12][5];

void format_program(){
    memset(array, 0, sizeof array);
    memset(temp, 0, sizeof temp);

    for(n=1; n<MAX_SIZE; n++){
        i=0; j=0;
        while (str[n][i]!='\n') {
            if((i==0)&&(str[n][i]==','))
                temp[n][++j]='0';
            temp[n][++j]=str[n][i];
            if ((str[n][i]==',')&&((str[n][i+1]==',')||(str[n][i+1]==NULL))){
                temp[n][++j]='0';
            }
            ++i;
        }
    }

    i=1; j=1; k=0;
    for(n=1; n<MAX_SIZE; n++){
        while(temp[n][i]!=NULL){
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

void baca_proyek(FILE *file){
    memset(str, 0, sizeof str);
    i=1;
    while (fgets(str[i], MAX_SIZE, file) != NULL){
        ++i;
    }
    fclose(file);
    format_program();
    return;
}


void buka_proyek(){
    printf("====== Memuat Proyek dari Berkas ======\n");
    printf("Masukkan nama proyek: ");
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
        error_buka_proyek();
    } else if ((file1==NULL)&&(file2!=NULL)){
        printf("\n'%s' tidak ditemukan.\n", fasis);
        fclose(file1);
        fclose(file2);
        error_buka_proyek();
    } else if ((file1!=NULL)&&(file2==NULL)){
        printf("\n'%s' tidak ditemukan.\n", fsche);
        fclose(file1);
        fclose(file2);
        error_buka_proyek();
    } else {
    	file1=fopen(f_asisten,"r");
        file2=fopen(f_schedule,"r");
        i=0;
        baca_proyek(file1);
        baca_proyek(file2);

    }
    exit(0);
    return;
}

void error_buka_proyek(){
    tab(); printf("1. Masukkan ulang\n");
    tab(); printf("2. Kembali\n");
    opsi=baca_opsi();
    switch(opsi){
        case 1: buka_proyek(); break;
        case 2: exit(0);
        default: printf("Masukan salah.\n\n");
                 error_buka_proyek();
    }
    return;
}

int main(){
    buka_proyek();
    return 0;
}
