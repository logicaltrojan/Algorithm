#include <iostream>
#include <cstdio>
#include <stack>

typedef long long ll;



using namespace std;
ll N; // rectangle amount;
ll a[100500];
ll MAX;

void mach(){

	stack <pair <ll, ll> > s; //size, index
	
	for(int i =0 ; i < N ; i++){
		if(s.empty()){
			s.push(make_pair(a[i], i));
		}else{
			if(s.top().first < a[i]){
				s.push(make_pair(a[i], i));
			}else{
				while(!s.empty() && s.top().first > a[i]){
					ll tempSize = s.top().first; ll tempInd = s.top().second;
					s.pop();
					ll width = i;
					if(!s.empty())
						width = (i-s.top().second-1);
					if(tempSize * width > MAX)
						MAX = tempSize * width;


				}
				s.push(make_pair(a[i], i));
			}
		}
	}
	while(!s.empty()){
		ll recSize;
		ll tempSize = s.top().first; ll tempInd = s.top().second;
		s.pop();
		if(s.empty()){
			recSize = tempSize * N;	
		}else{
			recSize = (N-s.top().second-1)* tempSize;
		}
		
		if(recSize > MAX)
			MAX =recSize;

	}


	return;

}




int main(){
	

	scanf("%lld", &N);

	while( N != 0){
		for(int i= 0; i < N ; i++)
			scanf("%lld", &a[i]);

		mach();
		printf("%lld\n", MAX);
		MAX = -1;
		scanf("%d", &N);

	}

	return 0;

}