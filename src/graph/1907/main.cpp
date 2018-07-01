#include<bits/stdc++.h>
using namespace std;

vector<char> mat[1025];
vector<int> visitado[1025];

void dfs(int x, int y, int d1, int d2){

	int xx=x, yy=y;

	if(visitado[xx][yy]==1) return;
	visitado[xx][yy]=1;

	//direita
	yy++;
	if(yy<d2 and mat[xx][yy]=='.') dfs(xx,yy, d1, d2);
	yy--;

	xx++;
	if(xx<d1 and mat[xx][yy]=='.') dfs(xx,yy, d1, d2);
	xx--;

	yy--;
	if(yy>=0 and mat[xx][yy]=='.') dfs(xx,yy, d1, d2);
	yy++;

	xx--;
	if(xx>=0 and mat[xx][yy]=='.') dfs(xx,yy, d1, d2);
	xx++;
}

int num_comp(int d1, int d2){
	int cont=0;

	for(int i=0;i<d1;i++)
		for(int j=0;j<d2;j++)
			if(mat[i][j]=='.' && visitado[i][j]==0){
				cont++;
				dfs(i, j, d1,d2);
			}

	return cont;
}


int main(){

	int n, m, i, j;
	char c;

	cin>>n>>m;
	cin.ignore();

	for(i=0;i<n;i++)
		for(j=0;j<m;j++){
			cin>>c;
			visitado[i].push_back(0);
			mat[i].push_back(c);
		}

	int ans = num_comp(n, m);

	printf("%d\n",ans);

	return 0;
}
