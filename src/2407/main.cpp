#include<bits/stdc++.h>
using namespace std;

vector<long long int> v[1002];
int i, j;

unsigned long long int testa(int n){

	unsigned long long int ans=0, aux1, aux2, aux3=0;

	for(i=0;i<n;i++) ans+=v[0][i];
	for(i=0;i<n;i++){
		aux1=aux2=0;
		for(j=0;j<n;j++){
			aux1+=v[i][j];
			aux2+=v[j][i];
			if(i==j) aux3+=v[i][i];;
		}
		if(aux1!=ans) return 0;
		if(aux2!=ans) return 0;
	}
	if(aux3!=ans) return 0;

	aux1=0;
	int a=n-1;
	for(i=0;i<n;i++){
		aux1+=v[a--][i];
	}
	if(aux1!=ans) return 0;

	return ans;
}

int main(){

	int n;
	long long int x;
	unsigned long long int resp;
	map<long long int, int> mp;
	map<long long int, int>::iterator it;
	bool num=true;

	cin>>n;

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%lld", &x);
			v[i].push_back(x);
			if(!mp.count(x)) mp[x]=1;
		}
	}

	it=mp.end();
	--it;
	if(mp.size()!=n*n || it->first!=n*n) num=false;

	if(!num) cout<<"0\n";
	else{
		resp = testa(n);
		if(resp>0) cout<<resp<<endl;
		else cout<<"0\n";
	}

	return 0;
}
