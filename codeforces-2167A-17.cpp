#include <bits/stdc++.h>
using namespace std;
int main(){
 
    int testes;
    
    cin >> testes;
   for ( int i=0;i<testes;i++) {
    int vetor[4];
 
    for (int j=0;j<4;j++){
        cin >> vetor[j];
    }
 
    if(vetor[0]==vetor[1]&&vetor[1]==vetor[2]&&vetor[2]==vetor[3]) {
        cout << "YES\n";
    }
    else cout << "NO\n";
 
   }
 
 
 
 
return 0;
}