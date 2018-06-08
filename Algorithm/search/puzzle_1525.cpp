#include <iostream>
#include <cstdio>
#include <queue>
#include <string>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>

#define N 3

using namespace std;


int a[5][5];



int mach(int x){
	map <int, int> m;
	queue <int> q;
	int pos;
	int temp;
	string strX;


	 // becareful of range 0  ~ 8 ;
	q.push(x);
	m[x] = 0;

	while(!q.empty()){
		temp = q.front(); q.pop();
		strX = to_string(temp);
		pos = strX.find('9');
		string t;
		int newNum;
		if (temp == 123456789)
			return m[123456789];
		
		if(pos > 2){
			t = strX;
			swap(t[pos-3], t[pos]);
			newNum = stoi(t);
			if(m.count(newNum) == 0){
				q.push(newNum);
				m[newNum] = m[temp]+1;
			}		
		}
		if(pos%3 != 0){
			t = strX;
			swap(t[pos-1], t[pos]);
			newNum = stoi(t);
			if(m.count(newNum) == 0){
				q.push(newNum);
				m[newNum] = m[temp]+1;
			}		
		}

		if(pos%3 != 2){
			t = strX;
			swap(t[pos+1], t[pos]);
			newNum = stoi(t);
			if(m.count(newNum) == 0){
				q.push(newNum);
				m[newNum] = m[temp]+1;
			}		
		}

		if(pos < 6 ){
			t = strX;
			swap(t[pos+3], t[pos]);
			newNum = stoi(t);
			if(m.count(newNum) == 0){
				q.push(newNum);
				m[newNum] = m[temp]+1;
			}		
		}
	}

	return -1;
		
}



int main(){

	
	int temp;
	string c = "";


	for(int i = 1; i<= 3 ; i++)
		for(int j = 1; j<= 3 ; j++){
			scanf("%d", &a[i][j]);
			temp = a[i][j];
			if(temp == 0)
				temp = 9;
			c += to_string(temp);
		}

	cout << mach(stoi(c)) <<endl;





}