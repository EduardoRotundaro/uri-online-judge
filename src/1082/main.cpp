#include<bits/stdc++.h>
using namespace std;

#define MAX 100

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

	int num_arestas, num_vertices, i, j, teste=1, nc;
	char vertice_1, vertice_2;
	int n;

	cin>>n;

	while(n--){

		cin>>num_vertices>>num_arestas;
		cin.ignore();

		for(i=0;i<num_vertices;i++){
			lista_adjacencia[i].clear();
		}

		for(i=0;i<num_arestas;i++){
			cin>>vertice_1>>vertice_2;
			lista_adjacencia[ (int) vertice_1-'a' ].push_back( (int) vertice_2-'a' );
			lista_adjacencia[ (int) vertice_2-'a' ].push_back( (int) vertice_1-'a' );
		}

		nc = numero_de_componentes(num_vertices);

		printf("Case #%d:\n", teste++);

		for(i=0;i<nc;i++){

			for(j=0;j<num_vertices;j++){
				if(id_v[j]==i) printf("%c,", (char) j+97 );
			}
			cout<<endl;

		}
		printf("%d connected components\n\n", nc);
	}

	return 0;
}
