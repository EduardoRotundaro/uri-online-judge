#include<bits/stdc++.h>
using namespace std;

int sdk[10][10];

bool verifica(vector<int> v){
	sort(v.begin(),v.end());
	for(int i=0;i<9;i++) if(v[i]!=(i+1)) return false;
	return true;
}

bool solve(){
	int i, j;
	vector<int> aux;

	for(i=0;i<9;i++){
		aux.clear();
		for(j=0;j<9;j++) aux.push_back(sdk[i][j]);
		if(!verifica(aux)) return false;
	}
	for(i=0;i<9;i++){
		aux.clear();
		for(j=0;j<9;j++) aux.push_back(sdk[j][i]);
		if(!verifica(aux)) return false;
	}

	aux.clear();
	for(i=0;i<3;i++) for(j=0;j<3;j++) aux.push_back(sdk[i][j]);
	if(!verifica(aux)) return false;

	aux.clear();
	for(i=0;i<3;i++) for(j=3;j<6;j++) aux.push_back(sdk[i][j]);
	if(!verifica(aux)) return false;

	aux.clear();
	for(i=0;i<3;i++) for(j=6;j<9;j++) aux.push_back(sdk[i][j]);
	if(!verifica(aux)) return false;

	aux.clear();
	for(i=3;i<6;i++) for(j=0;j<3;j++) aux.push_back(sdk[i][j]);
	if(!verifica(aux)) return false;

	aux.clear();
	for(i=3;i<6;i++) for(j=3;j<6;j++) aux.push_back(sdk[i][j]);
	if(!verifica(aux)) return false;

	aux.clear();
	for(i=3;i<6;i++) for(j=6;j<9;j++) aux.push_back(sdk[i][j]);
	if(!verifica(aux)) return false;

	aux.clear();
	for(i=6;i<9;i++) for(j=0;j<3;j++) aux.push_back(sdk[i][j]);
	if(!verifica(aux)) return false;

	aux.clear();
	for(i=6;i<9;i++) for(j=3;j<6;j++) aux.push_back(sdk[i][j]);
	if(!verifica(aux)) return false;

	aux.clear();
	for(i=6;i<9;i++) for(j=6;j<9;j++) aux.push_back(sdk[i][j]);
	if(!verifica(aux)) return false;

	return true;
}

int main(){

	int n, inst=1;

	cin>>n;
	while(n--){
		for(int i=0;i<9;i++) for(int j=0;j<9;j++) cin>>sdk[i][j];

		printf("Instancia %d\n", inst++);
		if(solve()) printf("SIM\n\n");
		else printf("NAO\n\n");
	}

	return 0;
}
