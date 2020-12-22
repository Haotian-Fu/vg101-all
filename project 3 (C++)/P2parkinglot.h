//
// Created by EricD on 2020/12/9.
//

#ifndef P3_P2PARKINGLOT_H
#define P3_P2PARKINGLOT_H
#include<iostream>
#include<stdlib.h>
#include<cmath>
#include<vector>
#include <algorithm>
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
#include"P2figure.h"
#include <algorithm>
#include <random>
using namespace std;

class Parkinglot{
public:
    Parkinglot(Vec **_p0,Vec **_ber,int **_status,int **_side,int _number,int _n,Vec **_pointing);
    void move();
    void draw();
    ~Parkinglot();
private:
    int n,num;//n is the vehicle number num is the total slot number
    vector<Group*>g;
    vector<Teleporter*>t;
    vector<Vec *>p0;
    vector<Vec *>ber;
    vector<Vec *>pointing;
    vector<int *>status;
    Gate *gate;
};

#endif //P3_P2PARKINGLOT_H
