#include <iostream>

using namespace std;

#define SIZE 5000+2

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int k;//버튼을 누른 횟수

	int a = 1; // a의 갯수
	int b = 0; // b의 갯수
	int temp_a, temp_b; // 현재의 a,b의 갯수를 저장
	cin >> k;

	for (int i = 0; i < k; i++) {
		temp_a = a;
		temp_b = b;
		b = temp_b + temp_a;
		a = temp_b;
	}
	cout << a << " " << b << endl;
}