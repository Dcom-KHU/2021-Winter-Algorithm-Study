#include <iostream>
#include <algorithm>
using namespace std;

#define MAXSIZE 200+2 //sort시 index 오류 방지 위해 +2
int arr[MAXSIZE]; //아이들의 순서
int dp[MAXSIZE];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n; //아이들의 수
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> arr[i];
		dp[i] = 1; //자기 자신만으로 이루어진 수열(크기 1)로 초기화 
	}

	//arr 배열에서 LIS 찾기
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1; j < i;j++)
		{
			if (arr[i] > arr[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	sort(&dp[1], &dp[n+1]);
	int LISCnt = dp[n]; //arr 배열에서 얻은 LIS의 크기

	//움직여야 할 아이들의 수는 정렬되어 있는 가장 긴 아이들의 배열(LIS)에 그렇지 못한 아이들을 집어넣는 것과 같음
	//따라서 옮겨지는 아이의 최소 수 = 전체 인원 수 - LIS
	cout << n - LISCnt;

	return 0;
}