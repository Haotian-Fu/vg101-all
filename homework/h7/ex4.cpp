//#include "assignment.h"
#include <iterator>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void q1();
void q2();

void q1()
{
    long a;
    long N = 0;
    cin >> a;
    while (a != 1)
    {
        if (a % 2 == 0)
        {
            a = a / 2;
        }
        else
        {
            a = 3 * a + 1;
        }
        N++;
    }
    cout << N << endl;
}

void q2()
{
    long M;
    cin >> M;
    // if (M == 2)
    // {
    //     cout << 2 << endl;
    // }
    // else
    // {
    //     vector<long> N((unsigned long int )M + 1);
    //     N[1] = 0;

    //     long temp = M;int cnt = 0;
    //     for (long i = 2; i <= M; i++)
    //     {
            
    //         while (temp >= i)
    //         {
    //             if (temp % 2 == 0)
    //             {
    //                 temp = temp / 2;
    //             }
    //             else
    //             {
    //                 temp = 3 * temp + 1;
    //             }
    //             cnt++;
    //         }
    //         N.push_back(cnt+N[(unsigned long int )temp]);
    //     }
    //     cout<<*max_element(N.begin(),N.end())<<endl;
    // }
    vector<long> N((unsigned)M + 1);
    N[0] = N[1] = 1;
    for (int i = 2; i <= M; ++i)
    {
        long temp = i;
        long cnt = 0;
        while (temp >= i)
        {
            if (temp % 2 == 0)
            {
                temp /= 2;
            }
            else
            {
                temp = 3 * temp + 1;
            }
            ++cnt;
        }
        N[(unsigned)i] = cnt+N[(unsigned)temp];     //important
    }
    cout<<max_element(N.begin(),N.end()) - N.begin()<<endl;
    // for (auto i : N) cerr << i << ' ';
    // cerr << endl;        //print N
}

void ex4()
{
    long q;
    cin >> q;
    switch (q)
    {
    case 1:
        q1();
        break;

    default:
        q2();
        break;
    }
}

//#ifndef JOJ
int main()
{
    ex4();
    return 0;
}
//#endif
