#include <iostream>
#include <cstdio>

using namespace std;



int mach(int count, int sum, int goal){


	if(sum > goal)
		return 0;
	if(count > goal)
		return 0;
	if(sum == goal)
		return 1;
	int ans = 0;
	for(int i=1; i<= 3; i++){
		ans += mach(count+1, sum+i, goal);
	}

	return ans;
}




int main(){

	int tc; 
	cin >> tc;

	int n;
	while(tc--){
		scanf("%d", &n);
		cout << mach(0, 0, n) << endl;
	}


}
