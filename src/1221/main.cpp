#include<bits/stdc++.h>
using namespace std;

long long int _sieve_size;
bitset<10000010> bs;
vector<int> primes;

void sieve(long long int upperbound) {
	_sieve_size = upperbound + 1;
	bs.set();
	for (long long int i = 2; i <= _sieve_size; i++)
		if (bs[i]) {
			for (long long int j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
			primes.push_back((int)i);
		}

}

bool isPrime(long long int N) {
	if (N <= _sieve_size) return bs[N];
	for (int i = 0; i < (int)primes.size(); i++)
		if (N % primes[i] == 0) return false;

	return true;
}

int main(){

	int n;
	long long int num;

	sieve(10000000);

	cin>>n;
	while(n--){
		cin>>num;
		if( isPrime(num) ) cout<<"Prime\n";
		else cout<<"Not Prime\n";
	}

	return 0;
}
