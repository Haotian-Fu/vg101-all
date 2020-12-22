//
// Created by EricD on 2020/12/4.
//
#include"P1parkinglot.h"
#include<iostream>
int getprice(int type, time_t tstay){//one step as one second
    int price;
    price=(int)(tstay*(time_t)1/3600*2*(type+1));
    return price;
}
TicketMachine::TicketMachine() {t=0;tactual=time(0);}
void TicketMachine::updatetime(time_t cnt) {t=cnt;}
arrivalticket TicketMachine::printArrivalTicket(class vehicle *v,location slot,ofstream *out){
    arrivalticket at;
    at.t=t;
    at.type=v->gettype();
    at.p=slot;
    time_t tout=at.t+tactual;
    char* dt = ctime(&tout);
    cout<<"\n***ARRIVAL TICKET***"<<endl;
    *out<<"\n***ARRIVAL TICKET***"<<endl;
    cout<<"Time of arrival: "<<dt;
    *out<<"Time of arrival: "<<dt;
    string tname;
    switch(at.type){
        case 0:tname="Bicycle";break;
        case 1:tname="Motorcycle";break;
        case 2:tname="Car";break;
        case 3:tname="Van";break;
    }
    cout<<"Type of the vehicle: "<<tname<<endl;
    *out<<"Type of the vehicle: "<<tname<<endl;
    cout<<"Empty Slot: Floor "<<at.p.floor<<" Slot number "<<at.p.number<<endl<<endl;
    *out<<"Empty Slot: Floor "<<at.p.floor<<" Slot number "<<at.p.number<<endl<<endl;
    return at;
}
void TicketMachine::printDepartureticket(class vehicle *v,ofstream *out) {
    string tname;
    switch(v->gettype()){
        case 0:tname="Bicycle";break;
        case 1:tname="Motorcycle";break;
        case 2:tname="Car";break;
        case 3:tname="Van";break;
    }
    cout<<"\n***DEPARTURE TICKET***\n";
    *out<<"\n***DEPARTURE TICKET***\n";
    cout<<"Time spent in the parking lot: "<<v->getstaytime()/3600<<"h "<<(v->getstaytime()%3600)/60\
    <<"min "<<v->getstaytime()%60<<"sec\n";
    *out<<"Time spent in the parking lot: "<<v->getstaytime()/3600<<"h "<<(v->getstaytime()%3600)/60\
    <<"min "<<v->getstaytime()%60<<"sec\n";
    cout<<"Type of the vehicle: "<<tname<<endl;
    *out<<"Type of the vehicle: "<<tname<<endl;
    cout<<"Price: "<<'$'<<getprice(v->gettype(),v->getstaytime())<<endl<<endl;
    *out<<"Price: "<<'$'<<getprice(v->gettype(),v->getstaytime())<<endl<<endl;
}

