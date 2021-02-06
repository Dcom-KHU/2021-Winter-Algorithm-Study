#include <iostream>
#include <algorithm>
using namespace std;

#define MAXSIZE 1000
int arr[MAXSIZE];
int dp[MAXSIZE];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> arr[i];
		dp[i] = 1; //자기 자신만으로 이루어진 수열(크기 1)로 초기화 
	}

	//arr 배열에서 LIS 찾기
	int ret = 0;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0; j < i;j++)
		{
			if (arr[i] > arr[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		if (dp[i] > ret)
			ret = dp[i];
	}

	cout << ret;

	return 0;
}