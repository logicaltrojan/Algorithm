#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>


using namespace std;

int n;
int a[15][15];



int mach(){
	
	vector <int> v; 
	for(int i= 1; i <= n ; i++)
		v.push_back(i);

	int ans;

	int min = 0xffffff;
	do{
		int temp =0;
		bool ok = true;

		for(int i = 0; i < v.size()-1; i++){
			if(a[v[i]][v[i+1]] != 0)
				temp += a[v[i]][v[i+1]];
			else 
				ok =false;
		}
		if(ok && a[v[n-1]][v[0]] != 0)
			if(min > temp + a[v[n-1]][v[0]])
				min = temp + a[v[n-1]][v[0]];

	}while(next_permutation(v.begin(), v.end()));

	return min;
}



int main(){

	cin >> n;

	for(int i = 1; i <= n ; i++)
		for(int j = 1; j <= n ; j ++)
			scanf("%d", &a[i][j]);


	cout << mach();



}