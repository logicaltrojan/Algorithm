#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;








int main(){

	int k;
	cin >> k;

	while(k){
		vector <int> s(k);

		for(int i = 0 ; i < k; i++)
			scanf("%d", &s[i]);


		vector <int> a;	

		for(int i=0 ; i < k-6 ; i++)
			a.push_back(0);
		for(int i = 0 ; i< 6; i++)
			a.push_back(1);



		sort(s.begin(), s.end());

		vector <vector <int> > ans;
		vector <int> current;

		do{
			for(int i =0; i < k ; i++)
				if(a[i] == 1)
					current.push_back(s[i]);

			ans.push_back(current);
			current.clear();
		}while(next_permutation(a.begin(),a.end()));




		for(int i = ans.size()-1; i >= 0 ; i-- ){
			for(int j = 0 ; j < ans[i].size() ; j++)
				cout << ans[i][j] << " " ;
			cout << endl;
		}

		cout << endl;

		cin >> k;

	}

	return 0;
}