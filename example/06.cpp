#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

bool check[10001] = { false };

int main() {
	for (int i = 2; i <= 10000; i++)
	{
		if (check[i] == false) {
			for (int j = i * i; j <= 10000; j += i) { // 소수의 배수 부터
				check[j] = true; // 소수의 배수는 소수가 아님
			}
		}
	}
}