#include <iostream>
#include <string>
using namespace std;

int gcd(int a, int b) {  // 유클리드 호제법
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}

int main() {
	string str;
	cin >> str;

	int first = stoi(str.substr(0, str.find(':')));  // 앞 숫자 추출
	int end = stoi(str.substr(str.find(':') + 1));  // 뒷 숫자 추출

	int divide = gcd(first, end);  // 최대공약수 구함

	cout << first / divide << ':' << end / divide << endl;
}