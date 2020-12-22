//
// Created by EricD on 2020/12/4.
//

#ifndef P3_PARKING_LOT_H
#define P3_PARKING_LOT_H
#include<ctime>
#include<vector>
#include<fstream>
using namespace std;
typedef struct _location{int floor;int number;}location;
typedef struct _arrivalticket{time_t t;int type;location p;}arrivalticket;
//typedef struct _departureticket{time_t stay;int type;int price;}departureticket;
class TicketMachine{
private:time_t t;time_t tactual;
public:
    TicketMachine();
    void updatetime(time_t cnt);
    arrivalticket printArrivalTicket(class vehicle *v,location slot,ofstream *out);
    void printDepartureticket(class vehicle *v,ofstream *out);

};

class slot{
private:bool status;location l;int type;//status 1:empty status 0:taken
public:
    slot(int f=1,int n=1,int sltype=0);
    int whichtype();
    bool isempty();
    location getlocation();
    void updatestatus();
};

class vehicle{
protected:time_t tarrival;time_t tstay;location p;int status;//1:new arrival 2:parking 3:departure 0:left
public:
    void getArrivalTicket(arrivalticket ta);//print ticket
    bool whetherToGo(time_t t);
    virtual int gettype()=0;
    time_t getstaytime();
    int getstatus();
    location getlocation();
    void updatestatus(int status);
    virtual ~vehicle()=0;
};
class van:public vehicle{
private:int type;
public:
    van();
    int gettype();
};
class car:public vehicle{
private:int type;
public:
    car();
    int gettype();
};
class motorcycle:public vehicle{
private:int type;
public:
    motorcycle();
    int gettype();
};
class bicycle:public vehicle{
private:int type;
public:
    bicycle();
    int gettype();
};

class Parkinglot{
private:
    vector<vehicle*>V;
    vector<slot>S;
    TicketMachine T;
public:
    Parkinglot(int floor=2);
    ~Parkinglot();
    void newVehicle(ofstream *out);//1.new vehicle generate 2. check slot status 2.arv ticket printed 3.vehicle & slot status updated
    void TicketMachineUpdate(time_t t);
    void VehicleLeaving(time_t t,ofstream *out);//check vehicle status if leaving then leave
};



#endif //P3_PARKING_LOT_H
