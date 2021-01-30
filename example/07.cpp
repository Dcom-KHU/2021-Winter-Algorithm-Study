#include <iostream>
#include <vector>
using namespace std;


int main() {
	int length, max = 0;
	cin >> length;

	vector<int> vec(length + 1);
	vector<int> dp(length + 1);

	for (int i = 1; i <= length; i++) {
		cin >> vec[i];
		dp[i] = 0;
	}

	for (int i = 1; i <= length; i++) { // 체크하려는 수
		int min = 0;

		// 체크하려는 수보다 낮은 수 중 가장 긴 수열을 갖고 있는 것을 찾는다.
		for (int j = 1; j < i; j++) {
			if (vec[i] > vec[j]) {  // j 보다 i 가 크면
				if (min < dp[j]) {
					min = dp[j];  // 가장 긴수열 갱신
				}
			}
		}
		dp[i] = min + 1;  // min 갱신
		if (dp[i] > max)
			max = dp[i];  // max 갱신
	}

	cout << max << endl;
}