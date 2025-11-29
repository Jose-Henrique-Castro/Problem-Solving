#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> casa;
vector <bool> vis;
int maior_distancia = -1;
int pontaA = -1;

void DFS(int u,int d){

    vis[u] = true;
    if(d>maior_distancia){
        maior_distancia = d;
        pontaA = u;
    }

    for(auto x: casa[u]){
        if(!vis[x]){
            DFS(x,d+1);
        }
    }

}

int main() 
{

int nodes; cin >> nodes;

casa.resize(nodes+1);
vis.resize(nodes+1,0);

for(int i=0;i<nodes-1;i++){

    int u,v; cin >> u >> v;
    casa[u].push_back(v);
    casa[v].push_back(u);

}

DFS(1,0);


int ponta = pontaA;

maior_distancia = -1;
fill(vis.begin(),vis.end(),false);
DFS(ponta,0);

cout << maior_distancia << endl;

  return 0;
}