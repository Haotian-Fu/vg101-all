//
// Created by EricD on 2020/12/9.
//
#include"P2parkinglot.h"
#include<chrono>
void TimeStep(int n)
{
    glutTimerFunc((unsigned int)n, TimeStep, n);
    glutPostRedisplay();
}
void myDisplay() {
    int static _number=0;int static _n=0;
    if(_number==0){
        cout<<"***Demonstration begin!***\n"<<"please input slot number (>=12): ";
        cin>>_number;
        _n=rand()%_number+1;
    }
    auto seed = std::chrono::system_clock::now ().time_since_epoch ().count ();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    int static begin=0;
    vector<Vec> static _p0((unsigned long)_n,{2.5f,-10});
    vector<Vec> static _ber((unsigned long)_n,{0,1});
    vector<Vec> static _pointing((unsigned long)_n,{0,0.09f});
    Vec static ber_gate={1,0};
    int static _status[500]={0};
    int static _side[500]={0};
    if (begin==0){
        vector<int>__status;
        for(unsigned long int i=0;i<(unsigned long)_number;i++){__status.push_back((int)i+1);}
        shuffle(__status.begin(),__status.end(),default_random_engine ((unsigned int) seed));
        for(unsigned long int i=0;i<(unsigned long)_number;i++){
            _status[i]=__status[i];
            _side[i]=rand()%300;
        }
        begin=1;
    }
    int static status_gate=0;
    Vec **p0=new Vec *[(unsigned long)_n];
    Vec **ber=new Vec *[(unsigned long)_n+1];
    Vec **pointing=new Vec*[(unsigned long)_n];
    int **status=new int *[(unsigned long)_number+1];
    int **side=new int *[(unsigned long)_number-_n];
    unsigned long int i=0;
    for(;i<(unsigned long)_n;i++){
        p0[i]=&_p0[i];
        ber[i]=&_ber[i];
        status[i]=&_status[i];
        pointing[i]=&_pointing[i];
    }
    ber[_n]=&ber_gate;status[_n]=&status_gate;
    for(i=(unsigned long)_n+1;i<(unsigned long)_number+1;i++){
        side[i-_n-1]=&_side[i-_n-1];
        status[i]=&_status[i-1];
    }
    Parkinglot P(p0,ber,status,side,_number,_n,pointing);
    P.move();P.draw();
    glutSwapBuffers();
    glFlush();
    delete []p0;delete []ber;delete[]status;delete[]side;delete[]pointing;
}

int main(int argc,char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(100,100 );
    glutInitWindowSize(800, 800);
    glutCreateWindow("Parking lot");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(-3,40,-3,40);
    glutDisplayFunc(myDisplay);
    glutTimerFunc(10,TimeStep,1);
    glutMainLoop();
    return 0;
}
