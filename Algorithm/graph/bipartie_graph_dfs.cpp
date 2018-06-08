#include <iostream>
#include <cstdio>
#include <vector>


using namespace std;

vector <int> a[20050];
int color[20050];



void dfs(int x, int clr){ //  blue = 1 , red = 2
	color[x] = clr;// check the color
	for(int i = 0; i < a[x].size() ; i++ ){
		int y = a[x][i];
		if(color[y] == 0)
			dfs(y, 3-clr);
	}

}



bool check_Bi(int x){

	bool ok = true;

	for(int i = 0; i < a[x].size() ; i++ ){
		int y = a[x][i];
		if(color[y] + color[x] == 3)
			continue;
		else{
			ok = false;
			break;
		}
	}

	return ok;

}



void initialize(){

	for(int i = 0; i < 20050 ; i++){
		color[i] = 0;
		a[i].clear();
	}
}

int main(){


	int testCase = 0;
	cin >> testCase;
	int v, e;
	while(testCase--){ //input 
		scanf("%d %d", &v, &e);
		for(int i =0; i<e ; i++){
			int n, m;
			scanf("%d %d", &n, &m);
			a[n].push_back(m); a[m].push_back(n);
		}

		bool ok =true; //checking the condition 

		for(int i = 1; i <= v; i++){//for the disjoint graph, check all;
			if(color[i] == 0)
				dfs(i,1);
			if(ok=check_Bi(i))
				continue;
			else
				break;


		}

		if(ok)
			printf("YES\n");
		else
			printf("NO\n");

		initialize();


	}

}









