#include<iostream>
using namespace std;

int gcd(int m, int n) { //��Ŭ���� ȣ������ �̿��� �ִ����� ���ϱ�

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
	int a, b; // �ּҰ������ �ִ������� ���� ����
	cin >> a >> b;

	int g = gcd(a, b); // �ִ�����
	
	

	int m = a * b / g;   //�ּҰ���� = a * b / �ִ�����
	cout << g  << '\n'; //
	cout << m << '\n';
}
