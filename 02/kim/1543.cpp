#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	string a, b; // a : üũ�� ���ڿ� b : �˻��� �ܾ�
	int index = 0; // ���� a���� ã����ġ
	int count = 0; // a���� b�� ã���� ++

	getline(cin, a);
	getline(cin, b); // a�� b�� �Է¹���

	while (true) {
		index = a.find(b, index);
		if (index > a.length()) { // ã����ġ�� ���ڿ� ���� ���� ũ���ǹ̰� ����
			break;
		}
		count++; // break�� ���Ͼ� �����Ƿ� ���������� ã��
		index += b.length(); // ã�� ���ڿ� ���� ��ŭ ������
	}
	cout << count << '\n';

	return 0;
}