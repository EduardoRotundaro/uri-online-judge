#include<bits/stdc++.h>
using namespace std;

int m;

bool cmp(int a, int b){
	if( a%m < b%m ) return true;
	else if( a%m > b%m ) return false;
	else if(a%2==0 && b%2!=0 ) return false;
	else if(b%2==0 && a%2!=0 ) return true;
	else if(a%2!=0 && b%2!=0 && a>b) return true;
	else if(a%2!=0 && b%2!=0 && b>a) return false;
	else if(a%2==0 && b%2==0 && a<b) return true;
	else if(a%2==0 && b%2==0 && b<a) return false;
}

int main(){

	int n, i;
	long long int x;
	vector<long long int> v;

	cin>>n>>m;
	while(n!=0 || m!=0){

		for(i=0;i<n;i++){
			cin>>x;
			v.push_back(x);
		}
		cout<<n<<" "<<m<<endl;
		sort(v.begin(), v.end(), cmp);

		for(i=0;i<v.size();i++) cout<<v[i]<<endl;

		v.clear();
		cin>>n>>m;
	}
	cout<<n<<" "<<m<<endl;

	return 0;
}
