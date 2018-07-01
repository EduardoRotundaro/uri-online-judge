#include <bits/stdc++.h>
using namespace std;

int main(void){

	int n, tm, i;
	long long int x, apagou;
	char lp[62];
	char c;

	cin>>n;

	while(n--){
		cin>>lp>>x;

		tm = strlen(lp);

		if(lp[0]=='X') apagou = x/2;
		else apagou = (x+1)/2;

		if(x%2!=0){
			if(lp[0]=='X') lp[0] = 'O';
			else lp[0] = 'X';
		}

		for(i=1;i<tm;i++){
			c=lp[i];
			if(apagou%2!=0){
				if(lp[i]=='X') lp[i] = 'O';
				else lp[i] = 'X';
			}

			if(c=='X') apagou = apagou/2;
			else apagou = (apagou+1)/2;

		}

		for(i=0;i<tm;i++) cout<<lp[i];
		cout<<endl;

	}

	return 0;
}
