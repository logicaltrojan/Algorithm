#include <iostream>
#include <cstdio>
#define mod 1000000000

typedef long long ll;


ll a[201];
ll c[201][201];


ll mach (int n, int k){

	
	for(int j = 1; j<= k ; j++)
		for(int i = 0; i<= n ; i++)
			for(int l = 0; l <= i ; l++){
				c[i][j] += c[i-l][j-1];
				c[i][j] %= mod;
			}

	return c[n][k];
}





int main(){
	int n;
	int k;
	

	for (int i =0; i <= 200 ; i++){
		c[i][1] = 1;
	}



	scanf("%d %d", &n, &k);

	printf("%lld", mach(n,k));



	return 0;
}