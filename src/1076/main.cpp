#include<bits/stdc++.h>
using namespace std;

#define MAX 1000

bool visitado[MAX];
vector< int > lista_adjacencia[MAX];
int cont;

void dfs(int u){
	int v, i;

	visitado[u] = true;
	int t = lista_adjacencia[u].size();

	for(i=0;i<t;i++){
		v = lista_adjacencia[u][i];
		if(!visitado[v]){
			cont++;
			dfs(v);
		}
	}

}

int main(){

	int num_arestas, num_vertices, vertice_1, vertice_2, t, i, nodo;

	cin>>t;
	while(t--){

		cin>>nodo>>num_vertices>>num_arestas;

		for(i=0;i<num_vertices;i++){
			visitado[i] = false;
			lista_adjacencia[i].clear();
		}

		for(i=0;i<num_arestas;i++){
			cin>>vertice_1>>vertice_2;
			lista_adjacencia[vertice_1].push_back( vertice_2 );
			lista_adjacencia[vertice_2].push_back( vertice_1 );
		}

		cont=0;
		dfs(nodo);

		cout<<2*cont<<endl;
	}

	return 0;
}
