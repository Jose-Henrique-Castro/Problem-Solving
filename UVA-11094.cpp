#include <bits/stdc++.h>
using namespace std;

int L,C;
vector<vector<char>> mapa;
vector<vector<bool>> vis;
int cont_atual=0;

int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1}; 

void DFS(int i,int j,char alvo){
    
    if(i<0||i>=L) return;
    j = (j+C)%C; // cíclico , depois do final volta pro começo e depois do começo volta pro final
    if(vis[i][j]) return;
    if(mapa[i][j]!=alvo) return;

        
    cont_atual++;
    vis[i][j] = true;

    for(int r=0;r<4;r++){
        DFS(i+di[r],j+dj[r],alvo);
    }

}

int main() 
{

    while(cin >> L >> C) {

    
    mapa.resize(L,vector<char>(C));
    vis.assign(L,vector<bool>(C,false));
    for(int i=0;i<L;i++){
        for(int j=0;j<C;j++){
            cin >> mapa[i][j];
        }
    }

    int loc1,loc2; cin >> loc1 >> loc2;
    char loc_atual = mapa[loc1][loc2];
DFS(loc1,loc2,loc_atual);
int maior_continente = 0;

 for(int a=0;a<L;a++){
        for(int b=0;b<C;b++){
            if(mapa[a][b]==loc_atual && !vis[a][b]){
                cont_atual=0;
                DFS(a,b,loc_atual);
                if(cont_atual>maior_continente) maior_continente=cont_atual;
            }
        }
    }



cout << maior_continente << endl;
    }
    return 0;
}