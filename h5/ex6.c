#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(a,b) { a ^= b; b ^= a; a ^= b; }   //swap() function,to exchange the value of a,b
// #de5fine TEST
unsigned long int mult(unsigned long int a, unsigned long int b);   //define mult() function
int main () {
    unsigned long int a, b;     //define variable a,b
    srand(time(NULL));      //create a random seed
#ifndef TEST                //run the code and print the result as h5.pdf says
    a=rand(); b=rand();     //give a,b random long numbers 
    printf("%ld*%ld=%ld %d\n",a,b,mult(a,b), RAND_MAX);    //print the formula and results
#endif
#ifdef TEST                 //test if the program run successfully
    int i;
    for(i=0; i< 1000000; i++) {
        a=rand(); b=rand();     //give a,b random long numbers 
        if(mult(a,b)!=a*b) {    //if the code is wrong
            fprintf(stderr,"Error (%d): a=%ld, b=%ld, a*b=%ld, k(a,b)=%ld\n",\
                i,a,b,a*b,mult(a,b));       //print the error result
            exit(-1);           //quit the program
        }
    }
#endif
}
unsigned long int mult(unsigned long int a, unsigned long int b) {
    unsigned long int i,n,m,N,M;        
    unsigned long int x0,y0,x1,y1,z0,z1,z2,z3;      //define some useful variables.
    if(a<b) SWAP(a,b);          //make a>=b
    if(b==0) return 0;
    if(b==1) return a;          //make the function have an output
    for(M=0, i = 1; i <= b; i<<=1, M++);        //make M be the length of b
    m=M/2;
    for(N=M; i <= a; i<<=1, N++);               //make N be the length of a
    n=N/2;
    x0 = a&((1<<m)-1);              //x0 is the remaining 4 numbers of b (in binary)
    x1 = a>>m;                      //x1 is the first 4 numbers of b (in binary)
    y0 = b&((1<<n)-1);              //y0 is the remaining 4 numbers of a (in binary)
    y1 = b>>n;                      //y1 is the first 4 numbers of a(in binary)
    // Therefore, a = 2^m*x1+x0; b = 2^n*y1+y0;
    z0 = mult(x0,y0);                 //use a recursive function to calculate x0 * y0
    z1 = mult(x1,y1);                 //use a recursive function to calculate x1 * y1
    z2 = mult(x1,y0);                 //use a recursive function to calculate x1 * y0
    z3 = mult(x0,y1);                 //use a recursive function to calculate x0 * y1
    return ((z1<<(m+n))+(z2<<m)+(z3<<n)+z0);        //2^m*x1+2^n*y1+(x1*y0*2^m+x0*y1*2^m)+x0*y0
    // for(n=-1, i = 1; i <= b; i<<=1, n++); /* not optimal */
    // for(N=n; i <= a; i<<=1, N++);
    // y0=b&((1<<n)-1);
    // x0=a&((1<<N)-1);
    // z0=mult(x0,y0);
    // i=N+n;
    // return ((z1<<i)+(x0<<n)+(y0<<N)+z0);
}