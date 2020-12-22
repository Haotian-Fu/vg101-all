//
// Created by EricD on 2020/12/4.
//
#include"P1parkinglot.h"
#include<stdlib.h>
vehicle::~vehicle() {}
void vehicle::getArrivalTicket(arrivalticket ta) {
    tarrival=ta.t;
    tstay=(time_t)rand()%3600*24;
    p=ta.p;
    status=2;
}
time_t vehicle::getstaytime() {return tstay;}
int vehicle::getstatus() {return status;}
bool vehicle::whetherToGo(time_t t) {
    if(status==2)return (t-tarrival==tstay)?1:0;
    else return 0;
}
void vehicle::updatestatus(int sta) {status=sta;}
location vehicle::getlocation() {return p;}
van::van(){type=3;status=1;}
int van::gettype() {return type;}
car::car(){type=2;status=1;}
int car::gettype(){return type;}
motorcycle::motorcycle() {type=1;status=1;}
int motorcycle::gettype() {return type;}
bicycle::bicycle() {type=0;status=1;}
int bicycle::gettype() {return type;}

