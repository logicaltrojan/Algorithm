#include <iostream>
#include <cstdio>
#include <string>
#define mod 1000000

typedef long long ll;
using namespace std;

char a[5001];
ll c[5001];

int mach(int n){


	c[1] = 1;
	c[0] = 1; 

	if(1== n && a[1] == '0')
		return 0;

	for(int i = 2; i<= n ; i++){
		if(a[i] == '0'){
			if(a[i-1] == '1' || a[i-1] == '2'){
				c[i] = c[i-2]%mod;
			}
			else
				c[i] = 0;
		}
		else if((a[i-1] == '1' && (a[i] >= '1' && a[i] <= '9')) || (a[i-1] == '2' && (a[i] >= '1' && a[i] <= '6')))
				c[i] = (c[i-1] + c[i-2])%mod;
		else{
			c[i] = c[i-1]%mod;
		}
	}

	return c[n];


}




int main(){

	int num;
	string b;

	std::cin>> b;
	
	num = b.length();
	for(int i = 0 ; i< num ; i++)
		a[i+1] = b.at(i);

	printf("%d", mach(num));

	
	return 0;
}