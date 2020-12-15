#include "assignment.h"
  
// ex. 1 function: disptach work to other functions for exercise 1
typedef struct _complex{
    int real;
    int imag;
    } complex_t;

void ex1() {
    
    complex_t a1,a2;
    char n;
    //scanf("%d%di %d%di %c",&a1.real,&a1.imag,&a2.real,&a2.imag,&n);
    if(scanf("%d%di %d%di %c",&a1.real,&a1.imag,&a2.real,&a2.imag,&n)!=0){
       if(n=='+'){
        int addreal,addimag;
        addreal = a1.real+a2.real;
        addimag = a1.imag+a2.imag;
        printf("%d%+di\n",addreal,addimag);
        }
        if(n=='*'){
        int multreal,multimag;
        multreal = a1.real*a2.real-a1.imag*a2.imag;
        multimag = a1.real*a2.imag+a2.real*a1.imag;
        printf("%d%+di\n",multreal,multimag);
        } 
    }   
}

//#ifdef JOJ
int main(){
    ex1();
    return 0;
}
//#endif
