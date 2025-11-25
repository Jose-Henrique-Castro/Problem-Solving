#include <bits/stdc++.h>
using namespace std;

int main() 
{

    long long nums ,alvo, valor; cin >> nums >> valor;
    vector <pair<int,int>> numeros(nums); 

    for(int i=0;i<nums;i++){
        cin >> numeros[i].first;
        numeros[i].second = i+1;
    }

    sort(numeros.begin(),numeros.end()); // [ 1 2 5 7 ]

    
    for (int i=0;i<nums;i++){

        if(i>0 && numeros[i].first ==numeros[i-1].first ) continue;

        long long num = numeros[i].first; // 1

       alvo = valor - num; //  8 - 1 = 7

        int left = i+1; // 1
        int right = nums-1; // 3

        while(left<right){
            long long sum = (long long)numeros[left].first + numeros[right].first;
                if(alvo==sum){
                    
                    cout << numeros[i].second << " " <<  numeros[left].second << " " << numeros[right].second << endl;

                    return 0;
                }
                else if(sum>alvo) right--;
                else left ++;
        }

    }
    cout << "IMPOSSIBLE" << endl;

  
    return 0;
}