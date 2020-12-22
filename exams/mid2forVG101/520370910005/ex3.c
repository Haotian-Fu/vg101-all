#include "assignment.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ex. 3 function: disptach work to other functions for exercise 3
void ex3() {
    if(scanf("%d",n)!=0){
        int line = n/10;
        int column = n%10;
        printf("%d\n-\n%d",line,column);
    }
}

#ifdef JOJ
int main(){
    ex3();
    return 0;
}
#endif
