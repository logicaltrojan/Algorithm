#include <iostream>
#include <cstring>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

vector <string> v;
vector <char> a;
int L, C;

void mach(int count, string curr, int pos){

	if(pos <= C){
		if(count == L)
			v.push_back(curr);
		else{
			mach(count+1, curr+a[pos], pos+1);
			mach(count, curr, pos+1);
		}
	}
}



int main(){

	char n;
	scanf("%d %d", &L, &C);
	getchar();

	for(int i = 0; i < C ; i++){
		scanf(" %c", &n);
		a.push_back(n);
	}

	sort(a.begin(), a.end());

	mach(0,"",0);
	for(int i = 0; i < v.size(); i++){
		string temp = v[i];
		int ja =0; int mo = 0;
		for(int j = 0; j < L ; j++){
			if(temp.at(j) == 'a' || temp.at(j) =='e' || temp.at(j) == 'i' || temp.at(j) == 'o'|| temp.at(j) == 'u')
				mo++;
			else
				ja++;
		} 
		if (ja >=2  && mo  >=1 )
			cout << temp << endl;
	}
}