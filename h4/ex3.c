#include "assignment.h"
#include <math.h>
// ex. 3 function: disptach work to other functions for exercise 3

//int root(int a,int b,float x1,float x2,float x1i,float x2i,float delta){
    
    
//}

void ex3() {
    float a,b,c,x1,x2,x1i,x2i,delta;
    if(scanf("%f %f %f",&a,&b,&c)!=0){
        delta = (b*b)-4*a*c;
        x1=0.0;x2=0.0;x1i=0.0;x2i=0.0;
        //root(a,b,x1,x2,x1i,x2i,delta);
        if (delta<0){
            x1 = -b/(2*a);
            x1i = -sqrt(-delta)/(2*a);
            x2 = -b/(2*a);
            x2i = sqrt(-delta)/(2*a);
            printf("%0.5f%+0.5fi\n%0.5f%+0.5fi",x1,x1i,x2,x2i);
        }
        if(delta==0){
            x1 = (-b-sqrt(delta))/(2*a);
            printf("%0.5f",x1);
        }
        if(delta>0){
            x1 = (-b-sqrt(delta))/(2*a);
            x2 = (-b+sqrt(delta))/(2*a);
            printf("%0.5f\n%0.5f",x1,x2);
        }
    }
    
}


//#ifdef JOJ
int main(){
    ex3();
    return 0;
}
//#endif
