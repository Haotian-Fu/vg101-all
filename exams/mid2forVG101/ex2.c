#include "assignment.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ex. 2 function: disptach work to other functions for exercise 2
void ex2() {
    char* n={0,0,0,0,0,0};
    printf("Input an integer:\n");
    if(scanf("%s",&n)!=0){
        for(i=0;i<6;i++){
            if(n[i]!=0){
                switch (i)
                {
                case 2:
                    switch (n[i])
                    {
                    case 1:
                        printf("one ");
                        break;
                    case 2:
                        printf("two ");
                        break;
                    case 3:
                        printf("three ");
                        break;
                    case 4:
                        printf("four ");
                        break;
                    case 5:
                        printf("five ");
                        break;
                    case 6:
                        printf("six ");
                        break;
                    case 7:
                        printf("seven ");
                        break;
                    case 8:
                        printf("eight ");
                        break;
                    case 9:
                        printf("nine ");
                        break;
                    default:
                        break;
                    }
                    printf("thousand");
                    break;
                case 3:
                case 0:
                    switch (n[i])
                    {
                    case 1:
                        printf("one ");
                        break;
                    case 2:
                        printf("two ");
                        break;
                    case 3:
                        printf("three ");
                        break;
                    case 4:
                        printf("four ");
                        break;
                    case 5:
                        printf("five ");
                        break;
                    case 6:
                        printf("six ");
                        break;
                    case 7:
                        printf("seven ");
                        break;
                    case 8:
                        printf("eight ");
                        break;
                    case 9:
                        printf("nine ");
                        break;
                    default:
                        break;
                    }
                    printf("hundred");
                    break;
                case 1:
                case 4:
                    switch (n[i])
                    {
                    case 2:
                        printf("twenty ");
                        break;
                    case 3:
                        printf("thirty ");
                        break;
                    case 4:
                        printf("forty ");
                        break;
                    case 5:
                        printf("fifty ");
                        break;
                    case 6:
                        printf("sixty ");
                        break;
                    case 7:
                        printf("seventy ");
                        break;
                    case 8:
                        printf("eighty ");
                        break;
                    case 9:
                        printf("ninty ");
                        break;
                    default:
                        break;
                    }
                    printf("and");
                    break;
                default:
                    switch (n[i])
                    {
                    case 1:
                        printf("one");
                        break;
                    case 2:
                        printf("two");
                        break;
                    case 3:
                        printf("three");
                        break;
                    case 4:
                        printf("four");
                        break;
                    case 5:
                        printf("five");
                        break;
                    case 6:
                        printf("six");
                        break;
                    case 7:
                        printf("seven");
                        break;
                    case 8:
                        printf("eight");
                        break;
                    case 9:
                        printf("nine");
                        break;
                    default:
                        break;
                    }
                    break;
                }
            }
        }
    }
}

#ifdef JOJ
int main(){
    ex2();
    return 0;
}
#endif
