#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int num; // N��

	cin >> num; // N�� �Է�

	for (int i = 1; i < num+1; i++) {
		cout << i << "\n"; // N������ ���� ���	 ��endl �ϸ� �ð��ʰ�
	}

	return 0;
}