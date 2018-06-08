#include <iostream>
#include <cstdio>


int cache[10001];


int mach(int x){
	if(x == 0)
		return 0;

	if(cache[x]>0)
		return cache[x];

	cache[x] =  mach(x-1)+mach(x-2);
	cache[x] = cache[x] % 10007;

	return cache[x];

}


int main(){
	int n;
	cache[1] =1;
	cache[2] = 2;
	std::cin >> n;

	std::cout << mach(n)<< std::endl;
}