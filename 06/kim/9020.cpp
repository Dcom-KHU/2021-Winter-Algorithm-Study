#include <iostream>
#include <cmath>

using namespace std;



bool IsPrime(int n) {
	if (n <= 1) return false;

	for (int i = 2; i <= sqrt(n); i++) {
		if ((n % i) == 0) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a, b; // 소수를 나눈 두 소수들
	int c; //케이스의 개수
	cin >> c;
	int min;

	for (int i = 0; i < c; i++) {
		int q; // 분해할 소수 
		cin >> q;

		for (int j = 1; j <=  q / 2; j++) {
			if (IsPrime(j)) {
				if (IsPrime(q - j)) { // q/2 까지 쭉 올라가면서 찾다보면 결국 차이가 가장적은 두 수를 찾는다
					a = j;
					b = q - j;
				}
			}
		}
		cout << a << " " << b << "\n";
	}

	return 0;
}
