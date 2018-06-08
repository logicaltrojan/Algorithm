#include <iostream>
#include <cstdio>




typedef long long ll;
ll juice[10001];
ll d[10001][2]; // max drink/status status 0 == not drunk 1 == drunk
using namespace std;

ll mach(int n){

	for(int i = 2; i <= n ; i++){	
		d[i][1] = max((d[i-2][0] + juice[i-1] +juice[i]),(d[i-1][0]+juice[i]));
		d[i][0] = max(d[i-1][0],d[i-1][1]);
	}

	return max(d[n][0], d[n][1]);

}

int main(){



	int num;

	cin >> num; 
	for (int i =1; i <= num ; i++)
		cin>> juice[i];

	d[1][1] = juice[1];

	printf("%lld\n" , mach(num));

	return 0;
}