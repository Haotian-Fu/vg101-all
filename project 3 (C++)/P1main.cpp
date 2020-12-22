#include <iostream>
#include <ctime>
#include"P1parkinglot.h"
#include<cstdlib>
#include <fstream>


using namespace std;

int main( )
{
    int floor;
    ofstream out;
    out.open("demonstration.log");
    out<<"Demonstration begin!"<<endl;
    cout<<"Input total floor number (larger than 1): ";
    cin>>floor;
    Parkinglot P(floor);
    srand((unsigned int)time(NULL));
    time_t cnt;
    for(cnt=0;cnt<=3600*24;cnt++){
        P.TicketMachineUpdate(cnt);
        P.newVehicle(&out);
        P.VehicleLeaving(cnt,&out);
    }
    cout<<"\nDemonstration Finish!"<<endl;
    out<<"\nDemonstration finish!"<<endl;
    out.close();
    return 0;
}
