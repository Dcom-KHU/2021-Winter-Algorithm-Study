#include <iostream>
#include <algorithm>
using namespace std;

#define MAXSIZE 1000
int a[MAXSIZE];
int dp[MAXSIZE] = { 0, }; //a�� �� �ε������� ���� �� �ִ� ���� ū �����κм����� �� (0~index)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; //���� a�� ũ��
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
		dp[i] = a[i]; //�ڱ� �ڽŸ����� �̷���� ����(ũ�� 1)�� �ʱ�ȭ 
	}

	//top-down DP
	for (int i = 0;i < n;i++)
	{
		for (int j = 0; j < i;j++) //0 ~ i-1�� �ε������� Ž���ϸ鼭
		{
			if (a[i] > a[j]) //a[i]���� ���� ���� ���� ���
				dp[i] = max(dp[i], dp[j] + a[i]);
		}
	}

	sort(dp, dp + n);
	cout << dp[n-1];

	return 0;
}