#include <bits/stdc++.h>
using namespace std;

vector <int> arr;
vector <long long> pref;

long long prefix_sum(int x,int y){ // 1 3 = 0 2 

return pref[y] - pref[x-1];

}

int main() 
{


int valores , testes; cin >> valores >> testes; // 1 2 3 4 5 //  0 1 3 6 10 15 // 

arr.resize(valores);
pref.resize(valores+1,0);

for(int i=0;i<valores;i++){
    cin >> arr[i];
}

    for(int i=0;i<valores;i++){
        pref[i+1] = arr[i] + pref[i];
    }
    //for(int i=1;i<=valores+1;i++){
      //  pref[i] = array[i-1] + pref[i-1];
    //}

for(int i=0;i<testes;i++){
    int p1,p2; cin >> p1 >> p2;
    cout << prefix_sum(p1,p2) << endl;
}

    return 0;
}