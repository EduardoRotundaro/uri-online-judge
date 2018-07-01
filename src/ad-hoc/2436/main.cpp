#include <bits/stdc++.h>
using namespace std;


int main(){

	int i, j, n, m, x, pc, pl;
	vector<int> mat[1003];

	cin>>n>>m>>pl>>pc;

	for(i=0;i<=m+1;i++) mat[0].push_back(0);
	for(i=1;i<=n;i++){
		mat[i].push_back(0);
		for(j=0;j<m;j++){
			cin>>x;
			mat[i].push_back(x);
		}
		mat[i].push_back(0);
	}
	for(j=0;j<=m;j++) mat[i].push_back(0);

	mat[pl][pc]=0;
	while(mat[pl-1][pc]==1 || mat[pl+1][pc]==1 || mat[pl][pc-1]==1 || mat[pl][pc+1]==1){
		if(mat[pl-1][pc]==1) mat[--pl][pc]=0;
		else if(mat[pl+1][pc]==1) mat[++pl][pc]=0;
		else if(mat[pl][pc-1]==1) mat[pl][--pc]=0;
		else if(mat[pl][pc+1]==1) mat[pl][++pc]=0;
	}

	cout<<pl<<" "<<pc<<endl;


	return 0;
}
