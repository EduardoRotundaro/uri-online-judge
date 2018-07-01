#include<bits/stdc++.h>
using namespace std;

bool compara(string a, string b){

	int i, tm, erro=0;

	tm=a.size();
	for(i=0;i<tm;i++){
		if(a[i]!=b[i]) erro++;
	}

	if(erro>1) return true;
	return false;
}

int main(){

	int m, n, cont;
	string nome, assin;
	map<string,string> mp;

	cin>>n;
	while(n!=0){

		cin.ignore();
		while(n--){
			cin>>nome>>assin;
			mp[nome]=assin;
		}

		cin>>m;
		cin.ignore();
		cont=0;
		while(m--){
			cin>>nome>>assin;
			if( compara(assin, mp[nome] ) ) cont++;
		}

		cout<<cont<<endl;

		cin>>n;
	}
		
	return 0;
}
