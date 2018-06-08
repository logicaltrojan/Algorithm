#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;


queue<int> q;
vector<int> a[1005];
bool check1[1005] = {false};
bool check2[1005] = {false};



void dfs(int x){
	check1[x] = true;
	printf("%d ",x);
	for(int i = 0; i < a[x].size() ; i++){
		int y = a[x][i];
		if(check1[y] == false)
			dfs(y);
	}
}


void bfs(int x){
	check2[x] = true;
	q.push(x);
	while(!q.empty()){
		int x = q.front(); q.pop();
		printf("%d ", x);
		for(int i =0 ; i < a[x].size(); i++){
			int y = a[x][i];
			if(check2[y] == false){
				q.push(y);
				check2[y] = true;
			}
		}

	}
}




int main(){

	int v, e, start;

	scanf("%d %d %d", &v, &e, &start);
	for(int i =0; i < e ; i ++){
		int n, m;
		scanf("%d %d", &n, &m);
		a[n].push_back(m);
		a[m].push_back(n);
	}

	for(int i =0; i< e; i++){
		sort(a[i].begin(), a[i].end());
	}

	dfs(start);
	std::cout << std::endl;;
	bfs(start);




	return 0;
}