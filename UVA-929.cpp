#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using p = pair<long long,long long>;
using tup = tuple<int,int,int>;

int dl[] = {-1,1,0,0};
int dc[] = {0,0,-1,1};

void solve(){

ll L,C; cin >> L >> C;

vector<vector<ll>> grid(L,vector <ll>(C));
for(int i=0;i<L;i++){
    for(int j=0;j<C;j++){
        cin >> grid[i][j]; // lendo custo do local
    }
}

vector<vector<ll>> dist(L,vector<ll>(C,1e18));
priority_queue<tup,vector<tup>,greater<tup>> pq;

dist[0][0] = grid[0][0];
pq.push({grid[0][0],0,0}); // custo , linha , coluna

while(!pq.empty()){

auto [dis_atual,l,c] = pq.top();
pq.pop();

if(dis_atual>dist[l][c]) continue;
if(l==L-1 && c==C-1) {
    cout << dis_atual << endl;
    return;
}

for(int i=0;i<4;i++){
    int nl = dl[i] + l;
    int nc = dc[i] + c;

    if(nl >=0 && nl<L && nc>=0 && nc<C){

        if(dist[l][c]+grid[nl][nc]<dist[nl][nc]){
            dist[nl][nc] = dist[l][c]+grid[nl][nc];
            pq.push({dist[nl][nc],nl,nc});
        }
    }
}

}

}

int main(){

int cases; cin >> cases;
while(cases--) solve();
    return 0;
}