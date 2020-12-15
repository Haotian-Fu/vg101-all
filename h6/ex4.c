#include "assignment.h"
// ex. 4 function: disptach work to other functions for exercise 4

void ex4() {
    FILE *fp = fopen("matrices.txt", "r");
    FILE *fr = fopen("result.txt","w");
    int cnt=1;    //size = cnt * cnt  
    static int matA[600][600];
    static int matB[600][600];
    static int matADD[600][600];
    static int matMULT[600][600];
    static int matA1[600][600];
    static int matB1[600][600];
    static int matMULT1[600][600];
    //the first line
    while(1){
        char c;
        fscanf(fp,"%c",&c);
        if(c==' '){
            cnt++;
        }
        if(c=='\n'){
            break;
        }
    }
    //printf("%d",cnt);
    rewind(fp);

    //scan part
    for(int i=0;i<cnt;i++){
        for(int j=0;j<cnt;j++){
            fscanf(fp, "%d",&matA[i][j]);
        }
    }
    
    for(int i=0;i<cnt;i++){
        for(int j=0;j<cnt;j++){
            fscanf(fp, "%d",&matB[i][j]);
        }
    }

    //add
    for(int i=0;i<cnt;i++){
        for(int j=0;j<cnt;j++){
            matADD[i][j]=matA[i][j]+matB[i][j];
        }
    }

    //multiply
    for(int i=0;i<cnt;i++){
        for(int j=0;j<cnt;j++){
            for(int n=0;n<cnt;n++){
                matMULT[i][j]+=matA[i][n]*matB[n][j];
            }
        }
    }

    //transportation
    for(int i=0;i<cnt;i++){
        for(int j=0;j<cnt;j++){
            matA1[i][j]=matA[j][i];
            matB1[i][j]=matB[j][i];
        }
    }

    for(int i=0;i<cnt;i++){
        for(int j=0;j<cnt;j++){
            for(int n=0;n<cnt;n++){
                matMULT1[i][j]+=matA1[i][n]*matB1[n][j];
            }
        }
    }

    //print part
    for(int i=0;i<cnt;i++){
        for(int j=0;j<cnt;j++){
            fprintf(fr, "%d ",matADD[i][j]);    
        }
        fprintf(fr,"\n");
    }
    fprintf(fr,"\n");

    for(int i=0;i<cnt;i++){
        for(int j=0;j<cnt;j++){
            fprintf(fr, "%d ",matMULT[i][j]);    
        }
        fprintf(fr,"\n");
    }
    fprintf(fr,"\n");
    
    for(int i=0;i<cnt;i++){
        for(int j=0;j<cnt;j++){
            fprintf(fr, "%d ",matMULT1[i][j]);    
        }
        fprintf(fr,"\n");
    }

    fclose(fp);
    fclose(fr);
    
}

#ifndef JOJ
int main(){
    ex4();
    return 0;
 }
#endif
