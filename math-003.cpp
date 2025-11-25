#include <bits/stdc++.h>
using namespace std;

int main() 
{

// S = 2/1! + 4/2! + 6/3! + 8/4!...

int num;// number of times realizing automation
cin >> num;

int fat=1;
double S=0;
for (int i=1;i<=num;i++) {
fat*=i;
S += (2*(double)i)/(double)fat;
}

cout << S << endl;

    return 0;
}