#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int N;
int a[20];
vector <int> v;
int MAX = -2000000000;
int MIN = 2000000000;



void mach(){


	int ans = 0;

	do{
		int x; int y; int z;
		
		x= a[0];
		for(int i = 1 ; i <= N-1 ;i++){	
			y =a[i];
			z = v[i-1];
			if(z == 1)
				ans = x+y;
			if(z == 2)
				ans = x-y;
			if(z == 3)
				ans = x * y;
			if(z == 4)
				ans = x/y; 
		
			x = ans;
		}

		if(ans > MAX)
			MAX = ans;
		if(ans < MIN)
			MIN = ans;


	}while(next_permutation(v.begin(), v.end()));


}



int main(){


	scanf("%d", &N);

	for(int i = 0; i < N ; i++){
		scanf("%d", &a[i]);
	}

	for(int i = 1; i <= 4 ; i++){
		int x;
		scanf("%d", &x);
		for(int j = 0 ; j < x ; j++)
			v.push_back(i);
	}

	mach();
	cout << MAX << endl;
	cout << MIN << endl;
	

}