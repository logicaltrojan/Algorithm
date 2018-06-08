#include <iostream>
#include <cstring>
#include <queue>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

int prime[10005];
int check[10005];
bool visited[10005];

int change(int n, int i, int j ){
	if(i == 0 && j == 0)
		return -1;

	string temp = to_string(n);
	temp[i] = '0'+j;

	return stoi(temp);

}


void mach(int x, int ans){

	queue <int> q;
	int temp;
	q.push(x);
	visited[x] = true;
	check[x] = 0;

	while(!q.empty()){

		int now = q.front(); q.pop();
		for(int i = 0; i<=3 ; i++ ){
			for(int j = 0 ; j <= 9 ; j++){
				temp = change(now,i,j);
				if(temp > 0 && prime[temp] == 0)
					if(visited[temp] == false){
						q.push(temp);
						check[temp] = check[now]+1;
						visited[temp] = true;
					}
			}
		}			
	}


}





int main(){

	for(int i = 2; i <= 10000; i++){
		if(prime[i] == 0)
			for(int j = i*i ;j<= 10000; j+= i)
				prime[j] = -1;
	}




	int tc;
	cin >> tc;
	int x; int y;
	while(tc--){
		memset(visited, false, sizeof(visited));
		memset(check, 0, sizeof(check));

		scanf("%d %d", &x, &y);
		mach(x, y);
		if(visited[y] == false )
			cout<< "Impossible" <<endl;
		else
			cout << check[y]<<endl;

		
	}

}