#include<bits/stdc++.h>
using namespace std;

#define MAX 2001

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

	for(v=0; v<num_vertices; v++) visitado[v] = false;

	reachR(origem);

	if (!visitado[destino]) return false;
	return true;
}

int main(){

	int orientado, num_arestas, num_vertices, vertice_1, vertice_2, i, j;
	bool existe_caminho, sim;
	set< pair<int, int> > nao;

	cin>>num_vertices>>num_arestas;

	while(num_vertices!=0 || num_arestas!=0){

		for(i=0;i<num_arestas;i++){
			scanf("%d %d %d", &vertice_1, &vertice_2, &orientado);
			lista_adjacencia[--vertice_1].push_back( --vertice_2 );
			if(orientado==2){
				lista_adjacencia[vertice_2].push_back( vertice_1 );
				nao.insert( make_pair(vertice_1,vertice_2) );
				nao.insert( make_pair(vertice_2,vertice_1) );
			}
		}

		sim=true;
		for(i=0;i<num_vertices;i++){
			for(j=i+1;j<num_vertices;j++){
				if(!nao.count( make_pair(i,j) ) && !nao.count( make_pair(i,j) ) ){
					if( !existe_um_caminho(num_vertices, i, j) || !existe_um_caminho(num_vertices, j, i) ) { sim=false; i=num_vertices; break;}
				}
			}
		}

		if(sim) cout<<"1\n";
		else cout<<"0\n";

		for(i=0;i<num_vertices;i++) lista_adjacencia[i].clear();
		nao.clear();

		cin>>num_vertices>>num_arestas;
	}

	return 0;
}
