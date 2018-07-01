#include<bits/stdc++.h>
using namespace std;

int main(){

    char linha1[102], linha2[102];
    int i, j, tm2, tm, maior, cont, aux, aux2;

    while(cin.getline(linha1,102)){
    	cin.getline(linha2,102);

    	maior=0;
    	tm=strlen(linha1);
    	tm2=strlen(linha2);

    	for(i=0;i<tm;i++){

    		for(j=0;j<tm2;j++){

    			if(linha2[j]==linha1[i]){
    				cont=0; aux=j; aux2=i;
    				while(linha2[aux++]==linha1[aux2++] && aux<=tm2 && aux2<=tm){
    					cont++;
					}
					if(cont>maior) maior=cont;
				}

			}

		}

		printf("%d\n", maior);

	}

    return 0;
}
