#include <iostream>
#include <cstdio>
#include <queue>
#include <utility>



int n, m;
int day; // tomato day

int a[1050][1050];
int c[1050][1050];

int dx[4] = {0, 0, -1, 1}; // for the rotation
int dy[4] = {-1, 1, 0 , 0};

using namespace std;


queue <pair<int, int> > q; // queue for bfs


void bfs(){// bfs , the ini will be held in main func // have to give initail queue pop

	while(!q.empty()){
		int k = q.front().first; int t = q.front().second;
		q.pop();
		for(int i =0 ; i < 4 ; i++){
			int nx =  k+dx[i]; int ny = t+dy[i];
			if(0< nx && nx <= n && 0 < ny && ny <= m)
				if(c[nx][ny] ==0 ){
					q.push(make_pair(nx, ny));
					c[nx][ny] = c[k][t] + 1; 
				}
		}
	}


}





int main(){

	//push queue for the all 1's 

	scanf("%d %d", &m, &n);
	for(int i = 1; i <= n ; i++)
		for(int j = 1; j <= m ; j++){
			scanf("%d", &a[i][j]);
			if(a[i][j] == 1){
				q.push(make_pair(i, j));
				c[i][j] = 1;
			}
			if(a[i][j] == -1)
				c[i][j] = -1;
		}

	bfs();
		

	int max = -1;
	bool flag =true;

	for(int i = 1; i <= n ; i++)
		for(int j = 1; j <= m ; j++){
			if(c[i][j] == 0)
				flag= false;
			if(c[i][j] > max)
				max = c[i][j];
		}


	if(flag)
		printf("%d", max-1);
	else
		printf("%d", -1);
		



	return 0;
}