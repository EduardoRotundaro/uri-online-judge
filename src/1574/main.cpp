#include<bits/stdc++.h>
using namespace std;

int move(char c){
	if(c=='L') return -1;
	return 1;
}

int toInteger(string s){
	int ans=0, ax=s.size()-1;
	for(int i=0;i<s.size();i++) ans+=(s[i]-'0')*pow(10.0,ax--);
	return ans;
}

int main(){

	int n, m, posicao, p;
	char linha[15];
	string aux;
	vector<char> v;

	cin>>n;
	while(n--){
		cin>>m; cin.ignore();
		posicao=0; v.clear(); v.push_back('x');
		while(m--){
			cin.getline(linha,15);
			if(linha[0]=='S'){
				aux.clear();
				for(int i=8;i<strlen(linha);i++) aux.push_back(linha[i]);
				v.push_back(v[toInteger(aux)]);
			}
			else v.push_back(linha[0]);
			posicao+=move(v.back());
		}
		printf("%d\n", posicao);
	}

	return 0;
}
