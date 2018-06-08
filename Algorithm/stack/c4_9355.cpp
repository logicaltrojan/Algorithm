#include <iostream>
#include <cstdio>
#include <stack>
#include <utility>
#include <cstring>
#include <algorithm>
#include <string>


using namespace std;

char a[1005000];
char b[40];
bool check[1005000];
string ans;
int aSize;
int tSize;
int m, n;

stack< pair<int, int > > st;



void makeEmpty(){
	while(!st.empty()){
		st.pop();
	}
}

void mach(){

	for(int i = 0; i < aSize ; i++){
		if(a[i] == b[0])
			st.push(make_pair(i,0));
		else{
			if(!st.empty()){
				if(a[i] == b[st.top().second+1]){
					st.push(make_pair(i,st.top().second+1));
					if(st.top().second == tSize-1)
						for(int j =0 ; j < tSize; j++){
							check[st.top().first] = true;
							st.pop(); 
						}
					
				}else {
					makeEmpty();
				}
			
			}
		}
	}

			
		
			
	

}


int main(){

	
	scanf("%s", a);
	scanf("%s", b);
	
	aSize = strlen(a);
	tSize=  strlen(b);
	m= tSize;
	n = aSize;
	if(tSize == 1){
		for(int i =0 ; i< aSize	; i++)
			if(a[i] == b[0])
				check[i] = true;
	}else{
		mach();	
	}

	
	for(int i = 0; i < aSize; i++)
		if(check[i] == false){
			ans += a[i];
		}

	if(ans.size() == 0)
		printf("FRULA");
	else
		cout<< ans;


	return 0;
}