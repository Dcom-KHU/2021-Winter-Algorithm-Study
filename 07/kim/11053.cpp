#include <iostream>
using namespace std;

#define SIZE 1000+1

int max(int a, int b) { //큰값을 리턴하는 함수
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

	int n; // 수열의 크기
	cin >> n;

	int arr[SIZE]; //수열을 담는 배열
	int dp[SIZE]; // index의 부분수열 크기를담는 배열

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i] = 1; // 수열의 최소 길이는 1이므로


	}
	int m_length = 1; // 수열의 최대길이를 저장

	for (int i = 0; i < n; i++) { // LSI 알고리즘 .... 시간복잡도 낮은걸로 다시 풀어볼게요 ㅠ
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
			if (dp[i] > m_length) { // 원래 저장된 값보다 크면 변경
				m_length = dp[i];
			}
		}
	}

	cout << m_length << '\n';


}