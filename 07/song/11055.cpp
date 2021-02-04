#include <iostream>
#include <algorithm>
using namespace std;

#define MAXSIZE 1000
int a[MAXSIZE];
int dp[MAXSIZE] = { 0, }; //a의 각 인덱스에서 가질 수 있는 가장 큰 증가부분수열의 합 (0~index)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; //수열 a의 크기
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
		dp[i] = a[i]; //자기 자신만으로 이루어진 수열(크기 1)로 초기화 
	}

	//top-down DP
	for (int i = 0;i < n;i++)
	{
		for (int j = 0; j < i;j++) //0 ~ i-1의 인덱스까지 탐색하면서
		{
			if (a[i] > a[j]) //a[i]보다 작은 값이 나온 경우
				dp[i] = max(dp[i], dp[j] + a[i]);
		}
	}

	sort(dp, dp + n);
	cout << dp[n-1];

	return 0;
}