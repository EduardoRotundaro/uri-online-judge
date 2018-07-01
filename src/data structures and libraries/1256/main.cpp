#include<bits/stdc++.h>
using namespace std;

int main(){

	int c, n, m, x, i, k;
	vector<int> tabela[101];
	vector<int>::iterator it;

	cin>>c;
	while(c--){
		cin>>n>>m;

		while(m--){
			cin>>x;
			k=x%n;
			tabela[k].push_back(x);
		}

		for(i=0;i<n;i++){
			printf("%d -> ", i);

			for(it=tabela[i].begin(); it!=tabela[i].end();it++) printf("%d -> ", *it);

			printf("\\\n");
		}
		if(c!=0) printf("\n");

		for(i=0;i<n;i++) tabela[i].clear();
	}


    return 0;
}
