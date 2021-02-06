#include <iostream>
using namespace std;

#define SIZE 1000+1

int max(int a, int b) { //ū���� �����ϴ� �Լ�
	if (a > b) {
		return a;
	}
	else
		return b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; // ������ ũ��
	cin >> n;

	int arr[SIZE]; //������ ��� �迭
	int dp[SIZE]; // index�� �κм��� ũ�⸦��� �迭

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i] = 1; // ������ �ּ� ���̴� 1�̹Ƿ�


	}
	int m_length = 1; // ������ �ִ���̸� ����

	for (int i = 0; i < n; i++) { // LSI �˰��� .... �ð����⵵ �����ɷ� �ٽ� Ǯ��Կ� ��
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
			if (dp[i] > m_length) { // ���� ����� ������ ũ�� ����
				m_length = dp[i];
			}
		}
	}

	cout << m_length << '\n';


}