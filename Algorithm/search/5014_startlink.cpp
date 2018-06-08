#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int F, S, G, U, D;

int a[3000000];
bool c[3000000];

void mach(int s){
	
	queue <int> q;
	q.push(s);
	c[s] = true;
	a[s] = 0;

	while(!q.empty()){
		int temp = q.front(); q.pop();
		int newTemp = temp +U;

		if(newTemp <= F && c[newTemp] == false ){
			q.push(newTemp);
			c[newTemp] = true;
			a[newTemp] = a[temp] +1;
		}
		newTemp = temp - D;
		if(newTemp > 0 && c[newTemp] == false){
			q.push(newTemp);
			c[newTemp] = true;
			a[newTemp] = a[temp] +1;
		}
	}

}





int main(){

	scanf("%d %d %d %d %d", &F, &S ,&G, &U, &D);
	memset(c, false, sizeof(c));
	mach(S);
	if(c[G] == false)
		cout << "use the stairs";
	else
		cout << a[G];
}