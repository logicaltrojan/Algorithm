#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <utility>

using namespace std;

bool visited[10005];
vector <string> v(10005);


int D(int x){

	return (x*2)%10000;
}

int S(int x){

	int temp =x;
	temp = temp-1;
	if (temp ==- 1)
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
	visited[n] = true;
	v[n] = "";
	q.push(n);


	while(!q.empty()){
		int temp = q.front(); q.pop();
		if(temp == m)
			break;

		if(visited[D(temp)] == false){
			q.push(D(temp));
			v[D(temp)] = v[temp] + 'D';
			visited[D(temp)] = true;
		}
		if(visited[S(temp)] == false){
			q.push(S(temp));
			v[S(temp)] = v[temp] + 'S';
			visited[S(temp)] = true;
		}
		if(visited[L(temp)] == false){
			q.push(L(temp));
			v[L(temp)] = v[temp] + 'L';
			visited[L(temp)] = true;
		}
		if(visited[R(temp)] == false){
			q.push(R(temp));
			v[R(temp)] = v[temp] + 'R';
			visited[R(temp)] = true;
		}
	}

}


int main(){

	int tc;
	cin >> tc;
	int n, m;

	for(int i = 0; i < v.size(); i++)
		v[i] = "";

	while(tc--){
		memset(visited, false, sizeof(visited));
		scanf("%d %d", &n, &m);
		mach(n,m);
		cout << v[m] <<endl;
		v.clear();
	}

}