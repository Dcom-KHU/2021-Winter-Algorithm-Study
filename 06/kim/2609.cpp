#include<iostream>
using namespace std;

int gcd(int m, int n) { //유클리드 호제법을 이용한 최대공배수 구하기

	if (n == 0)
		return m;
	else
		return gcd(n, m % n);
}





int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a, b; // 최소공배수와 최대공약수를 구할 수들
	cin >> a >> b;

	int g = gcd(a, b); // 최대공약수
	
	

	int m = a * b / g;   //최소공배수 = a * b / 최대공약수
	cout << g  << '\n'; //
	cout << m << '\n';
}
