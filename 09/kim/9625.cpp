#include <iostream>

using namespace std;

#define SIZE 5000+2

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int k;//��ư�� ���� Ƚ��

	int a = 1; // a�� ����
	int b = 0; // b�� ����
	int temp_a, temp_b; // ������ a,b�� ������ ����
	cin >> k;

	for (int i = 0; i < k; i++) {
		temp_a = a;
		temp_b = b;
		b = temp_b + temp_a;
		a = temp_b;
	}
	cout << a << " " << b << endl;
}