#include <bits/stdc++.h>
using namespace std;

int L,C;
vector<vector<char>> mapa;
vector <vector<bool>> vis;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void DFS (int i,int j){

if(i<0 || j<0 || i>=L || j>=C) return;
if(mapa[i][j]!='.') return;
if(vis[i][j]) return;

vis[i][j]=true;

for(int r=0;r<4;r++){
    DFS(i+dx[r],j+dy[r]);
}

}

int main() 
{

cin >> L >> C;
mapa.resize(L,vector<char>(C));
vis.resize(L,vector<bool>(C,0));

vector<pair<int,int>> p;

for(int i=0;i<L;i++){
    for(int j=0;j<C;j++){
        cin >> mapa[i][j];
        if(mapa[i][j] == '.') p.push_back({i,j});
    }
}
int cont = 0;
for(auto pair : p){
    int k = pair.first;
    int n = pair.second;

    if(!vis[k][n]) {
        cont++;
        DFS(k,n);
}
}
cout << cont << endl;

     return 0;

}