#include<bits/stdc++.h>
using namespace std;

#define MAX 50

vector<int> lista_adjacencia[MAX];
bool visitado[MAX];

static void reachR(int v){

	int a;

	visitado[v] = true;

	for(a=0; a<lista_adjacencia[v].size(); a ++)
		if(!visitado[ lista_adjacencia[v][a] ]) reachR(lista_adjacencia[v][a]);

}

bool existe_um_caminho(int num_vertices, int origem, int destino){

	int v;

	for(v=1; v<=num_vertices; v++) visitado[v] = false;

	reachR(origem);

	if (!visitado[destino]) return false;
	return true;//else
}


int main(){

	int i,j, n, aux=1;
	bool existe_caminho;
	int mp[10][10], vert[10][10];

	for(i=0;i<7;i++){
		mp[0][i]=1; mp[6][i]=1; mp[i][0]=1; mp[i][6]=1;
	}

	cin>>n;

	while(n--){

		aux=1;
		for(i=1;i<6;i++){
			for(j=1;j<6;j++){
				cin>>mp[i][j];
				vert[i][j]=aux++;
			}
		}

		for(i=1;i<6;i++){
			for(j=1;j<6;j++){
				if(mp[i][j]==0 && mp[i][j+1]==0) lista_adjacencia[ vert[i][j] ].push_back( vert[i][j+1] );
				if(mp[i][j]==0 && mp[i+1][j]==0) lista_adjacencia[ vert[i][j] ].push_back( vert[i+1][j] );
				if(mp[i][j]==0 && mp[i][j-1]==0) lista_adjacencia[ vert[i][j] ].push_back( vert[i][j-1] );
				if(mp[i][j]==0 && mp[i-1][j]==0) lista_adjacencia[ vert[i][j] ].push_back( vert[i-1][j] );
			}
		}

		existe_caminho = existe_um_caminho(25, 1, 25);

		if(existe_caminho) cout<<"COPS\n";
		else cout<<"ROBBERS\n";

		for(i=1;i<26;i++) lista_adjacencia[i].clear();
	}

	return 0;
}
