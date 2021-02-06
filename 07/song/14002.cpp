#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

#define MAXSIZE 1000+1
int arr[MAXSIZE];
int dp[MAXSIZE];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> arr[i];
		dp[i] = 1; //자기 자신만으로 이루어진 수열(크기 1)로 초기화 
	}

	//LIS
	int maxCnt = 0;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0; j < i;j++)
		{
			if (arr[i] > arr[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}

		//LIS가 갱신되었을 경우
		if (dp[i] > maxCnt)
			maxCnt = dp[i];
	}

	//maxCnt부터 0번째 인덱스까지 탐색하면서 1씩 줄어드는 순서대로 stack에 저장
	//ex.	arr	10	20	10	30	20	50
	//		dp	1	2	1	3	2	4
	//dp[i]가 4->3->2->1 순서 => 결과값 : 50 30 20 10 (이 때, 오름차순 출력해야하므로 stack 사용)
	stack<int> st;
	int tmp = maxCnt;
	for (int i = n - 1;i >= 0;i--)
	{
		if ((dp[i] == tmp) && (tmp >= 1))
		{
			st.push(i);
			tmp--;
		}
	}

	cout << maxCnt << "\n";
	while (!st.empty())
	{
		cout << arr[st.top()] << " ";
		st.pop();
	}
	
	return 0;
}