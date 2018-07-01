#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> frutas;
	int n, k, i, morta, d;
	long long int acumulado, resp = 0;
	char clima;

	cin>>n>>k;

	for(i=0; i<k; ++i){
		scanf("%d",&d);
		frutas.push_back(d);
	}

	sort(frutas.begin(),frutas.end());

	acumulado = 0;
	d = 0;

	morta = 0;

	for(i=0; i<n; ++i){

		scanf(" %c",&clima);

		if(clima == 'E')
			--d;
		else if (clima == 'C')
			++d;

		acumulado += d;

		while(frutas[morta] <= -d && morta < k) // arvore morreu
		{
			resp += acumulado + (i+(long long int)1)*frutas[morta];
			morta++;
		}
	}

	while(morta < k)
	{
		resp += acumulado + n*(long long int)frutas[morta];
		morta++;
	}

	printf("%lld\n",resp);

	return 0;
}
