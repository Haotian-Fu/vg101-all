//#include "assignment.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void ex3()
{
    ifstream fp("matrices.txt");
    ofstream fr("result.txt");
    static int matA[600][600];
    static int matB[600][600];
    static int matADD[600][600];
    static int matMULT[600][600];
    static int matA1[600][600];
    static int matB1[600][600];
    static int matMULT1[600][600];
    int cnt = 0;
    string s;

    if (fp.is_open() && fr.is_open())
    {
        while(getline(fp,s)){
            cnt++;
        }
        cnt = (cnt - 1) / 2;    //calculate the length of the matrice
    }
    else
    {
        cerr << "Unable to open the file(s).";
    }
    fp.clear();
    fp.seekg(0);
    int a;
    //scan part
    for(int i=0;i<cnt;i++){
        for(int j=0;j<cnt;j++){
            fp >> a;
            matA[i][j] = a;
        }
    }
    
    for(int i=0;i<cnt;i++){
        for(int j=0;j<cnt;j++){
            fp >> a;
            matB[i][j] = a;
        }
    }
    //add
    for(int i=0;i<cnt;i++){
        for(int j=0;j<cnt;j++){
            matADD[i][j]=matA[i][j]+matB[i][j];
        }
    }

    //multiply
    for(int i=0;i<cnt;i++){
        for(int j=0;j<cnt;j++){
            for(int n=0;n<cnt;n++){
                matMULT[i][j]+=matA[i][n]*matB[n][j];
            }
        }
    }

    //transportation
    for(int i=0;i<cnt;i++){
        for(int j=0;j<cnt;j++){
            matA1[i][j]=matA[j][i];
            matB1[i][j]=matB[j][i];
        }
    }

    for(int i=0;i<cnt;i++){
        for(int j=0;j<cnt;j++){
            for(int n=0;n<cnt;n++){
                matMULT1[i][j]+=matA1[i][n]*matB1[n][j];
            }
        }
    }

    //print part
    for(int i=0;i<cnt;i++){
        for(int j=0;j<cnt;j++){
            fr << matADD[i][j] << " ";
        }
        fr << "\n";
    }
    fr << endl;

    for(int i=0;i<cnt;i++){
        for(int j=0;j<cnt;j++){
            fr << matMULT[i][j] << " ";
        }
        fr << "\n";
    }
    fr << endl;
    
    for(int i=0;i<cnt;i++){
        for(int j=0;j<cnt;j++){
            fr << matMULT1[i][j] << " ";
        }
        fr << "\n";
    }
    fr << endl;


    fp.close();
    fr.close();
}
#ifndef JOJ
int main()
{
    ex3();
    return 0;
}
#endif

