#include <iostream>
#include <algorithm>
#include <cstdio>


using namespace std;


int main(){

	int temp[5] = {1,2,3,4,5};

	do{
		for(int i =0 ; i< 5; i++)
			printf("%d", temp[i]);
		cout << endl;


	}while(next_permutation(temp, temp+5));



	return 0;

}