#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>


using namespace std;


queue<int> q;
vector<int> a[20050];
int check[20050];


void bfs(int x){

	int color = 1;
	q.push(x);
	check[x] = color;
	while(!q.empty()){
		int y = q.front(); q.pop(); 
		for(int i=0 ; i < a[y].size() ; i++){
			if(check[a[y][i]] == 0){
				q.push(a[y][i]);
				color = 3-color;
				check[a[y][i]] = color;	
			}
		
		}
	}
}

bool colorCheck(int n){
	for(int i = 0; i <a[n].size() ; i++){
		if(check[n] + check[a[n][i]] != 3)
			return false;
	}
	
	return true;
}

void initialize(){
	while(!q.empty()){
		q.pop();
	}
	for(int i = 0; i < 20050 ; i++){
		check[i] = 0;
		a[i].clear();
	}
}


int main(){

	int testCase = 0;
	cin >> testCase;
	int v, e;
	while(testCase--){
		scanf("%d %d", &v, &e);
		for(int i =0; i<e ; i++){
			int n, m;
			scanf("%d %d", &n, &m);
			a[n].push_back(m); a[m].push_back(n);
		}

		bool ok = true;
		for(int j = 1; j <= v; j++){
			if(check[j] == 0 )
				bfs(j);
			if(ok = colorCheck(j))
				continue;
			else
				break;

		}

		if(ok)
			printf("YES\n");
		else
			printf("NO\n");

	
		initialize();

	}

}