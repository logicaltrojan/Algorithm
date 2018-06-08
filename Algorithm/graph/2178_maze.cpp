#include <iostream>
#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>



using namespace std;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};


int a[105][105];
int c[105][105];

int n, m;
queue<pair<int, int> > q;


void bfs(int x, int y){

	int count = 1;

	q.push(make_pair(x, y));
	c[x][y] = count;

	while(!q.empty()){
		int k = q.front().first; int t = q.front().second; 
		q.pop();
		for(int i = 0; i < 4; i ++){
			int nx = k+ dx[i]; int ny = t+dy[i];
			if(0 < nx && nx <= n && 0 < ny && ny <= m){
				if(c[nx][ny] == 0 && a[nx][ny] == 1){
					q.push(make_pair(nx, ny));
					c[nx][ny] = c[k][t]+1;
				}
			}
		}
	}
}

int main(){

	scanf("%d %d", &n, &m);



	for(int i = 1; i <= n ; i++)
		for(int j = 1; j <=m ; j++){
			scanf("%1d", &a[i][j]);
		}


	bfs(1,1);


	printf("%d", c[n][m]);



}