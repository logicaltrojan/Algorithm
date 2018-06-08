#include <iostream>
#include <stdio.h>

int a[100001];
int c[100001];

int mach(int n){

	if(c[n] > 0)
		return c[n];


}



int main(){


	int num;
	std::cin>> num;

	for(int i = 1; i < 350 ; i++){
		if( i*i < 100000)
			c[i*i] = 1;
	}

	std::cout << mach(num);
}