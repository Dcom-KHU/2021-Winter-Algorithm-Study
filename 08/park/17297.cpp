#include <iostream>
#include <string>
using namespace std;


long long m;
long long dp[50];
string messi[3] = { "", "Messi", "Messi Gimossi" };  // 그만큼 신나시다는 거지~

void print(char c) {  // 공백 처리
	if (c == ' ')
		cout << "Messi Messi Gimossi" << endl;
	else
		cout << c << endl;
}

void func(int n) { 
	int flag;  // flag 번째 문자열에서 탐색
	for (int i = 1; i <= 42; i++) {
		if (dp[i] >= n) {
			flag = i;
			break;
		}
	}

	if (flag <= 2) {  // 2개 이하면 처리 가능
		print(messi[flag][n - 1]);
		return;
	}

	int checkPoint = dp[flag - 1];
	int nn = n - checkPoint; // dp[n - 1] + ' ' + dp[n - 2] 구조, dp[n - 2] 에서 탐색 위함

	if (nn == 1) {  // 띄어쓰기 처리
		print(' ');
	}
	else {  // 나머지
		func(nn - 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> m;

	dp[1] = 5;
	dp[2] = 13;

	for (int i = 3; i <= 42; i++) {
		dp[i] = dp[i - 1] + 1 + dp[i - 2];
	}

	func(m);
	return 0;
}