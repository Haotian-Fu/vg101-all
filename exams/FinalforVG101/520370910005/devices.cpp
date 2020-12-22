#include "devices.h"

char American::A(int input){
    input= 2*input %5;
    return 'C';
}
char American::B(int input){
    if(input>=10)
    return 1;
    else return 'D';
}
char Americna::C(int input){
    input +=6;
    return 'B';
}
int American::D(int input){
    if(x%3!=1)
    return 0;
    else
    {
        return 1;
    }
    
}