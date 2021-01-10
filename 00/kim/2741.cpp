#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int num; // N값

	cin >> num; // N값 입력

	for (int i = 1; i < num+1; i++) {
		cout << i << "\n"; // N까지의 숫자 출력	 ※endl 하면 시간초과
	}

	return 0;
}