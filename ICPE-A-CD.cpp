#include <bits/stdc++.h>
using namespace std;

int main() 
{
int cds_jack , cds_jill;
    cin >> cds_jack >> cds_jill;

    while(cds_jack!=0 && cds_jill!=0){

        vector <int> jack;
        vector <int> jill;
        int tam = cds_jack+cds_jill;
        set <int> total;

        for(int i=0;i<cds_jack;i++){
            int x; cin >> x;
            jack.push_back(x);
            total.insert(x);
        }

        for(int i=0;i<cds_jill;i++){
            int x; cin >> x;
            jill.push_back(x);
            total.insert(x);
        }

        int resultado = tam - total.size();

        cout << resultado << endl;

        cin >> cds_jack >> cds_jill;
    }
    return 0;
}