#include "assignment.h"

# define M_PI		3.14159265358979323846	/* pi */
// ex. 2 function: disptach work to other functions for exercise 2
typedef struct cart_point{
    double real;
    double img;
}cart_p_t;

typedef struct polar_point{
    double r;
    double angle;
}polar_p_t;

void cart_polar(cart_p_t* pointc, polar_p_t* pointp);
void polar_cart(cart_p_t* pointc, polar_p_t* pointp);

void cart_polar(cart_p_t* pointc, polar_p_t* pointp){

    for(int i=0;i<3;i++){
            pointp[i].r=sqrt(pointc[i].real*pointc[i].real + pointc[i].img*pointc[i].img);
            pointp[i].angle=acos(pointc[i].real/pointp[i].r);        
    }
            pointp[4].r=sqrt(pointc[4].real*pointc[4].real + pointc[4].img*pointc[4].img);
            pointp[4].angle=acos(pointc[4].real/pointp[4].r);        
    
}

void polar_cart(cart_p_t* pointc, polar_p_t* pointp){
            pointc[3].real=pointp[3].r * cos(pointp[3].angle);
            pointc[3].img=pointp[3].r * sin(pointp[3].angle);       
            pointc[5].real=pointp[5].r * cos(pointp[5].angle);
            pointc[5].img=pointp[5].r * sin(pointp[5].angle); 
}


void ex2() {
    cart_p_t pointc[6]={{3.,0.8},{+0.,log(4)},{45.245,0.23500},
                    {0.,0.},{4*cos(M_PI/9),4*sin(M_PI/9)},{0.,0.}};
    polar_p_t pointp[6]={{0.,0.},{0.,0.},{0.,0.},{3.,(M_PI/17)},{0.,0.},{1.,(M_PI/12)}};
    cart_polar(pointc,pointp);
    polar_cart(pointc,pointp);
    for(int i=0;i<6;i++){
        switch (i)
        {
        case 3:
            printf("%.5fe%.5fi %.5f%+.5fi\n",pointp[i].r,pointp[i].angle,pointc[i].real,pointc[i].img);
            break;
        case 5:
            printf("%.5fe%.5fi %.5f%+.5fi\n",pointp[i].r,pointp[i].angle,pointc[i].real,pointc[i].img);
            break;
        default:
            printf("%.5f%+.5fi %.5fe%.5fi\n",pointc[i].real,pointc[i].img,pointp[i].r,pointp[i].angle);
            break;
        }
    }
}

//#ifdef JOJ
int main(){
    ex2();
    return 0;
}
//#endif
