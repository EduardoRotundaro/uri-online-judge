#include<bits/stdc++.h>
using namespace std;

long long int string_to_int(string num, char tp){

	long long int ans=0;
	int tm = num.size();
	int a =tm-1;

	if(tp=='b'){
		for(int i=0;i<tm;i++){
			if(num[a]=='1') ans += pow(2,i);
			a--;
		}
	}
	else if(tp=='d'){
		for(int i=0;i<tm;i++){
			ans+= (int) (num[a]-'0') * pow(10,i);
			a--;
		}
	}
	else{
		for(int i=0;i<tm;i++){
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

string decimal_to_binary(long long int a){

	string ans;
	int rst;

	while(a>=2){
		rst= a%2;
		ans.push_back( (char) (rst + 48) );
		a /=2;
	}
	ans.push_back( (char) (a+48) );
	reverse(ans.begin(), ans.end());

	return ans;
}

int main(){

	int n, caso=1;
	char tp;
	long long int deci;
	string num, typ, bin;

	cin>>n;
	while(n--){
		cin>>num>>typ;

		cout<<"Case "<<caso++<<":\n";
		if(typ.compare("bin")==0){
			deci = string_to_int(num, 'b');
			printf("%lld dec\n", deci);
			printf("%x hex\n\n", deci);
		}

		else if(typ.compare("dec")==0){
			deci = string_to_int(num, 'd');
			printf("%x hex\n", deci);
			bin = decimal_to_binary(deci);
			cout<<bin<<" bin\n\n";
		}

		else{
			deci = string_to_int(num, 'h');
			printf("%lld dec\n", deci);
			bin = decimal_to_binary(deci);
			cout<<bin<<" bin\n\n";
		}
	}

	return 0;
}
