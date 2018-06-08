#include <iostream>
#include <cstdio>



using namespace std;

int N;
int a[20][20];
int ans;

bool column[20];
bool rightup[50];
bool leftup[50];




bool check(int row, int i){

	if(column[i])
		return false;
	if(rightup[row+i])
		return false;
	if(leftup[row-i+N])
		return false;

	return true;


}

int mach(int row){

	
	if(row == N+1)
		return 1;

	int cnt =0;
	for(int i = 1; i <= N ; i++){
		if(check(row,i)){
			a[row][i] = -1;
			column[i] = true;
			rightup[row+i] = true;
			leftup[row-i+N] = true;
			cnt += mach(row+1);
			column[i] = false;
			rightup[row+i] = false;
			leftup[row-i+N] = false;
			a[row][i] = 0;
		}
	
	}

	return cnt;
}


int main(){

	scanf("%d", &N);
	
	cout << mach(1);
}