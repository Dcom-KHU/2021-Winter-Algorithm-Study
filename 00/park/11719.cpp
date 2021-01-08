#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	while (getline(cin, str)) {  // cin 객체에 데이터가 있으면 계속 getline
		cout << str << '\n';
	}
	return 0;
}