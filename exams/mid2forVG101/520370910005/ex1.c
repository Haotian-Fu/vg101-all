#include "assignment.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct polydense{
    int degree;
    int *ptr;
}poly_d;

typedef struct polysparse
{
    int num;
    int *ptr;
}poly_s;

// ex. 1 function: disptach work to other functions for exercise 1

poly_d polyd;
poly_s polys;


void trans(poly_d polyd,poly_s polys){
    int cnt=0;
    while(getchar()!=NULL){
        cnt++;
    }
    int max;
    if(scanf("%d",max)!=0){
        printf("dense %d",max);
        for(int i=0;i<(cnt/2);i++){
            scanf("%d %d",polys[i].num,polys[i].ptr);
            for(int c=polys[i].num;c<max;c++;printf(" 0 "));

        }

    }
}

void showd(poly_d polyd){
    scanf("%d",&polyd.degree){
                polyd.ptr= malloc(polyd.degree*sizeof(int))
                for(int i=0;i<polyd.degree;i++){
                    scanf("%d",polyd.ptr[i]);
                    if(i！=0 &&i!=polyd.degree-1){
                        if(polyd.ptr[i]!=0){
                        printf("+x^%d",polyd.degree-polyd.ptr[i]);
                        }
                    }
                    else{
                        if(i==0){
                            if(polyd.ptr[i]!=0){
                        printf("(x^%d",polyd.degree-polyd.ptr[i]);
                            }
                        }
                        if(i==polyd.degree-1){
                            if(polyd.ptr[i]!=0){
                        printf("+x^%d)",polyd.degree-polyd.ptr[i]);
                            }
                        }
                        if(i==cnt-1){
                            printf("%d",polyd.ptr[i]);
                        }
                    }
                }
            }
}

void shows(poly_s polys){
    int cnt=0;
    while(getchar()!=NULL){
        cnt++;
    }
    cnt=cnt/2;
    for(i=0;i<cnt;i++){
        scanf("%d %d",polys[i].num,polys[i].ptr);
        if(polys[i].ptr!=0){
            if(i==cnt-1){
                printf("%d",polys[i].num);
            }
            else{printf("+x^%d",polys[i].num);}
        }
    }
    
}

void mult(poly_s polys,poly_d polyd){
    poly_s polymult;
    int cnt=0;
    while(getchar()!=NULL){
        cnt++;
    }
    for(i=0;i<(cnt/2);i++){
        fprintf("x^%d",polymult.num[i]);
    }
    

    
}


void call(poly_s polys,poly_d polyd){
    fopen(fp,"polynomials.txt","r");
    fopen(fr,"output.txt","w");
    showd(polyd);
    shows(polys);
    mult(polys,polyd);
    fclose(fp);
    fclose(fr);
}


void ex1() {
    call();

}

#ifdef JOJ
int main(){
    ex1();
    return 0;
}
#endif
