
#ifndef DEVICES_H
#define DEVICES_H

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <array>
#include <string>
#include <ctime>
using namespace std;

class Devices
{
    public:
        int type;
        int button[4];
        char button_name[4]={'A','B','C','D'};
        virtual int A();
        virtual int B();
        virtual int C();
        virtual int D();
    protected:
        int calc_0; int calc_1;
};

class American: public Devices
{
    public:
        int outcome[10];
        int A(int input);
        int B(int input);
        int C(int input);
        int D(int input);
    protected:
        int calc_0=0;
        int calc_1=0;
        int x;
};
class Asian: public Devices
{
    public:
        int outcome[10];
        int A(int input);
        int B(int input);
        int C(int input);
        int D(int input);
    protected:
        int calc_0=0;
        int calc_1=0;
        int x;
};
class Australian: public Devices
{
    public:
        int outcome[10];
        int A(int input);
        int B(int input);
        int C(int input);
        int D(int input);
    protected:
        int calc_0=0;
        int calc_1=0;
        int x;
};
class European: public Devices
{
    public:
        int outcome[10];
        int A(int input);
        int B(int input);
        int C(int input);
        int D(int input);
    protected:
        int calc_0=0;
        int calc_1=0;
        int x;
};
#endif


