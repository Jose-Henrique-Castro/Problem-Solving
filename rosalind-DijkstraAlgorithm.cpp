#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define pb push_back

int main(){

    int V , A; cin >> V >> A; // Vértices , Arestas
    vector<vector<pair<int,int>>> adj(V+1); // vértices ligados

    REP(i,A){ // ler coneções dos vertices e seus custos
        int u,v,w; cin >> u >> v >> w;
        adj[u].pb({v,w}); // unidirecional
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; // lista de prioridade ordem crescente

    vector<int> dist(V+1,INT_MAX); // começa com o maior valor possível

    dist[1] = 0;
    pq.push({1,0}); // vértice - peso

    while(!pq.empty()){

        int v = pq.top().first; // 2 4 3
        int d = pq.top().second; // 2 3 
        pq.pop();

        if(d!= dist[v]) continue; // corrije novas vindas do vertices com distancias antigas

        for(auto pair: adj[v]){
            int u = pair.first; // vizinho
            int peso = pair.second; // distancia

            if(peso + dist[v] < dist[u] ) { // 
                dist[u] = peso + dist[v];
                pq.push({u,dist[u]});
            }
        }
    }

    for(int i=1;i<dist.size();i++){
        if(dist[i]==INT_MAX) dist[i] = -1;
        i==dist.size()-1 ? cout << dist[i] : cout << dist[i] <<  " ";
    }
    cout << endl;
        

    return 0;
}