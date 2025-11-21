#include <bits/stdc++.h>
using namespace std;

int main() 
{

// S = -2/3 + 5/5 - 8/7 + 11/9 - 14/11...

int num; // number of times realizing automation
cin >> num;

double S=0;
int sinal = -1;
for (int i=1;i<=num;i++) {
    S += (3*(double)i-1)/(2*i+1)*sinal;
    sinal*=-1;
}

cout << S << endl;

      return 0;
}