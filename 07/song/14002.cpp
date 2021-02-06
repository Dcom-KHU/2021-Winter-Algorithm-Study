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
		dp[i] = 1; //�ڱ� �ڽŸ����� �̷���� ����(ũ�� 1)�� �ʱ�ȭ 
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

		//LIS�� ���ŵǾ��� ���
		if (dp[i] > maxCnt)
			maxCnt = dp[i];
	}

	//maxCnt���� 0��° �ε������� Ž���ϸ鼭 1�� �پ��� ������� stack�� ����
	//ex.	arr	10	20	10	30	20	50
	//		dp	1	2	1	3	2	4
	//dp[i]�� 4->3->2->1 ���� => ����� : 50 30 20 10 (�� ��, �������� ����ؾ��ϹǷ� stack ���)
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