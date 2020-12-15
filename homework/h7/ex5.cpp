#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

static const char GRADES[] = {'F', 'F', 'F', 'F', 'F', 'F', 'D', 'C', 'B', 'A', 'A'};

struct Grade
{
    char ltr;
    int prct;
};

void GradePrct(Grade &grade, int prct)
{
    grade.prct = prct;
    grade.ltr = GRADES[prct / 10];
}

void GradeLtr(Grade &grade, char ltr)
{
    grade.ltr = ltr;
    grade.prct = 100 - (ltr - 'A') * 10 - 5;
}

void printGrade(Grade grade)
{
    cout << "Grade: " << grade.prct << " -> " << grade.ltr << endl;
}

int main()
{
    Grade g;
    int prct;
    char ltr;
    cout << "Input two space seprated grades (1st in %%, 2nd in letter): " << endl;
    cin >> prct;
    cin >> ltr;
    GradePrct(g, prct);
    printGrade(g);
    GradeLtr(g, ltr);
    printGrade(g);
    return 0;
}
