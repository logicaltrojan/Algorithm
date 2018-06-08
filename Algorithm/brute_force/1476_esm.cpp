#include <iostream>
#include <cstdio>



int main(){


	int E, S, M;


	scanf("%d %d %d", &E, &S, &M);



	int i =1;
	int j = 1;
	int k =1; 
	int count = 1;

	while(!(i == E && j == S && k == M)){
		i = (i%15)+1;
		j = (j%28)+1;
		k = (k%19)+1;
		count++;
	}


	printf("%d", count);

	return 0;
}