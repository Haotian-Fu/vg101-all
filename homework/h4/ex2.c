#include "assignment.h"

// ex. 2 function: disptach work to other functions for exercise 2
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
void ex2() {
    int a,b;
    if(scanf("%d %d",&a,&b)!=0){
        printf("%d\n",gcd(a,b)); 
    }
    
}

//#ifdef JOJ
int main(){
    ex2();
    return 0;
}
//#endif
