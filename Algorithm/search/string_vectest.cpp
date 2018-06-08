#include <vector>
#include <iostream>
#include <string>

using namespace std;
vector <string> v(10005);


int main(){


	v[1000] = "hello";
	v[1001] = v[1000] + "my nameis";

	std::cout << v[1001];
}