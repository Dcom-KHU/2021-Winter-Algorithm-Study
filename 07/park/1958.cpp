#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int dp[101][101][101] = { 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string f_str;
	string s_str;
	string t_str;

	cin >> f_str;
	cin >> s_str;
	cin >> t_str;

	int f_n = f_str.size();
	int s_n = s_str.size();
	int t_n = t_str.size();

	for (int i = 1; i <= f_n; i++)
	{
		for (int j = 1; j <= s_n; j++)
		{
			for (int k = 1; k <= t_n; k++)
			{
				if (f_str[i - 1] == s_str[j - 1] && s_str[j - 1] == t_str[k - 1]) {  // 세 문자가 일치하면
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;  // 한글자씩 전진
				}
				else {  // 아니라면
					dp[i][j][k] = max(max(dp[i - 1][j][k], dp[i][j - 1][k]), dp[i][j][k - 1]);  // 그 전 가장 긴 LCS 중 가장 긴 값 선택
				}
			}
		}
	}
	cout << dp[f_n][s_n][t_n] << endl;

	return 0;
}