#include <bits/stdc++.h>
using namespace std;

int main(){

int testes , tam; cin >> testes;

while(testes--){
    cin >> tam;
vector<int> numeros(tam);
vector<int> iguais;
for(int i=0;i<tam;i++){
    cin >> numeros[i];
}

iguais.push_back(0);

int left = 0;
int right = tam-1;

int sumL = numeros[left] , sumR = numeros[right];
int cont = 2;
while(left < right){
    if(sumL==sumR) {
        iguais.push_back(cont);
        left++;
        right--;
        if(left<right){
          sumL += numeros[left];
        sumR += numeros[right];
        cont += 2;  
        }
    }

    else if(sumL>sumR){  
        right--;
        if(left<right){
        sumR += numeros[right];
        cont++;
        }
    }

    else {
        left++;
        if(left<right){
        sumL += numeros[left];
        cont++;
        }
    }
    
}

int j = iguais.size()-1;
int resultado = iguais[j];

cout << resultado << endl;

}

 return 0;
}




   
