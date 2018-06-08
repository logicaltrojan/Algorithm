#include <iostream>
#include <cstdio>
#include <vector>


using namespace std;

vector<int> a[1050];
bool check[1050] ={false};



void dfs(int n){
	check[n] = true;
	for(int i = 0; i < a[n].size(); i++){
		int y = a[n][i];
		if(check[y] == false)
			dfs(y);
	}
}



int main(){

	int v, e = 0;

	scanf("%d %d", &v, &e);

	for(int i =0 ; i< e; i++){
		int n, m;
		scanf("%d %d", &n, &m);
		a[n].push_back(m); a[m].push_back(n);
	}

	int component = 0;

	for(int i = 1  ;i <= v; i++){
		if(check[i] == false){
			dfs(i);
			component++;
		}
	}


	printf("%d", component);

}