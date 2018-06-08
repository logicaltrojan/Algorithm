#include <cstdio>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>


int num;
using namespace std; 

int dx[4] = {-1,0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int a[30][30];
int check[30][30];
int answer[30];

void dfs(int x,int y, int cnt){
	check[x][y] = cnt;
	for(int i =0 ; i < 4; i++){
		int nx = x+dx[i]; 
		int ny = y+dy[i];
		if( 0 < nx && nx <= num && 0<ny && ny <= num){

			if(check[nx][ny] == 0 && a[nx][ny] == 1){
				dfs(nx, ny, cnt);
			}
		}
	}


}

int main(){

	
	scanf("%d",&num);
	int n = num;

	for(int i =1 ; i <n+1 ; i++){ // input perfect
		for(int j = 1;  j < n+1 ; j++)
			scanf("%1d", &a[i][j]);

	}

	

	int count = 0; 

	for(int i =1 ; i < n+1 ; i++){
		for(int j = 1;  j < n+1 ; j++){
			if(a[i][j] ==1 && check[i][j] == 0){
				dfs(i,j,++count);
			}
		}
	}
	printf("%d\n", count );

	int cnt =0;
	for(int k = 1;  k<= count ; k++){
		for(int i =1 ; i <n+1 ; i++){
			for(int j = 1;  j < n+1 ; j++){
					if(check[i][j] == k)
						cnt++;
				}
			}
		answer[k] = cnt; 
		cnt = 0;
	}

	sort(answer,answer+count+1);

	for(int k = 1;  k<= count ; k++){
		printf("%d\n", answer[k]);
	}




	return 0;

}