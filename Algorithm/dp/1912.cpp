#include <iostream>
#include <cstdio>
#define max(a,b) ((a)>(b)?(a):(b))

typedef long long ll;


int a[100001];
ll c[100001];


ll mach(int n){

	int maxima = 0;

	maxima = c[1] = a[1];

	for(int i = 2; i <= n ; i++){
		if(c[i-1] + a[i]< a[i])
			c[i] = a[i];
		else
			c[i] = c[i-1]+a[i];
	}
	maxima = c[1];
	for(int i =1 ; i<=n ; i++)
		if(maxima < c[i])
			maxima=c[i];

	return maxima;
}






int main(){

	int num;

	std::cin >> num;

	for(int i = 1; i <= num ; i++){
		scanf("%d", &a[i]);
	}

	std::cout << mach(num);



	return 0;
}