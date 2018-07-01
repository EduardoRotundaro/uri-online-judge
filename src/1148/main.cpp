#include<bits/stdc++.h>
using namespace std;

#define MAX 501
#define INF 9999999

int matriz_adjacencia[MAX][MAX];
int pai[MAX], distancia[MAX];
bool visitado[MAX];

void inicializa(int num_vertices){

	for(int i=0;i<num_vertices;i++){
		pai[i] = -1;
		distancia[i] = INF;
		visitado[i] = false;
	}

}

void dijkstra(int num_vertices, int origem, int destino){

	int x, y, peso, i, menor_distancia;

	inicializa(num_vertices);

	distancia[origem] = 0;

	x = origem;

	while(!visitado[x]){

		for(i=0;i<num_vertices;i++){
			if(matriz_adjacencia[x][i] != INF){
				y=i;
				peso=matriz_adjacencia[x][i];

				if( (distancia[x]+peso) < distancia[y] ){
					distancia[y] = distancia[x]+peso;
					pai[y] = x;
				}
			}

		}

		visitado[x] = true;

		menor_distancia = INF;

		for(i=0;i<num_vertices;i++){
			if(!visitado[i] && distancia[i]<menor_distancia){
				x=i;
				menor_distancia = distancia[i];
			}

		}

	}

}

int main(){

	int num_arestas, num_vertices, vertice_1, vertice_2, peso, i, j, origem, destino, n;

	cin>>num_vertices>>num_arestas;

	while(num_arestas!=0 || num_vertices!=0){

		for(i=0;i<num_vertices;i++){
			for(j=0;j<num_vertices;j++) matriz_adjacencia[i][j]=INF;
		}

		for(i=0;i<num_arestas;i++){
			scanf("%d %d %d",&vertice_1, &vertice_2, &peso);
			vertice_1--; vertice_2--;
			if(matriz_adjacencia[vertice_2][vertice_1]!=INF){
				matriz_adjacencia[vertice_1][vertice_2] = 0;
				matriz_adjacencia[vertice_2][vertice_1] = 0;
			}
			else{
				matriz_adjacencia[vertice_1][vertice_2] = peso;
			}
		}

		cin>>n;
		while(n--){
			cin>>origem>>destino;
			origem--; destino--;

			dijkstra(num_vertices, origem, destino);

			if(distancia[destino]==INF) printf("Nao e possivel entregar a carta\n");
			else printf("%d\n", distancia[destino]);

		}
		printf("\n");

		cin>>num_vertices>>num_arestas;

	}

	return 0;
}
