#include <iostream>
#include <algorithm>
using namespace std;

#define SIZE 100000+1

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n; // ������ ����
	int rope[SIZE];
	int max = 0; //���� �ִ밪
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> rope[i];
	}
	sort(rope, rope + n); //ũ�������� ����
	for (int i = 0; i < n; i++) {
		if (max < rope[i] * (n - i)) {
			max = rope[i] * (n - i); //���� ���԰� �������� ������ �ϳ��� ��
		}
	}
	cout << max;
}
