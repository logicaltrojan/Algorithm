#include <cstdio>
#include <iostream>

using namespace std;
int R, C;
int a[30][30];
int v[30][30];
bool c[100];

int MAX= 1;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};


bool safe(int row, int col){

	return (row >=0 && row < R && col >= 0 && col <C);
}

void mach(int row, int col, int cnt){

	if(cnt > MAX)
		MAX = cnt;

	v[row][col] = 1;
	c[a[row][col]] = true;

	for(int i = 0 ; i < 4 ; i++){
		int nrow = row + dx[i]; int ncol = col + dy[i];
		if(safe(nrow,ncol) && v[nrow][ncol] == 0){
			if(c[a[nrow][ncol]] == false){
				mach(nrow, ncol, cnt+1);
				v[nrow][ncol] = 0;
				c[a[nrow][ncol]] = false;
			}
		}
	}


}

int main(){

	char temp;
	int x;


	scanf("%d %d", &R, &C);
	for(int i = 0; i < R ; i++)
		for(int j = 0; j < C ; j++){
			scanf(" %c", &temp);
			x = (int)temp;
			a[i][j] = x-65;
		}

	mach(0,0,1);
	cout << MAX;

}