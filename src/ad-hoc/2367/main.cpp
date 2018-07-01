#include <bits/stdc++.h>
using namespace std;

static int cnt[1024 * 1024];
static int forbid[1024 * 1024];

int solve (int n, int m){
	int i, j;
  	for (i = 0; i <= n; i++)
    	cnt[i] = forbid[i] = 0;

  	for (i = 0; i <= n; i++) {
    	if (cnt[i] == 0) {
      		for (j = 1; j <= m; j++) {
        		cnt[i + j]++;
        		forbid[i + j] = j;
      		}
    	}
		else if (cnt[i] == 1) {
      		cnt[i + forbid[i]]++;
      		forbid[i + forbid[i]] = forbid[i];
    	}
  	}

	  return cnt[n];
}

int main(){
	int n, m;

    scanf ("%d %d", &n, &m);
    if (n == 0) return 0;

	if(solve (n, m)) printf("Paula\n");
	else printf("Carlos\n");

	return 0;
}
