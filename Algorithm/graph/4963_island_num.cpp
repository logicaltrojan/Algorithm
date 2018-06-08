#include <iostream>
#include <cstdio>
#include <utility>
#include <algorithm>

int a[55][55];

int c[55][55];

int dx[8] = {-1, 1, 0, 0, 1,1, -1, -1};
int dy[8] = {0, 0, -1, 1, 1, -1, 1, -1};


int h, w;

void dfs(int x, int y, int count){
	c[x][y] = count;
	for(int i=0; i < 7 ; i++ ){
		int nx= x+dx[i]; int ny = y+dy[i];
		if( 0<nx && nx <=h && 0<ny && ny <= w){
			if(c[nx][ny] == 0 && a[nx][ny] == 1) // if not visited , and island
				dfs(nx, ny, count);
		}
	}


}

void initialize(){
	for(int i = 0; i < 55; i++)
		for(int j = 0 ; j < 55 ; j++){
			a[i][j] =0; c[i][j]= 0;
		}
}

int main(){

	scanf("%d %d", &w, &h);

	while(w != 0 && h != 0){		

		for(int i = 1; i <= h; i++)
			for(int j =1 ; j <= w ; j++)
				scanf("%d", &a[i][j]);


		int count = 0;
		for(int i = 1; i <= h; i++)
			for(int j =1 ; j <= w ; j++)
				if(c[i][j] == 0 && a[i][j] == 1){
					dfs(i,j, ++count);
				}

		printf("%d\n", count);
		initialize();
		scanf("%d %d", &w, &h);
	}
	

	return 0;

}