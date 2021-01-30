#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; //���� ī���� ����
	cin >> n;

	long long card[100001];
	//ī�� ���� �Է� �� ����
	for (int i = 0; i < n; i++)
		cin >> card[i];
	sort(card, card + n);

	//�ֺ� ã��
	int max = 1; //���� ���� �󵵼�
	long long ret = card[0]; //����� : ���� ���� ������ ī��
	int count = 1; //curr�� card[0]���� �����ϹǷ� 1���� ����

	if (n == 1)
		cout << card[0];
	else
	{
		for (int i = 1; i < n; i++)
		{
			if (card[i] == card[i - 1])
				count++;
			else
				count = 1;
			if (count > max)
			{
				max = count;
				ret = card[i];
			}
		}
		cout << ret;
	}
	return 0;
}