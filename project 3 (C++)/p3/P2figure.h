//
// Created by EricD on 2020/12/10.
//

#ifndef P3_P2FIGURE_H
#define P3_P2FIGURE_H
#include<cmath>
#ifdef _WIN32
#define <GL/freeglut.h>
#elif _WIN64
#include <GL/freeglut.h>
#elif __APPLE__
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#elif __linux__
#include <GL/freeglut.h>
#endif
#include<iostream>
#include<vector>
using namespace std;
static const float V=0.08f;
static const float PI=3.1415926535f;
class Vec {
private:
    float x,y;
public:
    Vec(float _x=0, float _y=0);
    float getX();
    float getY();
    Vec operator+ (Vec v);
    Vec operator- (Vec v);
    Vec operator* (float k);
    float operator* (Vec v);
    Vec operator<<(float a);
    Vec operator>>(float a);
    float norm();
};
class Figure {
protected:
    Vec anchor;
public:
    Figure();
    Vec getAnchor();
    virtual void draw()=0;
    virtual ~Figure(){};
};

class Gate:public Figure{
public:
    Gate(Vec _ber,int _status);
    void draw();
    void open(Vec *_ber,int*_status);
    void close(Vec *_ber,int *_status);
    int returnstatus();
private:
    Vec dir,p;
    int status;
};

class ColorFig: public Figure{
public:
    virtual void draw()=0;
    virtual ~ColorFig(){};
protected:
    float r=0,g=0,b=0;
};

class Line:public ColorFig{
public:
    Line(Vec ra = {0, 0}, Vec rb = {0.1f, 0.2f},Vec anc={0,0});
    void draw();
    ~Line(){};
private:
    Vec t1,t2;
};

class Triangle: public ColorFig{
public:
    Triangle(Vec _t1={-.5,-.5},Vec _t2={.5,-.5},Vec _t3={0,.5},Vec _anc={0,0},float _r=0.8f,float _g=0.1f,float _b=0.1f);
    void draw();
    ~Triangle(){};
private:
    Vec t1={-0.5,0},t2={0.5,0},t3={0,0.5};
};
class Trapezium: public ColorFig{
public:
    Trapezium(Vec _ll={-1,-1},Vec _lr={1,-1},Vec _ul={-.5,.5},Vec _ur={.5,.5},Vec _anc={0,0},float _r=0.1f,float _g=0.1f,float _b=0.8f);
    void draw();
    virtual ~Trapezium(){};
protected:
    Vec t1={-1,-1},t2={1,-1},t3{-.5,.5},t4={.5,.5};
};

class Teleporter: public ColorFig{
public:
    void setcolor();
    void draw();
    void changeside(int *_side);
    Teleporter(int _status,int _num,int *_side);
private:
    vector<Vec> tel;
    int side;
};

class Circle: public ColorFig{
public:
    Circle(Vec pos={0,0.5},Vec _anc={0,0},float Radius=1,float _r=0.1f,float _g=0.1f,float _b=0.8f);
    virtual void draw();
    virtual ~Circle(){};
protected:
    float R=1;Vec c={0,0.5};
};
class SemiCircle: public Circle{
public:
    SemiCircle(Vec pos={0,0.5},Vec _anc={0,0},Vec ber={0,0.06f},float Radius=1,float _r=0.1f,float _g=0.1f,float _b=0.8f);
    void draw();
    ~SemiCircle(){};
private:
    Vec pnt=Vec(0,0);
};

class Group :public Figure {
public:
    Group();
    virtual ~Group();
    void move(Vec *p0,float step);
    void rotate(float angle,Vec *dir);
    void findingslot(Vec *_p0,Vec *_ber,int *_status,int _n);
    int getstatus();
    virtual void special(Vec *ber)=0;
    virtual int returntype()=0;
protected:
    Vec y={0,1};Vec x={1,0};
    ColorFig *s[10];
    Vec slotpos;
    int status,type;
};

class rocket:public Group{
public:
    rocket(Vec p0, Vec ber,int _status,int _n);
    ~rocket();
    void draw();
    void special(Vec *ber);
    int returntype();
};

class Car: public Group{
private:
    Vec flag;
public:
    Car(Vec anc,Vec ber,int _status,int _n);
    void special(Vec *ber);
    void draw();
    int returntype();
    ~Car();
};
class UFO:public Group{
protected:
    Vec _y,_x;
public:
    UFO(Vec anc,Vec ber,int _status,int _n,Vec _pointing);
    void special(Vec *_pointing);
    void draw();
    int returntype();
    ~UFO();
};


#endif //P3_P2FIGURE_H
