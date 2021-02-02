#include <iostream>
#include <vector>

using namespace std;

int gcd(int n, int k);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int a,b;
	int coprime;
	int num1, num2;
	
	cin>>a>>b;

	b /= a;

	//a에 곱해줄 서로소 찾기
	for (int i = 1; i*i < b + 1; i++) {
		if (b%i == 0 && gcd(i, b / i) == 1)
			coprime = i;
	}

	num1 = a * coprime;
	num2 = a * (b / coprime);

	cout << num1 << ' ' << num2;
	return 0;
}

int gcd(int n, int k) {
	if (k == 0)
		return n;
	else
		return gcd(k, n%k);
}