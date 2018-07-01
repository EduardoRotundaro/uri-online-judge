#include<bits/stdc++.h>
using namespace std;

vector<int> pset;
vector<pair<int, pair<int,int> > > edges;
long long int custo;
int V, E;

void init(int V) {
    for(int i=0; i<V; i++)
        pset.push_back(i);
}

int findset(int x) {
    if (x != pset[x])
        pset[x] = findset(pset[x]);
    return pset[x];
}

bool sameset(int x, int y){
    return findset(x) == findset(y);
}

void unionset(int x, int y, int c) {
     x = findset(x);
    y = findset(y);
    if(x != y){
        pset[x] = y;
        custo += c;
    }
}

int main(){

    int u, c, v, x, y, k;

	cin>>V>>E;

    while(V!=0 || E!=0){

    	for(k=0;k<E;k++){
    		cin>>u>>v>>c;
    		edges.push_back( make_pair(c, make_pair(u,v)) );
		}

		custo = 0;
    	sort(edges.begin(), edges.end());

    	pset.clear();
		init(V);

		for(int i=0; i<E; i++){
        	x = edges[i].second.first;
        	y = edges[i].second.second;
        	c = edges[i].first;
        	unionset(x, y, c);
		}

		cout<<custo<<endl;

    	edges.clear();
    	cin>>V>>E;
	}

	return 0;
}
