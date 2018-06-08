#include <iostream>
#include <cstdio>
#include <queue>
#include <string>
#include <utility>
#include <algorithm>
#include <cstring>

using namespace std;


int c[10005];
bool visited[10005];
int from[10005];
char how[10005];

int D(int x){

	return (x*2)%10000;
}

int S(int x){

	int temp =x;
	temp = temp-1;
	if (temp ==-1)
		return 9999;

	return temp; 

}

int L(int x){
	int first = x /1000;
	int temp = (x%1000)*10;

	return temp + first;

}

int R(int x){
	int last = (x%10);
	int temp = (x/10);

	return (last*1000)+temp;


}

void mach(int n, int m){

	queue <int> q;
	q.push(n);
	c[n] = 0;
	visited[n] = true;
	from[n] = -1;

	while(!q.empty()){
		int temp = q.front(); q.pop();
		int next = D(temp);
		if(visited[next] == false){
			c[next] = c[temp] +1;
			visited[next] = true;
			from[next] = temp;
			how[next] = 'D';
			q.push(next);
		}
		next = S(temp);
		if(visited[next] == false){
			c[next] = c[temp] +1;
			visited[next] = true;
			from[next] = temp;
			how[next] = 'S';
			q.push(next);
		}
		next = L(temp);
		if(visited[next] == false){
			c[next] = c[temp] +1;
			visited[next] = true;
			from[next] = temp;
			how[next] = 'L';
			q.push(next);
		}

		next = R(temp);
		if(visited[next] == false){
			c[next] = c[temp] +1;
			visited[next] = true;
			from[next] = temp;
			how[next] = 'R';
			q.push(next);
		}
	}




}

string printAns(int n, int m){

	string ans = "";
	while(n != m){
		char a= how[m];
		ans += a;
		m = from[m];
	}

	reverse(ans.begin(), ans.end());

	return ans;


}





int main(){

	int tc;
	int n, m;
	cin >> tc;
	while(tc--){
		memset(c, 0, sizeof(c));
		memset(visited, false, sizeof(visited));
		memset(from, 0, sizeof(from));
		memset(how, 0, sizeof(how));
		scanf("%d %d", &n, &m);
		mach(n, m);
		cout << printAns(n,m) << endl;
	}


}