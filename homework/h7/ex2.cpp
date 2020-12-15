//#include "assignment.h"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <string>
#include <valarray>
using namespace std;

void U2C(double a, int p);
void C2U(double a, int p);

void U2C(double a, int p)
{
    a = a / 6.20350;
    cout <<showpoint <<setprecision(p) << a << endl;
    // on the right side add 0      set precision       forced output point
}

void C2U(double a, int p)
{
    a = a * 6.20350;
    cout << showpoint << setprecision(p) << a << endl;
}

void ex2()
{
    int n;
    int prec;
    double amount;
    cin >> n;
    cin >> amount;
    cin >> prec;
    switch (n)
    {
    case 1:
        C2U(amount, prec);
        break;

    default:
        U2C(amount, prec);
        break;
    }
}

int main()
{
    ex2();
    return 0;
}
