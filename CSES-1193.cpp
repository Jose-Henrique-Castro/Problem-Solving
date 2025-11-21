#include <bits/stdc++.h>
using namespace std;

int L,C;
vector<vector<char>> mapa;
vector<vector<bool>> vis;
int cont = 0;
vector<char> dir;
vector<char> menor_caminho;
int menor_tam = 99999;
bool achei_B = false;

int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};
char move_[4] = {'D','U','R','L'};

void DFS(int i,int j){
     if(dir.size()>=menor_tam) return;
     if(i<0||i>=L||j<0||j>=C) return;
     if(mapa[i][j]=='#') return;
     if(vis[i][j]) return;
     if(mapa[i][j]=='B'){
          if(dir.size()<menor_tam){
               menor_tam = dir.size();
               menor_caminho = dir;
          }
          return;
     }
     

     vis[i][j] = true;

     for(int r=0;r<4;r++){
          int ni = i+di[r];
          int nj = j+dj[r];
          char movi_atual = move_[r];
          dir.push_back(movi_atual);

          DFS(ni,nj);

          dir.pop_back();
     }
    
vis[i][j] = false; // deixar caminho livre para comparação
}

int main() 
{

     cin >> L >> C;
     mapa.resize(L,vector<char>(C));
     vis.resize(L,vector<bool>(C,false));

     int loc1 , loc2;

     for(int i=0;i<L;i++){
          for(int j=0;j<C;j++){
               cin >> mapa[i][j];
               if(mapa[i][j]=='A') {
                    loc1 = i;
                    loc2 = j;
               }
          }
     }

     DFS(loc1,loc2);
     

     if(menor_tam == 99999) cout << "NO" << endl;
     else{
          cout << "YES" << endl;
          cout << menor_tam << endl;
          for(auto x:menor_caminho){
               cout << x;
          }
          cout << endl;
     }
    
    
     return 0;
}