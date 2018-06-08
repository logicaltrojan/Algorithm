#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <deque>


using namespace std;
int target;
int normNum[20];


//push the button 

bool checkTarget(int x){

	bool ans = true;

	if(x == 0)
		if(normNum[0] == -1)
			ans = false;

	while(x>0){
		if(normNum[x%10] == -1)
			ans = false;
		x = x/10;
	}

	return ans;
}

int jarisu(int x){
	int count = 0;

	if(x ==0)
		return 1;

	while(x>0){
		x = x/10;
		count ++;
	}

	return count;
}

int permutateAll(){
 
	int min = 1000000;
	int ans = 1000000;

	for(int i = 0; i < 1000000 ; i++){
		if(checkTarget(i)){
			if(min > abs(target-i)){
				min = abs(target-i);
				ans = i;
			}
		}

	}

	return ans;


}




int main(){


	
	int n;
	int brokenNum;
	

	scanf("%d", &target);
	scanf("%d", &n);


	while(n--){
		scanf("%d", &brokenNum);
		normNum[brokenNum] = -1;
	}
	

	

	int min = jarisu(permutateAll()) + abs(target-permutateAll());
	


	if(abs(target-100) < min)
		min = abs(target-100);
	

	cout << min;

	return 0;


}