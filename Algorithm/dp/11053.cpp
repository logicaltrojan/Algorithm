#include <iostream>
#include <cstdio>


int c[1001];
int a[1001];


int mach(int n){


	for(int i=1; i <= n ; i++){
		c[i] = 1;
		for(int j= 1; j < i ; j++)
			if(a[i]<a[j] && c[i]< c[j]+1)
				c[i] = c[j]+1;
		}

	int maxima = c[1];
	
	for(int i = 1; i <= n ; i++){
		if(maxima < c[i])
			maxima = c[i];
	}
	return maxima;
}

int main(){

	int num;
	std::cin >> num;

	for(int i=1; i <= num ; i++)
		scanf("%d", &a[i]);

	printf("%d", mach(num));
	

	return 0;
}