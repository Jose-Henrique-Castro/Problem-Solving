#include <bits/stdc++.h>
using namespace std;

int tam;
vector<vector<char>> mapa;
vector<vector<bool>> vis;

int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

void DFS(int x,int y){

if(x<0||x>=tam||y<0||y>=tam) return;
if(vis[x][y]) return;
if(mapa[x][y]== '0') return;

vis[x][y] = true;

for(int i=0;i<8;i++){
    DFS(x+dx[i],y+dy[i]);
}

return;
}

int main() 
{
    int t = 1;
    while(cin >> tam){
        
        mapa.assign(tam,vector<char>(tam));
        vis.assign(tam,vector<bool>(tam,false));

        vector<pair<int,int>> p;

        for(int i=0;i<tam;i++){
            for(int j=0;j<tam;j++){
                cin >> mapa[i][j];
                if(mapa[i][j]=='1'){
                    p.push_back({i,j});
                }
            }
        }
            int cont=0;

        for(auto pair : p){

            int k = pair.first;
            int n = pair.second;

            if(!vis[k][n]){
                cont++;
                DFS(k,n);
            }
            
        }

        cout << "Image number " << t << " contains " << cont << " war eagles." << endl; 

        t++;
    }


      return 0;
}