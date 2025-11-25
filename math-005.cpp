#include <bits/stdc++.h>
using namespace std;

int main() 
{

    int QTD; cin >> QTD; // successive approximations for square root
    double y; cin >> y;
    double x = y/2.0;

    for(int i=2;i<=QTD;i++){ // automation 
        x = (x*x+y)/(2*x);
    }

    cout << x << endl;

    return 0;
}