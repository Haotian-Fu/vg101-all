//
// Created by EricD on 2020/12/4.
//
#include"P1parkinglot.h"
#include<iostream>
Parkinglot::Parkinglot(int floor) {
    int i=1;//1st floor has 50 slots (0) for bikes and 20 slots (1) for motorcycle
    // other floors each has 15 slots (2) for cars and 5 slots (3) for vans
    int t=i;
    for(;i<t+50;i++){
        slot temps(1,i,0);
        S.push_back(temps);
    }
    t=i;
    for(;i<t+20;i++){
        slot temps(1,i,1);
        S.push_back(temps);
    }
    for(int j=2;j<=floor;j++){
        t=i;
        for(;i<t+15;i++){
            slot temps(j,i,2);
            S.push_back(temps);
        }
        t=i;
        for(;i<t+5;i++){
            slot temps(j,i,3);
            S.push_back(temps);
        }
    }
}
Parkinglot::~Parkinglot() {
    for(int i=0;(unsigned)i<V.size();i++){
        delete V[(unsigned long)i];
    }
}
void Parkinglot::TicketMachineUpdate(time_t t) {T.updatetime(t);}
void Parkinglot::newVehicle(ofstream *out) {
    int chance=rand()%2000+1;
    if (chance<=10){
        vehicle *v;
        switch(chance){
            case 1:case 2:case 3:v=new bicycle;break;
            case 4:case 5:v=new motorcycle;break;
            case 6:case 7:case 8:case 9:v=new car;break;
            case 10:v=new van;break;
        }
        V.push_back(v);
        vector<slot>::iterator it;
        int flag=0;location slot;
        for(it=S.begin();it!=S.end();it++){
            if(it->isempty()){
                if(it->whichtype()==v->gettype()){
                    flag=1;slot=it->getlocation();
                    break;
                }
            }
        }
        if(flag==1){
            arrivalticket ta=T.printArrivalTicket(v,slot,out);
            v->getArrivalTicket(ta);
            v->updatestatus(2);
            it->updatestatus();
        }else{
            cout<<"No slot available! sorry!"<<endl;
            *out<<"No slot available! sorry!"<<endl;
            v->updatestatus(0);
        }
    }
}
void Parkinglot::VehicleLeaving(time_t t,ofstream *out) {
    for(int i=0;(unsigned)i<V.size();i++){
        if(V[(unsigned long)i]->whetherToGo(t)){
            V[(unsigned long)i]->updatestatus(3);
            S[(unsigned long)V[(unsigned long)i]->getlocation().number-1].updatestatus();
            T.printDepartureticket(V[(unsigned long)i],out);
            V[(unsigned long)i]->updatestatus(0);
        }
    }
}
