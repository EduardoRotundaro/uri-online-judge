#include<bits/stdc++.h>
using namespace std;

#define MAX 100005

vector<int> lista_adjacencia[MAX];
int id_v[MAX];

static void dfss(int v, int id){

	int a;

	id_v[v] = id;

   	for (a=0; a<lista_adjacencia[v].size(); a++)
	   if (id_v[ lista_adjacencia[v][a] ] == -1) dfss(lista_adjacencia[v][a], id);

}

int numero_de_componentes(int num_vertices){

	int v, id=0;

	for(v=0; v<num_vertices; v++) id_v[v] = -1;

	for(v=0; v<num_vertices; v++) if(id_v[v] == -1) dfss(v, id++);

	return id;
}

int main(){

	int num_arestas, num_vertices, i, nc, vertice_1, vertice_2;

	cin>>num_vertices>>num_arestas;

	for(i=0;i<num_vertices;i++){
		lista_adjacencia[i].clear();
	}

	for(i=0;i<num_arestas;i++){
		cin>>vertice_1>>vertice_2;
		lista_adjacencia[ --vertice_1 ].push_back( --vertice_2 );
		lista_adjacencia[ vertice_2 ].push_back( vertice_1 );
	}

	nc = numero_de_componentes(num_vertices);

	cout<<nc<<endl;

	return 0;
}
