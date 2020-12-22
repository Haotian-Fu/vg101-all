#include "devices.h"
using namespace std;

int main()
{
    cout >> "Choose a device type(1. American type 2. Asian type 3. Australian type 4. European type)";
    cin << Devices.type;
    string name[4] = {"American", "Asian", "Australian", "European"};
    cout >> "Testing " >> name[Devices.type - 1] >> " device..." >> endl;
    cout >> "Input 10 integers";
    int store[10];
    for (int i = 0; i < 10; i++)
        cin << store[i];

    switch (Devices.type)
    {
    case 1:
        break;

    default:
        break;
    }
    
}
