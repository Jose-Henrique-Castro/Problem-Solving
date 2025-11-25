#include <bits/stdc++.h>
using namespace std;

int main(){

    int servidores , comandos;
    cin >> servidores >> comandos;

    map <string,string> codigo;

    for(int i=0;i<servidores;i++){
        string nome; string ip;
        cin >> nome >> ip;
        codigo[ip] = nome;
    }

    for(int i=0;i<comandos;i++){
        string comando; string ip_alvo;
        cin >> comando >> ip_alvo;
        
        
    
    cout << comando << " " << ip_alvo << " " << "#";
    ip_alvo.pop_back();
    cout << codigo[ip_alvo] << endl;

            
        }
    


    return 0;
}

// n servidores com: 
// ips([unicos])
// name(não unicos)
// usar  map