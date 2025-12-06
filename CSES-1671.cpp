#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define pb push_back

int main(){

int V,A; cin >> V >> A;

vector<vector<pair<int,int>>> adj(V+1);
priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
vector<long long> dist(V+1,1e18);

REP(i,A){
    int u,v,w; cin >> u >> v >> w;
    adj[u].pb({v,w});
}

dist[1] = 0;
pq.push({0,1}); // vertice,peso

while(!pq.empty()){

    long long d = pq.top().first;
    int v = pq.top().second;
    pq.pop();

    if(d!=dist[v]) continue;

    for(auto x : adj[v]){
        int viz = x.first;
        long long d_viz = x.second;

        if(d_viz+dist[v] < dist[viz] ){
            dist[viz] = d_viz+dist[v];
            pq.push({dist[viz],viz});
        }
    }
}

for(int i=1;i<dist.size();i++){
    i==dist.size()-1 ? cout << dist[i] : cout << dist[i] << " ";
}
cout << endl;


    return 0;
}