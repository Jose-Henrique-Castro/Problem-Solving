#include <bits/stdc++.h>
using namespace std;

int main() 
{

    int postos; cin >> postos;

    while(postos!=0){
    bool flag = true;
    vector <int> distancia;
        for(int i=0;i<postos;i++){
                int x; cin >> x;
                distancia.push_back(x);
        }

        sort(distancia.begin(),distancia.end());
        

        for(int i=0;i<postos-1;i++){
            if(distancia[i+1]-distancia[i]>200) {
                flag = false;
                break;
            }
        }
        if(flag){
            int dis_fim = 1422 - distancia[postos-1];
            if(2*dis_fim>200) cout << "IMPOSSIBLE\n";
            else cout << "POSSIBLE\n";
        }
        else {
            cout << "IMPOSSIBLE\n";
        }

        //22*2 = 44 < 200 = possible

        cin >> postos;
    }
    
     return 0;
}