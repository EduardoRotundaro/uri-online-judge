#include<bits/stdc++.h>
using namespace std;

long long int string_to_int(string num, char tp){

	long long int ans=0;
	int tm = num.size();
	int a =tm-1;

	if(tp=='d'){
		for(int i=0;i<tm;i++){
			ans+= (int) (num[a]-'0') * pow(10,i);
			a--;
		}
	}
	else{
		for(int i=0;i<tm-2;i++){
			if(num[a]<58){
				ans += (int) (num[a] - '0') * pow(16,i);
			}
			else{
				ans += (int) (num[a] - 'W') * pow(16,i);
			}
			a--;
		}
	}

	return ans;
}

int main(){

	int n, caso=1;
	char tp;
	long long int deci;
	string num;

	cin>>num;
	while(num.at(0)!='-'){

		if(num.size()>2 && num.at(1)=='x'){
			deci = string_to_int(num, 'h');
			printf("%lld\n", deci);
		}

		else{
			deci = string_to_int(num, 'd');
			printf("0x%X\n", deci);
		}

		cin>>num;
	}

	return 0;
}
