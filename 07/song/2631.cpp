#include <iostream>
#include <algorithm>
using namespace std;

#define MAXSIZE 200+2 //sort�� index ���� ���� ���� +2
int arr[MAXSIZE]; //���̵��� ����
int dp[MAXSIZE];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n; //���̵��� ��
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> arr[i];
		dp[i] = 1; //�ڱ� �ڽŸ����� �̷���� ����(ũ�� 1)�� �ʱ�ȭ 
	}

	//arr �迭���� LIS ã��
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1; j < i;j++)
		{
			if (arr[i] > arr[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	sort(&dp[1], &dp[n+1]);
	int LISCnt = dp[n]; //arr �迭���� ���� LIS�� ũ��

	//�������� �� ���̵��� ���� ���ĵǾ� �ִ� ���� �� ���̵��� �迭(LIS)�� �׷��� ���� ���̵��� ����ִ� �Ͱ� ����
	//���� �Ű����� ������ �ּ� �� = ��ü �ο� �� - LIS
	cout << n - LISCnt;

	return 0;
}