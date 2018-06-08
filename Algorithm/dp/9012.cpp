#include <iostream>
#include <stack>
#include <cstdio>
#include e

using namespace std;
// using namespace std;


string VPS(string h){
	int stack = 0;
	for(int i = 0; i < h.size(); i++){
		if(h[i] == '(')
			stack++;
		else {
			stack--;
			if(stack < 0 )
				return "NO";
		}
	}

	if (stack == 0)
		return "YES";
	else
		return "NO";



}
int main(){

	stack<char> Stack;
	int num = 0;
	string h;

	scanf("%d", &num);

	while(num--){
		cin >> h;
		cout << VPS(h) << endl;
	}



	return 0;

}


/*
이 문제는 스택을 이용해서 푸는 게 정석이나, 인접한 괄호만을 검사한다는 점을 이용하여
스택을 사용하지 않고 문제를 풀 수 있다.
문자열을 받아, 처음부터 검사한다. (가 나올 경우 변수의 값을 1 올린다, )가 나올 경우 변수의 값을 1 내린다.
만약 반복문 중간에 변수의 값이 0 미만으로 내려 갈 경우, 반복문을 나오고 "NO"를 출력한다.
반복문을 다 돌고 변수의 값이 0일 경우, "YES"를 출력한다.
변수의 값이 0 초과일 경우, "NO"를 출력한다.
수행시간은 테스트 케이스 입력값을 제외하고 O(n)에서 해결할 수 있다.
*/

// int main()
// {
// 	int n,t;
// 	string s;
// 	scanf("%d", &n);

// 	while (n--)
// 	{
// 		t = 0;
// 		cin >> s;
// 		for (int i = 0; i < s.size(); i++)
// 		{
// 			if (s.at(i) == '(') t += 1;
// 			else t -= 1;
// 			if (t < 0)
// 			{
// 				printf("NO");
// 				break;
// 			}
// 		}
// 		if (t == 0) printf("YES");
// 		else if(t > 0) printf("NO");
// 		printf("\n");
// 	}
// }