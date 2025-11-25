#include <bits/stdc++.h>
using namespace std;

int main() 
{

// S = 1 + 3/5 + 5/11 + 7/16 + 9/21...

int num; // number of times realizing automation
cin >> num;

double S=0;

for(int i=1;i<=num;i++){
    S+= (2*(double)i-1)/(5*i-4);
}

cout << S << endl;

     return 0;
}