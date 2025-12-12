#include <bits/stdc++.h> 
using namespace std;
using p = pair<long long,long long>;

int main(){


    int cases; cin >> cases;
    bool first = true;
    while(cases--){

        int V,exit,timer,A; cin >> V >> exit >> timer >>  A;
        int cont = 0;
        vector<vector<p>> adj(V+1);
        vector<long long> dist (V+1,1e19);
        priority_queue<p,vector<p>,greater<p>> pq;

        for(int i=0;i<A;i++){
            int u,v,w;cin >> u >> v >> w;
            adj[v].push_back({u,w});
        }

        dist[exit]=0;
        pq.push({0,exit});

        while(!pq.empty()){

            int node = pq.top().second;
            int d= pq.top().first;
            pq.pop();

            if(d>dist[node]) continue;
            for(auto x:adj[node]){

                int viz = x.first;
                int dis = x.second;

                if(d+dis<dist[viz]){
                    dist[viz] = d+dis;
                    pq.push({dist[viz],viz});
                }

            }

        }
            
        for(int i=1;i<=V;i++){
            if(dist[i]<=timer) cont++;
        }

        if(!first) cout << endl;
        first = false;

        cout << cont <<  endl;
    
    }

    return 0;
}