#include <iostream>
#include <cstdio>
#include <utility>
#include <queue>

using namespace std;

int a[105][105];
int c[105][105]; //for dfs
int d[105][105]; // for bfs
int e[105][105];

int num;


queue < pair <int, int> > q;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};


bool safety(int x, int y){

	bool safe = false;
	if(0< x && x <= num && 0< y && y <= num)
		safe =true;

	return safe;
}

int bfs(int x, int y, int z){ //after dfs, bfs use it to make the minimum 
	//k is island num
	q.push(make_pair(x, y));
	d[x][y] = 1;
	int count = 0;

	while(!q.empty()){
		int k = q.front().first; int t = q.front().second; q.pop();
		for(int i = 0; i < 4; i++){
			int nx = k+ dx[i]; int ny = t + dy[i]; 
			if(safety(nx, ny))
				if(c[nx][ny] != z && c[nx][ny] != 0) //not my land and sea, its another island
					return d[k][t]-1;
				else if(a[nx][ny] == 0 && d[nx][ny] == 0){//sea and not visited, go a head
					q.push(make_pair(nx,ny));
					d[nx][ny] = d[k][t]+1;	
				}

		}

	}

	return -1;
}

void dfs(int x, int y, int count){ //dfs = checked
	c[x][y] = count;
	for(int i = 0; i < 4; i ++){
		int nx = x+ dx[i]; int ny = y +dy[i];
		if(safety(nx, ny))
			if(c[nx][ny] == 0 && a[nx][ny] == 1){
				dfs(nx, ny, count);
			}

	}

}

void printMap(){
	for(int i = 1; i <= num ; i++){
		for(int j =1 ; j <= num ; j++)
			printf("%2d ",e[i][j]);
		printf("\n");
	}

}

void ini(){
	for(int i = 0 ; i < 105; i++)
		for(int j =0 ; j < 105; j++)
			d[i][j] = 0;

	while(!q.empty()){
		q.pop();
	}
}



int main(){

	cin >> num;

	int n = num;

	for(int i = 1; i <= n ; i++) // input checked
		for(int j =1 ; j <= n ; j++)
			scanf("%d", &a[i][j]);


	int count = 0;
	for(int i = 1; i <=n ; i++)
		for(int j =1 ; j<= n ; j++)
			if(c[i][j] == 0 && a[i][j] == 1){
				dfs(i,j, ++count);
			}


	int min = 100000;

	for(int i = 1; i <=n ; i++)
		for(int j =1 ; j<= n ; j++)
			if(c[i][j] != 0 ){
				e[i][j] = bfs(i,j,c[i][j]);
				ini();
			}


	for(int i = 1; i <=n ; i++)
		for(int j =1 ; j<= n ; j++)
			if(a[i][j] != 0 )
				if(e[i][j] >= 0 && min > e[i][j]){
					min = e[i][j];
				}

	if(min  > 10000)
		printf("%d", 0)
	else
		printf("%d", min);


	return 0;
}