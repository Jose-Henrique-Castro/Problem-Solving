#include <bits/stdc++.h>
using namespace std;

int main() 
{

int N;
cin >> N; // Polygon sides

while(N>2){

    double R;
    cin >> R; // size of 2 sides of an isosceles triangle
 double A2 = 3.1415/N; // angle alpha / 2
 double L = 2*R*sin(A2); // size of the different size
 double H = R*cos(A2); // height of the triangle
 double AT = (L*H)/2; // traingle area
 double AP = AT*N; // polygon area
 cout << AP << endl;

 cin >> N; // automation of measuring different polygons

}
    return 0;
}