#include <iostream>
#include <cstdio>
#include <string.h>
#define N 21


using namespace std;

int main(){

	int num;
	cin >> num;
	int S = 0;

	while(num--){
		char cmd[50]; 
		int x;
		

		scanf("%s %d", cmd, &x);


		if(!strcmp(cmd, "add"))
			S = S | (1 << x);
		else if(!strcmp(cmd, "remove"))
			S = S & ~(1 << x);
		else if(!strcmp(cmd, "check")){
			if(S&(1<<x))
				printf("1\n");
			else
				printf("0\n");
			}
		else if(!strcmp(cmd, "toggle"))
			S = S ^ (1<< x);
		else if(!strcmp(cmd, "all"))
			S = (1 << N) -1;
		else if(!strcmp(cmd, "empty"))
			S = 0;

	}


	return 0;
}

