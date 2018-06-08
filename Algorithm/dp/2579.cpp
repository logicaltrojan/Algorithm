#include <iostream>
#include <cstdio>


int a[301];
int c[301][2];

int mach(int n){
	
	c[1][1]= a[1];

	for(int i= 2; i<= n; i ++){
		c[i][1] = std::max(c[i-2][1]+a[i], c[i-2][0]+a[i-1]+a[i]);
		c[i][0] = std::max(c[i-1][1]);
	}

	return c[n][1];



}

int main(){


	int num;

	std::cin >> num;

	for(int i = 1 ; i<= num ; i++)
		scanf("%d", &a[i]);


	printf("%d", mach(num));


	return 0;
}