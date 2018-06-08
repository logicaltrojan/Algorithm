#include <iostream>
#include <cstdio>

using namespace std;
int N, S;
int a[30];
int ans;

int mach(int sum, int pos){
	

	if(pos == N){
		if(sum == S)
			return 1;
		else
			return 0;
	}
	
	
	

	int cnt = mach(sum+a[pos], pos+1) + mach(sum, pos+1);

	return cnt;
}




int main(){

	scanf("%d %d", &N, &S);
	for(int i = 0; i < N ; i++)
		scanf(" %d", &a[i]);

	int max = mach(0,0);
	if(S == 0)
		max--;

	cout << max;

}