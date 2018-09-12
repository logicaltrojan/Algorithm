#include <bits/stdc++.h>

using namespace std;

int N;
char a[55][55];

struct wood{
	pair <int, int> head;
	pair <int, int> tail;
};

vector <int, int> endPoint;
vector <int, int> startPoint;

bool safety(int x, int y){
	return x > 0 && y > 0 && x <= N && y <= N;
}

int mach(){


	struct wood WOOD = {make_pair(0,0), make_pair(0,0)};


}

int main(){

	char temp;

	scanf("%d", &N);
	for(int i= 1; i <= N; i++){
		for(int j = 1; j <= N ; j++){
			scanf(" %1c", &a[i][j]);
			if(a[i][j] == 'B') startPoint.push(make_pair(i,j));
			else if(a[i][j] == 'E') endPoint.push(make_pair(i,j));
		}
	}


}
