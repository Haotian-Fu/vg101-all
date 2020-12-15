#include "assignment.h"
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <cstdlib>

using namespace std;

void ex1_reverse_array()
{
    string s[10000];
    int i = 0;
    string input;
    while (cin >> input)
    {
        s[i] = input;
        i++;
        if (cin.get() == '\n')
            break;
    }
    for (int x = i - 1; x >= 0; x--)
    {
        cout << s[x] << ' ';
    }
    cout << endl;
}

void ex1_reverse_vector()
{
    vector<string> vs; //vector string
    string input;
    while (cin >> input)
    {
        vs.insert(vs.begin(), input);
        if (cin.get() == '\n')
            break;
    }
    for (auto &&x : vs)
    {
        cout << x << ' ';
    }
    cout << endl;
}

void ex1_reverse_stack()
{
    stack<string> ss; //stack string
    string input;
    while (cin >> input)
    {
        ss.push(input);
        if (cin.get() == '\n')
            break;
    }
    while (!ss.empty())
    {
        cout << ss.top() << ' ';
        ss.pop();
    }
    cout << endl;
}

void ex1_ordered_array()
{
    string s[10000];
    int i = 0;
    string input;
    while (cin >> input)
    {
        s[i] = input;
        cout << s[i] << ' ';
        i++;
    }
    cout << endl;
}

void ex1_ordered_vector()
{
    vector<string> vs;
    string input;
    while (cin >> input)
    {
        vs.push_back(input);
        if (cin.get() == '\n')
            break;
    }
    for (auto &&x : vs)
    {
        cout << x << ' ';
    }
    cout << endl;
}

void ex1_ordered_queue()
{
    queue<string> qs; //queue string
    string input;
    while (cin >> input)
    {
        qs.push(input);
        if (cin.get() == '\n')
            break;
    }
    while (!qs.empty())
    {
        cout << qs.front() << ' ';
        qs.pop();
    }
    cout << endl;
}

