#include <iostream>
#include <cstdio>


using namespace std;
int memo[1000001];

int mach(int x){

	int temp;

	if(x == 1)
		return memo[1];

	if(memo[x]>0)
		return memo[x];

	else {
		//remember the 3 circumstance , the basic / 	
		memo[x] = mach(x-1)+1;

		if(x%2 == 0)
			memo[x] = min(mach(x-1), mach(x/2))+1;
		if(x%3 == 0)
			memo[x] = min(mach(x-1), mach(x/3))+1;
		

		return memo[x];
	}
	
}


int main(){

	int num = 0;
	cin >> num;
	cout<<mach(num)<<endl;

	return 0;
}