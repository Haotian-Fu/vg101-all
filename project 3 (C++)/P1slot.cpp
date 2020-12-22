//
// Created by EricD on 2020/12/4.
//
#include"P1parkinglot.h"
slot::slot(int f,int n,int sltype){
    l.floor=f;l.number=n;status=1;type=sltype;
}
int slot::whichtype() {return type;}
bool slot::isempty() {return status;}
location slot::getlocation() {return l;}
void slot::updatestatus() {status=1-status;}
