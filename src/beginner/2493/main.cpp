#include <bits/stdc++.h>
using namespace std;

struct expre{
	long long int x, y, z;
};

int main(void){

	expre expres[52];
	int i, n, k;
	char c;
	char nome[52];
	map<string, int> mp;
	map<string, int>::iterator it;

	while(cin>>n){
		mp.clear();
		for(i=1;i<=n;i++){
			scanf("%lld %lld%c%lld", &expres[i].x, &expres[i].y, &c, &expres[i].z );
		}

		for(i=1;i<=n;i++){
			scanf("%s %d %c", &nome, &k, &c);

			if(c=='I'){
				if( (expres[k].x + expres[k].y) == expres[k].z ) mp[nome] = 1;
				else if( (expres[k].x - expres[k].y) == expres[k].z ) mp[nome] = 1;
				else if( (long long int) (expres[k].x * expres[k].y) == expres[k].z ) mp[nome] = 1;
			}
			else if(c=='+'){
				if( (long long int) (expres[k].x + expres[k].y) != expres[k].z ) mp[nome] = 1;
			}
			else if(c=='-'){
				if( (expres[k].x - expres[k].y) != expres[k].z ) mp[nome] = 1;
			}
			else{
				if( (long long int) (expres[k].x * expres[k].y) != expres[k].z ) mp[nome] = 1;
			}

		}

		if(mp.size()==0) printf("You Shall All Pass!\n");
		else if(mp.size()==n) printf("None Shall Pass!\n");
		else{
			int aux = 1;
			for(it=mp.begin();it!=mp.end();it++){
				cout<<it->first;
				if(aux!=mp.size()) printf(" ");
				aux++;
			}
			printf("\n");
		}
	}

	return 0;
}
