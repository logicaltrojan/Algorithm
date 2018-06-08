#include <iostream>
#include <cstdio>
typedef long long ll;



ll c[101];


ll mach(int n){

	if(c[n] > 0)
		return c[n];

	for(int i = 6; i<=n; i++ ){
		c[i] = c[i-5]+c[i-1];
	}

	return c[n];
}





int main(){

	int test;
	int num;


	c[1] = c[2] =c[3] =1;
	c[4] = c[5] = 2;


	std::cin>>test;

	while(test--){
		std::cin >> num;
		std::cout<<mach(num)<<std::endl;;
	}

}