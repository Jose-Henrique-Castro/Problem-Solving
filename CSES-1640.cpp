#include <bits/stdc++.h>
using namespace std;

map <int,int> numeros;
vector <int> somas;

vector <int> soma(vector <int>& nums,int alvo){

for ( int i=0;i<nums.size();i++){

int diferença = alvo - nums[i];

if(numeros.find(diferença)!= numeros.end()){ // se o numero que falta está no mapa , achamos a soma.

    somas.push_back(numeros[diferença]); // adiciona o indice do numero ja colocado e o indice do atual que completa a soma
    somas.push_back(i);
    return somas;
}

numeros[nums[i]] = i; // adiciona o numero e seu indice do vetor nums no map numeros
}


return somas;

}

int main() 
{

    int num , sum; cin >> num >> sum;
    vector <int> nums(num);
    for(int i=0;i<num;i++){
        cin >> nums[i];
    }

    vector <int> resultado = soma(nums,sum);

    if(!somas.empty()){
            cout << resultado[0]+1 << " " << resultado[1]+1 << endl;
    }
    else cout << "IMPOSSIBLE\n";

      return 0;
}