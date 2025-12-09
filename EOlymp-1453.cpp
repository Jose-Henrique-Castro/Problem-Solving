#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
using p = pair<int,int>;
#define REP(i,n) for(int i=0;i<n;i++)

int main(){

    int V , A; cin >> V >> A;
    vector<vector<pair<int,int>>> adj(V+1);
    vector <ll> dist(V+1,30000);

    REP(i,A){
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }

    dist[1] = 0;

    REP(i,V-1){
        for(int u=1;u<=V;u++){

            if(dist[u] == 30000) continue;

            for(auto x : adj[u]){
            int viz = x.first;
            int dis = x.second;

            if(dist[u]+dis < dist[viz]){
                dist[viz] = dist[u]+dis;
            }
        }
        }
    }

    for(int i=1;i<=V;i++){
        i == V ? cout << dist[i] : cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}