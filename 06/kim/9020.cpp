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
	int a, b; // �Ҽ��� ���� �� �Ҽ���
	int c; //���̽��� ����
	cin >> c;
	int min;

	for (int i = 0; i < c; i++) {
		int q; // ������ �Ҽ� 
		cin >> q;

		for (int j = 1; j <=  q / 2; j++) {
			if (IsPrime(j)) {
				if (IsPrime(q - j)) { // q/2 ���� �� �ö󰡸鼭 ã�ٺ��� �ᱹ ���̰� �������� �� ���� ã�´�
					a = j;
					b = q - j;
				}
			}
		}
		cout << a << " " << b << "\n";
	}

	return 0;
}
