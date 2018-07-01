#include<bits/stdc++.h>
using namespace std;

int solve(set<int> a, set<int> b){
	set<int>::iterator it;

	int qa=0, qb=0;

	for(it=a.begin();it!=a.end();it++) if(!b.count(*it)) qb++;
	for(it=b.begin();it!=b.end();it++) if(!a.count(*it)) qa++;

	return min(qa,qb);
}

int main(){

	set<int> conj_a;
	set<int> conj_b;
	int n, m, x;

	cin>>n>>m;
	while(n || m){
		while(n--){
			cin>>x;
			conj_a.insert(x);
		}
		while(m--){
			cin>>x;
			conj_b.insert(x);
		}

		cout<<solve(conj_a,conj_b)<<endl;

		conj_a.clear(); conj_b.clear();
		cin>>n>>m;
	}

	return 0;
}
